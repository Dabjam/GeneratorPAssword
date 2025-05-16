/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *mainMenuPage;
    QVBoxLayout *mainMenuLayout;
    QLabel *mainMenuLabel;
    QPushButton *generateBtn;
    QPushButton *saveBtn;
    QPushButton *viewBtn;
    QWidget *generatorMenuPage;
    QVBoxLayout *generatorMenuLayout;
    QLabel *generatorMenuLabel;
    QPushButton *customGenBtn;
    QPushButton *complexityGenBtn;
    QPushButton *backBtnGeneratorMenu;
    QWidget *customGeneratorPage;
    QVBoxLayout *customGeneratorLayout;
    QLabel *customGeneratorLabel;
    QLineEdit *lengthInput;
    QCheckBox *lowerCaseCheck;
    QCheckBox *upperCaseCheck;
    QCheckBox *digitsCheck;
    QCheckBox *specialCheck;
    QPushButton *generateCustomBtn;
    QPushButton *backBtnCustomGenerator;
    QWidget *complexityGeneratorPage;
    QVBoxLayout *complexityGeneratorLayout;
    QLabel *complexityGeneratorLabel;
    QComboBox *complexityCombo;
    QPushButton *generateComplexityBtn;
    QPushButton *backBtnComplexityGenerator;
    QWidget *savePasswordPage;
    QVBoxLayout *savePasswordLayout;
    QLabel *savePasswordLabel;
    QLineEdit *loginInput;
    QLineEdit *passwordInput;
    QCheckBox *showPasswordCheck;
    QLineEdit *keyInputSave;
    QCheckBox *showKeySaveCheck;
    QPushButton *savePasswordBtn;
    QPushButton *backBtnSavePassword;
    QWidget *viewPasswordsPage;
    QVBoxLayout *viewPasswordsLayout;
    QLabel *viewPasswordsLabel;
    QListWidget *passwordList;
    QLineEdit *keyInputView;
    QCheckBox *showKeyViewCheck;
    QPushButton *viewPasswordBtn;
    QPushButton *removePasswordBtn;
    QPushButton *backBtnViewPasswords;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        mainMenuPage = new QWidget();
        mainMenuPage->setObjectName("mainMenuPage");
        mainMenuLayout = new QVBoxLayout(mainMenuPage);
        mainMenuLayout->setObjectName("mainMenuLayout");
        mainMenuLabel = new QLabel(mainMenuPage);
        mainMenuLabel->setObjectName("mainMenuLabel");
        mainMenuLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainMenuLayout->addWidget(mainMenuLabel);

        generateBtn = new QPushButton(mainMenuPage);
        generateBtn->setObjectName("generateBtn");

        mainMenuLayout->addWidget(generateBtn);

        saveBtn = new QPushButton(mainMenuPage);
        saveBtn->setObjectName("saveBtn");

        mainMenuLayout->addWidget(saveBtn);

        viewBtn = new QPushButton(mainMenuPage);
        viewBtn->setObjectName("viewBtn");

        mainMenuLayout->addWidget(viewBtn);

        stackedWidget->addWidget(mainMenuPage);
        generatorMenuPage = new QWidget();
        generatorMenuPage->setObjectName("generatorMenuPage");
        generatorMenuLayout = new QVBoxLayout(generatorMenuPage);
        generatorMenuLayout->setObjectName("generatorMenuLayout");
        generatorMenuLabel = new QLabel(generatorMenuPage);
        generatorMenuLabel->setObjectName("generatorMenuLabel");
        generatorMenuLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        generatorMenuLayout->addWidget(generatorMenuLabel);

        customGenBtn = new QPushButton(generatorMenuPage);
        customGenBtn->setObjectName("customGenBtn");

        generatorMenuLayout->addWidget(customGenBtn);

        complexityGenBtn = new QPushButton(generatorMenuPage);
        complexityGenBtn->setObjectName("complexityGenBtn");

        generatorMenuLayout->addWidget(complexityGenBtn);

        backBtnGeneratorMenu = new QPushButton(generatorMenuPage);
        backBtnGeneratorMenu->setObjectName("backBtnGeneratorMenu");

        generatorMenuLayout->addWidget(backBtnGeneratorMenu);

        stackedWidget->addWidget(generatorMenuPage);
        customGeneratorPage = new QWidget();
        customGeneratorPage->setObjectName("customGeneratorPage");
        customGeneratorLayout = new QVBoxLayout(customGeneratorPage);
        customGeneratorLayout->setObjectName("customGeneratorLayout");
        customGeneratorLabel = new QLabel(customGeneratorPage);
        customGeneratorLabel->setObjectName("customGeneratorLabel");
        customGeneratorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        customGeneratorLayout->addWidget(customGeneratorLabel);

        lengthInput = new QLineEdit(customGeneratorPage);
        lengthInput->setObjectName("lengthInput");

        customGeneratorLayout->addWidget(lengthInput);

        lowerCaseCheck = new QCheckBox(customGeneratorPage);
        lowerCaseCheck->setObjectName("lowerCaseCheck");

        customGeneratorLayout->addWidget(lowerCaseCheck);

        upperCaseCheck = new QCheckBox(customGeneratorPage);
        upperCaseCheck->setObjectName("upperCaseCheck");

        customGeneratorLayout->addWidget(upperCaseCheck);

        digitsCheck = new QCheckBox(customGeneratorPage);
        digitsCheck->setObjectName("digitsCheck");

        customGeneratorLayout->addWidget(digitsCheck);

        specialCheck = new QCheckBox(customGeneratorPage);
        specialCheck->setObjectName("specialCheck");

        customGeneratorLayout->addWidget(specialCheck);

        generateCustomBtn = new QPushButton(customGeneratorPage);
        generateCustomBtn->setObjectName("generateCustomBtn");

        customGeneratorLayout->addWidget(generateCustomBtn);

        backBtnCustomGenerator = new QPushButton(customGeneratorPage);
        backBtnCustomGenerator->setObjectName("backBtnCustomGenerator");

        customGeneratorLayout->addWidget(backBtnCustomGenerator);

        stackedWidget->addWidget(customGeneratorPage);
        complexityGeneratorPage = new QWidget();
        complexityGeneratorPage->setObjectName("complexityGeneratorPage");
        complexityGeneratorLayout = new QVBoxLayout(complexityGeneratorPage);
        complexityGeneratorLayout->setObjectName("complexityGeneratorLayout");
        complexityGeneratorLabel = new QLabel(complexityGeneratorPage);
        complexityGeneratorLabel->setObjectName("complexityGeneratorLabel");
        complexityGeneratorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        complexityGeneratorLayout->addWidget(complexityGeneratorLabel);

        complexityCombo = new QComboBox(complexityGeneratorPage);
        complexityCombo->addItem(QString());
        complexityCombo->addItem(QString());
        complexityCombo->addItem(QString());
        complexityCombo->setObjectName("complexityCombo");

        complexityGeneratorLayout->addWidget(complexityCombo);

        generateComplexityBtn = new QPushButton(complexityGeneratorPage);
        generateComplexityBtn->setObjectName("generateComplexityBtn");

        complexityGeneratorLayout->addWidget(generateComplexityBtn);

        backBtnComplexityGenerator = new QPushButton(complexityGeneratorPage);
        backBtnComplexityGenerator->setObjectName("backBtnComplexityGenerator");

        complexityGeneratorLayout->addWidget(backBtnComplexityGenerator);

        stackedWidget->addWidget(complexityGeneratorPage);
        savePasswordPage = new QWidget();
        savePasswordPage->setObjectName("savePasswordPage");
        savePasswordLayout = new QVBoxLayout(savePasswordPage);
        savePasswordLayout->setObjectName("savePasswordLayout");
        savePasswordLabel = new QLabel(savePasswordPage);
        savePasswordLabel->setObjectName("savePasswordLabel");
        savePasswordLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        savePasswordLayout->addWidget(savePasswordLabel);

        loginInput = new QLineEdit(savePasswordPage);
        loginInput->setObjectName("loginInput");

        savePasswordLayout->addWidget(loginInput);

        passwordInput = new QLineEdit(savePasswordPage);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        savePasswordLayout->addWidget(passwordInput);

        showPasswordCheck = new QCheckBox(savePasswordPage);
        showPasswordCheck->setObjectName("showPasswordCheck");

        savePasswordLayout->addWidget(showPasswordCheck);

        keyInputSave = new QLineEdit(savePasswordPage);
        keyInputSave->setObjectName("keyInputSave");
        keyInputSave->setEchoMode(QLineEdit::EchoMode::Password);

        savePasswordLayout->addWidget(keyInputSave);

        showKeySaveCheck = new QCheckBox(savePasswordPage);
        showKeySaveCheck->setObjectName("showKeySaveCheck");

        savePasswordLayout->addWidget(showKeySaveCheck);

        savePasswordBtn = new QPushButton(savePasswordPage);
        savePasswordBtn->setObjectName("savePasswordBtn");

        savePasswordLayout->addWidget(savePasswordBtn);

        backBtnSavePassword = new QPushButton(savePasswordPage);
        backBtnSavePassword->setObjectName("backBtnSavePassword");

        savePasswordLayout->addWidget(backBtnSavePassword);

        stackedWidget->addWidget(savePasswordPage);
        viewPasswordsPage = new QWidget();
        viewPasswordsPage->setObjectName("viewPasswordsPage");
        viewPasswordsLayout = new QVBoxLayout(viewPasswordsPage);
        viewPasswordsLayout->setObjectName("viewPasswordsLayout");
        viewPasswordsLabel = new QLabel(viewPasswordsPage);
        viewPasswordsLabel->setObjectName("viewPasswordsLabel");
        viewPasswordsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        viewPasswordsLayout->addWidget(viewPasswordsLabel);

        passwordList = new QListWidget(viewPasswordsPage);
        passwordList->setObjectName("passwordList");

        viewPasswordsLayout->addWidget(passwordList);

        keyInputView = new QLineEdit(viewPasswordsPage);
        keyInputView->setObjectName("keyInputView");
        keyInputView->setEchoMode(QLineEdit::EchoMode::Password);

        viewPasswordsLayout->addWidget(keyInputView);

        showKeyViewCheck = new QCheckBox(viewPasswordsPage);
        showKeyViewCheck->setObjectName("showKeyViewCheck");

        viewPasswordsLayout->addWidget(showKeyViewCheck);

        viewPasswordBtn = new QPushButton(viewPasswordsPage);
        viewPasswordBtn->setObjectName("viewPasswordBtn");

        viewPasswordsLayout->addWidget(viewPasswordBtn);

        removePasswordBtn = new QPushButton(viewPasswordsPage);
        removePasswordBtn->setObjectName("removePasswordBtn");

        viewPasswordsLayout->addWidget(removePasswordBtn);

        backBtnViewPasswords = new QPushButton(viewPasswordsPage);
        backBtnViewPasswords->setObjectName("backBtnViewPasswords");

        viewPasswordsLayout->addWidget(backBtnViewPasswords);

        stackedWidget->addWidget(viewPasswordsPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", nullptr));
        mainMenuLabel->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        generateBtn->setText(QCoreApplication::translate("MainWindow", "1. \320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        saveBtn->setText(QCoreApplication::translate("MainWindow", "2. \320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        viewBtn->setText(QCoreApplication::translate("MainWindow", "3. \320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \320\277\320\260\321\200\320\276\320\273\320\270", nullptr));
        generatorMenuLabel->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", nullptr));
        customGenBtn->setText(QCoreApplication::translate("MainWindow", "1. \320\235\320\260\321\201\321\202\321\200\320\260\320\270\320\262\320\260\320\265\320\274\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        complexityGenBtn->setText(QCoreApplication::translate("MainWindow", "2. \320\237\320\276 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        backBtnGeneratorMenu->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        customGeneratorLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\270\321\200\320\265\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\264\320\273\321\217 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        lengthInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        lowerCaseCheck->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\321\207\320\275\321\213\320\265 \320\261\321\203\320\272\320\262\321\213", nullptr));
        upperCaseCheck->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\273\320\260\320\262\320\275\321\213\320\265 \320\261\321\203\320\272\320\262\321\213", nullptr));
        digitsCheck->setText(QCoreApplication::translate("MainWindow", "\320\246\320\270\321\204\321\200\321\213", nullptr));
        specialCheck->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213", nullptr));
        generateCustomBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        backBtnCustomGenerator->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        complexityGeneratorLabel->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 \320\277\320\276 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        complexityCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\270\320\267\320\272\320\260\321\217", nullptr));
        complexityCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        complexityCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\320\272\320\260\321\217", nullptr));

        generateComplexityBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        backBtnComplexityGenerator->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        savePasswordLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        loginInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        showPasswordCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        keyInputSave->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        showKeySaveCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\273\321\216\321\207", nullptr));
        savePasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        backBtnSavePassword->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        viewPasswordsLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \320\277\320\260\321\200\320\276\320\273\320\270", nullptr));
        keyInputView->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\273\321\216\321\207", nullptr));
        showKeyViewCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\273\321\216\321\207", nullptr));
        viewPasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        removePasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        backBtnViewPasswords->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
