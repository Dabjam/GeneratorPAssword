#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QFile>
#include <QLatin1String>
#include <QDebug>
#include <QInputDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QApplication>
#include <QCoreApplication>
#include <QCheckBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    settings("MyCompany", "PasswordGenerator") {
    ui->setupUi(this);

    // Инициализация объектов
    generator = std::make_unique<PasswordGenerator>();
    manager = std::make_unique<PasswordManager>();
    clipboard = std::make_unique<ClipboardHandler>();

    if (!generator || !manager || !clipboard) {
        qWarning() << "Не удалось инициализировать один или несколько объектов";
        QCoreApplication::exit(0);
        return;
    }

    // Запрос мастер-пароля
    if (!requestMasterPassword()) {
        qDebug() << "requestMasterPassword returned false, closing application";
        delete ui;
        ui = nullptr;
        this->deleteLater();
        QCoreApplication::exit(0);
        return;
    }

    setWindowTitle(tr("Генератор паролей"));
    resize(500, 700);

    // Настройка QTableWidget
    ui->passwordTable->setColumnCount(2);
    ui->passwordTable->setHorizontalHeaderLabels({tr("Логин"), tr("Пароль")});
    ui->passwordTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->passwordTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->passwordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Загрузка сохранённой темы или установка тёмной по умолчанию
    QString savedTheme = settings.value("theme", "dark").toString();
    currentTheme = (savedTheme == "light") ? Theme::Light : Theme::Dark;

    // Программное добавление кнопки переключения тем
    QPushButton *themeToggleBtn = new QPushButton(ui->stackedWidget->widget(MainMenu));
    themeToggleBtn->setObjectName("themeToggleBtn");
    themeToggleBtn->setGeometry(410, 20, 70, 40);
    themeToggleBtn->setText(currentTheme == Theme::Light ? tr("Ночь") : tr("День"));

    // Применение начальной темы
    applyTheme();

    // Проверка objectName для заголовков
    QList<QLabel*> labels = ui->stackedWidget->findChildren<QLabel*>();
    for (QLabel* label : labels) {
        if (label->objectName() == "headerLabel") {
            qDebug() << "Found headerLabel with text:" << label->text() << "on page" << ui->stackedWidget->currentIndex();
        }
    }

    // Подключение сигналов и слотов
    connect(ui->generateBtn, &QPushButton::clicked, this, &MainWindow::showPasswordGeneratorMenu);
    connect(ui->saveBtn, &QPushButton::clicked, this, &MainWindow::showSavePasswordMenu);
    connect(ui->viewBtn, &QPushButton::clicked, this, &MainWindow::showSavedPasswordsMenu);
    connect(ui->customGenBtn, &QPushButton::clicked, this, &MainWindow::showCustomPasswordGenerator);
    connect(ui->complexityGenBtn, &QPushButton::clicked, this, &MainWindow::showComplexityPasswordGenerator);
    connect(ui->backBtnGeneratorMenu, &QPushButton::clicked, this, [this]() { goBack("backBtnGeneratorMenu"); });
    qDebug() << "Connected backBtnGeneratorMenu to goBack";
    connect(ui->generateCustomBtn, &QPushButton::clicked, this, &MainWindow::generateCustomPassword);
    connect(ui->backBtnCustomGenerator, &QPushButton::clicked, this, [this]() { goBack("backBtnCustomGenerator"); });
    connect(ui->generateComplexityBtn, &QPushButton::clicked, this, &MainWindow::generatePasswordByComplexity);
    connect(ui->backBtnComplexityGenerator, &QPushButton::clicked, this, [this]() { goBack("backBtnComplexityGenerator"); });
    connect(ui->savePasswordBtn, &QPushButton::clicked, this, &MainWindow::savePassword);
    connect(ui->backBtnSavePassword, &QPushButton::clicked, this, [this]() { goBack("backBtnSavePassword"); });
    connect(ui->viewPasswordBtn, &QPushButton::clicked, this, &MainWindow::viewPassword);
    connect(ui->removePasswordBtn, &QPushButton::clicked, this, &MainWindow::removePassword);
    connect(ui->backBtnViewPasswords, &QPushButton::clicked, this, [this]() { goBack("backBtnViewPasswords"); });
    connect(ui->showPasswordCheck, &QCheckBox::checkStateChanged, this, &MainWindow::togglePasswordVisibility);
    connect(ui->showKeySaveCheck, &QCheckBox::checkStateChanged, this, &MainWindow::toggleKeySaveVisibility);
    connect(ui->showKeyViewCheck, &QCheckBox::checkStateChanged, this, &MainWindow::toggleKeyViewVisibility);
    connect(themeToggleBtn, &QPushButton::clicked, this, &MainWindow::toggleTheme);
    connect(ui->searchInput, &QLineEdit::textChanged, this, &MainWindow::filterPasswords);

    showMainMenu();
}

MainWindow::~MainWindow() {
    if (manager && masterPasswordSet) {
        manager->savePasswords();
    }
    delete ui;
}

bool MainWindow::requestMasterPassword() {
    bool ok;
    QString masterPassword;
    bool firstAttempt = true;

    if (!QFile("passwords.dat").exists()) {
        QString hint = QInputDialog::getText(this, tr("Подсказка для мастер-пароля"),
                                             tr("Задайте подсказку для вашего мастер-пароля (оставьте пустым, если не нужна):"),
                                             QLineEdit::Normal, "", &ok);
        if (!ok) {
            qDebug() << "User pressed Cancel in hint dialog, aborting";
            return false;
        }
        manager->saveHint(hint);

        // Запрос нового мастер-пароля
        masterPassword = showNewMasterPasswordDialog(ok);
        if (!ok || masterPassword.isEmpty()) {
            QMessageBox::critical(this, tr("Ошибка"), tr("Мастер-пароль обязателен для работы приложения!"));
            return false;
        }
        if (!manager->setMasterPassword(masterPassword)) {
            QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось установить новый мастер-пароль!"));
            return false;
        }
        masterPasswordSet = true;
        qDebug() << "New master password set successfully";
    }

    while (true) {
        masterPassword = showMasterPasswordDialog(firstAttempt, ok);

        if (!ok) {
            qDebug() << "User pressed Cancel in master password dialog, aborting";
            return false;
        }

        if (masterPassword.isEmpty()) {
            QMessageBox::critical(this, tr("Ошибка"), tr("Мастер-пароль обязателен для работы приложения!"));
            firstAttempt = false;
            continue;
        }

        if (!manager->setMasterPassword(masterPassword)) {
            QMessageBox warning(QMessageBox::Warning, tr("Ошибка"),
                                tr("Не удалось установить мастер-пароль! Возможно, введён неверный мастер-пароль."),
                                QMessageBox::NoButton, this);
            QPushButton *retryButton = warning.addButton(tr("Попробовать снова"), QMessageBox::ActionRole);
            QPushButton *resetButton = warning.addButton(tr("Создать новый файл"), QMessageBox::ActionRole);
            warning.addButton(tr("Отмена"), QMessageBox::RejectRole);
            warning.exec();

            if (warning.clickedButton() == retryButton) {
                firstAttempt = false;
                masterPasswordSet = false;
                qDebug() << "User chose to retry entering master password";
                continue;
            } else if (warning.clickedButton() == resetButton) {
                resetPasswordFile();
                QString hint = QInputDialog::getText(this, tr("Подсказка для мастер-пароля"),
                                                     tr("Задайте подсказку для нового мастер-пароля (оставьте пустым, если не нужна):"),
                                                     QLineEdit::Normal, "", &ok);
                if (!ok) {
                    qDebug() << "User pressed Cancel in new hint dialog, aborting";
                    return false;
                }
                manager->saveHint(hint);
                masterPassword = showNewMasterPasswordDialog(ok);
                if (!ok || masterPassword.isEmpty()) {
                    QMessageBox::critical(this, tr("Ошибка"), tr("Мастер-пароль обязателен для работы приложения!"));
                    return false;
                }
                if (!manager->setMasterPassword(masterPassword)) {
                    QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось установить новый мастер-пароль!"));
                    return false;
                }
                masterPasswordSet = true;
                QMessageBox::information(this, tr("Успех"), tr("Файл паролей сброшен. Теперь используется новый мастер-пароль."));
                qDebug() << "Reset password file and set new master password";
                break;
            } else {
                qDebug() << "User pressed Cancel in warning dialog, aborting";
                masterPasswordSet = false;
                return false;
            }
        } else {
            masterPasswordSet = true;
            qDebug() << "Master password set successfully";
            break;
        }
    }

    return true;
}

QString MainWindow::showMasterPasswordDialog(bool firstAttempt, bool &ok) {
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Мастер-пароль"));

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *label = new QLabel(firstAttempt ? tr("Введите мастер-пароль для доступа к паролям:") :
                                   tr("Мастер-пароль неверный. Введите снова:"));
    layout->addWidget(label);

    QLineEdit *passwordInput = new QLineEdit();
    passwordInput->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordInput);

    QCheckBox *showPasswordCheck = new QCheckBox(tr("Показать пароль"));
    layout->addWidget(showPasswordCheck);
    connect(showPasswordCheck, &QCheckBox::checkStateChanged, this, [passwordInput](int state) {
        passwordInput->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
    });

    QPushButton *hintButton = new QPushButton(tr("Показать подсказку"));
    layout->addWidget(hintButton);
    connect(hintButton, &QPushButton::clicked, this, &MainWindow::showHint);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("ОК"));
    buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Отмена"));
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    int result = dialog.exec();
    ok = (result == QDialog::Accepted);
    qDebug() << "showMasterPasswordDialog result:" << result << "ok:" << ok;

    return passwordInput->text();
}

QString MainWindow::showNewMasterPasswordDialog(bool &ok) {
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Новый мастер-пароль"));

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *label = new QLabel(tr("Введите новый мастер-пароль:"));
    layout->addWidget(label);

    QLineEdit *passwordInput = new QLineEdit();
    passwordInput->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordInput);

    QCheckBox *showPasswordCheck = new QCheckBox(tr("Показать пароль"));
    layout->addWidget(showPasswordCheck);
    connect(showPasswordCheck, &QCheckBox::checkStateChanged, this, [passwordInput](int state) {
        passwordInput->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
    });

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("ОК"));
    buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Отмена"));
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    int result = dialog.exec();
    ok = (result == QDialog::Accepted);
    qDebug() << "showNewMasterPasswordDialog result:" << result << "ok:" << ok;

    return passwordInput->text();
}

void MainWindow::showHint() {
    QString hint = manager->loadHint();
    if (hint.isEmpty()) {
        QMessageBox::information(this, tr("Подсказка"), tr("Подсказка не задана."));
    } else {
        QMessageBox::information(this, tr("Подсказка"), tr("Подсказка для мастер-пароля:\n%1").arg(hint));
    }
}

void MainWindow::resetPasswordFile() {
    QFile file("passwords.dat");
    if (file.exists()) {
        if (!file.remove()) {
            qWarning() << "Failed to remove passwords.dat";
            QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось удалить старый файл паролей!"));
            return;
        }
        qDebug() << "Removed passwords.dat";
    }

    QFile hashFile("masterpassword.hash");
    if (hashFile.exists()) {
        if (!hashFile.remove()) {
            qWarning() << "Failed to remove masterpassword.hash";
            QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось удалить файл хеша мастер-пароля!"));
            return;
        }
        qDebug() << "Removed masterpassword.hash";
    }

    // Очищаем список паролей в менеджере
    manager->clearPasswords();
    qDebug() << "Cleared password list in PasswordManager";
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (manager && masterPasswordSet) {
        manager->savePasswords();
    }
    event->accept();
}

void MainWindow::applyTheme() {
    QFile styleFile(currentTheme == Theme::Light ? ":/light.qss" : ":/dark.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        setStyleSheet(styleSheet);
        styleFile.close();
    }
    QPushButton *themeToggleBtn = findChild<QPushButton*>("themeToggleBtn");
    if (themeToggleBtn) {
        themeToggleBtn->setText(currentTheme == Theme::Light ? tr("Ночь") : tr("День"));
    }
}

void MainWindow::toggleTheme() {
    currentTheme = (currentTheme == Theme::Light) ? Theme::Dark : Theme::Light;
    applyTheme();
    settings.setValue("theme", currentTheme == Theme::Light ? "light" : "dark");
}

void MainWindow::showMainMenu() {
    ui->stackedWidget->setCurrentIndex(MainMenu);
    previousPage = MainMenu;
    qDebug() << "showMainMenu: previousPage set to" << previousPage;
}

void MainWindow::showPasswordGeneratorMenu() {
    ui->stackedWidget->setCurrentIndex(PasswordGeneratorMenu);
    previousPage = MainMenu;
    qDebug() << "showPasswordGeneratorMenu: previousPage set to" << previousPage;
}

void MainWindow::showCustomPasswordGenerator() {
    ui->stackedWidget->setCurrentIndex(CustomPasswordGenerator);
    previousPage = PasswordGeneratorMenu;
    qDebug() << "showCustomPasswordGenerator: previousPage set to" << previousPage;
}

void MainWindow::showComplexityPasswordGenerator() {
    ui->stackedWidget->setCurrentIndex(ComplexityPasswordGenerator);
    previousPage = PasswordGeneratorMenu;
    qDebug() << "showComplexityPasswordGenerator: previousPage set to" << previousPage;
}

void MainWindow::showSavePasswordMenu() {
    ui->stackedWidget->setCurrentIndex(SavePasswordMenu);
    previousPage = MainMenu;
    qDebug() << "showSavePasswordMenu: previousPage set to" << previousPage;
}

void MainWindow::showSavedPasswordsMenu() {
    ui->stackedWidget->setCurrentIndex(SavedPasswordsMenu);
    previousPage = MainMenu;
    qDebug() << "showSavedPasswordsMenu: previousPage set to" << previousPage;
    filterPasswords();
}

void MainWindow::generateAndHandlePassword(const QString &password) {
    if (password.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сгенерировать пароль"));
        return;
    }
    QString strength = evaluatePasswordStrength(password);
    clipboard->copyToClipboard(password);
    QMessageBox::information(this, tr("Успех"), tr("Сгенерированный пароль: %1\nСложность: %2\nСкопирован в буфер обмена!").arg(password, strength));
    showMainMenu();
    QString temp;
    temp.swap(const_cast<QString&>(password));
}

void MainWindow::generateCustomPassword() {
    bool ok;
    int length = ui->lengthInput->text().toInt(&ok);
    if (!ok || length <= 0 || length > 50) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Неверная длина пароля (от 4 до 50 символов)"));
        return;
    }

    if (!ui->lowerCaseCheck->isChecked() && !ui->upperCaseCheck->isChecked() &&
        !ui->digitsCheck->isChecked() && !ui->specialCheck->isChecked()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Выберите хотя бы один тип символов"));
        return;
    }

    QString password = generator->generatePassword(
        length,
        ui->lowerCaseCheck->isChecked(),
        ui->upperCaseCheck->isChecked(),
        ui->digitsCheck->isChecked(),
        ui->specialCheck->isChecked()
        );

    generateAndHandlePassword(password);

    // Сбрасываем параметры после генерации
    ui->lengthInput->clear();
    ui->lowerCaseCheck->setChecked(false);
    ui->upperCaseCheck->setChecked(false);
    ui->digitsCheck->setChecked(false);
    ui->specialCheck->setChecked(false);
    qDebug() << "Custom password parameters reset";
}

void MainWindow::generatePasswordByComplexity() {
    QString complexity = ui->complexityCombo->currentText();
    int length = (complexity == tr("Низкая")) ? 8 : (complexity == tr("Средняя")) ? 12 : 16;
    bool special = complexity == tr("Высокая");

    QString password = generator->generatePassword(
        length,
        true,
        complexity != tr("Низкая"),
        true,
        special
        );

    generateAndHandlePassword(password);
}

void MainWindow::savePassword() {
    QString login = ui->loginInput->text();
    QString password = ui->passwordInput->text();
    QString key = ui->keyInputSave->text();

    if (login.isEmpty() || password.isEmpty() || key.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Все поля должны быть заполнены"));
        return;
    }

    if (login.length() > 50 || key.length() > 50) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Слишком длинный логин или ключ (максимум 50 символов)"));
        return;
    }

    manager->savePassword(login, password, key);
    QMessageBox::information(this, tr("Успех"), tr("Пароль успешно сохранён!"));
    ui->loginInput->clear();
    ui->passwordInput->clear();
    ui->keyInputSave->clear();
    ui->showPasswordCheck->setChecked(false);
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    ui->showKeySaveCheck->setChecked(false);
    ui->keyInputSave->setEchoMode(QLineEdit::Password);
    goBack("savePassword");
}

void MainWindow::viewPassword() {
    int currentRow = ui->passwordTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Выберите пароль для просмотра"));
        return;
    }

    QString login = ui->passwordTable->item(currentRow, 0)->text();
    QString key = ui->keyInputView->text();

    QString password = manager->getPassword(login, key);
    if (password.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Неверный ключ"));
        return;
    }

    clipboard->copyToClipboard(password);
    QMessageBox::information(this, tr("Успех"), tr("Пароль: %1\nСкопирован в буфер обмена!").arg(password));
    ui->keyInputView->clear();
    ui->showKeyViewCheck->setChecked(false);
    ui->keyInputView->setEchoMode(QLineEdit::Password);
    QString temp;
    temp.swap(const_cast<QString&>(password));
}

void MainWindow::removePassword() {
    int currentRow = ui->passwordTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Выберите пароль для удаления"));
        return;
    }

    QString login = ui->passwordTable->item(currentRow, 0)->text();
    QString key = ui->keyInputView->text();

    if (manager->removePassword(login, key)) {
        QMessageBox::information(this, tr("Успех"), tr("Пароль успешно удалён!"));
        filterPasswords();
        ui->keyInputView->clear();
        ui->showKeyViewCheck->setChecked(false);
        ui->keyInputView->setEchoMode(QLineEdit::Password);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось удалить пароль. Проверьте ключ."));
    }
}

void MainWindow::togglePasswordVisibility(Qt::CheckState state) {
    ui->passwordInput->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

void MainWindow::toggleKeySaveVisibility(Qt::CheckState state) {
    ui->keyInputSave->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

void MainWindow::toggleKeyViewVisibility(Qt::CheckState state) {
    ui->keyInputView->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

void MainWindow::goBack(const QString &buttonName) {
    qDebug() << "goBack called by" << buttonName << ", previousPage:" << previousPage
             << ", currentPage:" << ui->stackedWidget->currentIndex();

    int currentPage = ui->stackedWidget->currentIndex();
    int targetPage = previousPage;

    if (currentPage == CustomPasswordGenerator || currentPage == ComplexityPasswordGenerator) {
        targetPage = PasswordGeneratorMenu;
        previousPage = MainMenu;
    } else if (currentPage == PasswordGeneratorMenu) {
        targetPage = MainMenu;
        previousPage = MainMenu;
    } else if (currentPage == SavePasswordMenu || currentPage == SavedPasswordsMenu) {
        targetPage = MainMenu;
        previousPage = MainMenu;
    }

    if (targetPage >= 0 && targetPage < ui->stackedWidget->count()) {
        ui->stackedWidget->setCurrentIndex(targetPage);
        qDebug() << "Switched to page:" << targetPage << ", new previousPage:" << previousPage;
    } else {
        qWarning() << "Invalid previousPage value:" << targetPage << ", reverting to MainMenu";
        ui->stackedWidget->setCurrentIndex(MainMenu);
        previousPage = MainMenu;
        qDebug() << "Switched to MainMenu, new previousPage:" << previousPage;
    }
}

QString MainWindow::evaluatePasswordStrength(const QString &password) {
    int score = 0;
    if (password.length() >= 12) score += 2;
    if (password.contains(QRegularExpression("[a-z]"))) score++;
    if (password.contains(QRegularExpression("[A-Z]"))) score++;
    if (password.contains(QRegularExpression("[0-9]"))) score++;
    if (password.contains(QRegularExpression("[!@#$%^&*]"))) score++;
    if (score >= 5) return tr("Сильный");
    if (score >= 3) return tr("Средний");
    return tr("Слабый");
}

void MainWindow::filterPasswords() {
    ui->passwordTable->setRowCount(0);
    auto passwords = manager->getPasswordList();
    QString searchText = ui->searchInput->text().toLower();
    bool found = false;

    if (searchText.isEmpty()) {
        ui->passwordTable->setRowCount(passwords.size());
        for (int i = 0; i < passwords.size(); ++i) {
            const auto &entry = passwords[i];
            ui->passwordTable->setItem(i, 0, new QTableWidgetItem(entry.login));
            ui->passwordTable->setItem(i, 1, new QTableWidgetItem("********"));
            found = true;
        }
    } else {
        int row = 0;
        for (const auto &entry : passwords) {
            if (entry.login.toLower().contains(searchText)) {
                ui->passwordTable->insertRow(row);
                ui->passwordTable->setItem(row, 0, new QTableWidgetItem(entry.login));
                ui->passwordTable->setItem(row, 1, new QTableWidgetItem("********"));
                ++row;
                found = true;
            }
        }
    }

    if (!found && !searchText.isEmpty()) {
        QMessageBox::information(this, tr("Информация"), tr("Ничего не найдено"));
        ui->passwordTable->setRowCount(passwords.size());
        for (int i = 0; i < passwords.size(); ++i) {
            const auto &entry = passwords[i];
            ui->passwordTable->setItem(i, 0, new QTableWidgetItem(entry.login));
            ui->passwordTable->setItem(i, 1, new QTableWidgetItem("********"));
        }
    }
}
