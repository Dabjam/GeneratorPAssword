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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *MainMenu;
    QPushButton *generateBtn;
    QPushButton *saveBtn;
    QPushButton *viewBtn;
    QLabel *headerLabel_7;
    QWidget *PasswordGeneratorMenu;
    QLabel *headerLabel_2;
    QPushButton *customGenBtn;
    QPushButton *complexityGenBtn;
    QPushButton *backBtnGeneratorMenu;
    QWidget *CustomPasswordGenerator;
    QLabel *headerLabel_3;
    QLabel *label;
    QLineEdit *lengthInput;
    QCheckBox *lowerCaseCheck;
    QCheckBox *upperCaseCheck;
    QCheckBox *digitsCheck;
    QCheckBox *specialCheck;
    QPushButton *generateCustomBtn;
    QPushButton *backBtnCustomGenerator;
    QWidget *ComplexityPasswordGenerator;
    QLabel *headerLabel_4;
    QLabel *label_2;
    QComboBox *complexityCombo;
    QPushButton *generateComplexityBtn;
    QPushButton *backBtnComplexityGenerator;
    QWidget *SavePasswordMenu;
    QLabel *headerLabel_5;
    QLabel *label_3;
    QLineEdit *loginInput;
    QLabel *label_4;
    QLineEdit *passwordInput;
    QCheckBox *showPasswordCheck;
    QLabel *label_5;
    QLineEdit *keyInputSave;
    QCheckBox *showKeySaveCheck;
    QPushButton *savePasswordBtn;
    QPushButton *backBtnSavePassword;
    QWidget *SavedPasswordsMenu;
    QLabel *headerLabel_6;
    QLabel *label_6;
    QLineEdit *searchInput;
    QTableWidget *passwordTable;
    QLabel *label_7;
    QLineEdit *keyInputView;
    QCheckBox *showKeyViewCheck;
    QPushButton *viewPasswordBtn;
    QPushButton *removePasswordBtn;
    QPushButton *backBtnViewPasswords;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 500, 700));
        MainMenu = new QWidget();
        MainMenu->setObjectName("MainMenu");
        generateBtn = new QPushButton(MainMenu);
        generateBtn->setObjectName("generateBtn");
        generateBtn->setGeometry(QRect(139, 230, 221, 50));
        QFont font;
        font.setPointSize(12);
        generateBtn->setFont(font);
        saveBtn = new QPushButton(MainMenu);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(139, 290, 221, 50));
        saveBtn->setFont(font);
        viewBtn = new QPushButton(MainMenu);
        viewBtn->setObjectName("viewBtn");
        viewBtn->setGeometry(QRect(139, 350, 221, 50));
        viewBtn->setFont(font);
        headerLabel_7 = new QLabel(MainMenu);
        headerLabel_7->setObjectName("headerLabel_7");
        headerLabel_7->setGeometry(QRect(10, 180, 471, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        headerLabel_7->setFont(font1);
        headerLabel_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(MainMenu);
        PasswordGeneratorMenu = new QWidget();
        PasswordGeneratorMenu->setObjectName("PasswordGeneratorMenu");
        headerLabel_2 = new QLabel(PasswordGeneratorMenu);
        headerLabel_2->setObjectName("headerLabel_2");
        headerLabel_2->setGeometry(QRect(10, 180, 471, 41));
        headerLabel_2->setFont(font1);
        headerLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        customGenBtn = new QPushButton(PasswordGeneratorMenu);
        customGenBtn->setObjectName("customGenBtn");
        customGenBtn->setGeometry(QRect(110, 240, 271, 50));
        customGenBtn->setFont(font);
        complexityGenBtn = new QPushButton(PasswordGeneratorMenu);
        complexityGenBtn->setObjectName("complexityGenBtn");
        complexityGenBtn->setGeometry(QRect(110, 300, 271, 50));
        complexityGenBtn->setFont(font);
        backBtnGeneratorMenu = new QPushButton(PasswordGeneratorMenu);
        backBtnGeneratorMenu->setObjectName("backBtnGeneratorMenu");
        backBtnGeneratorMenu->setGeometry(QRect(110, 360, 271, 40));
        backBtnGeneratorMenu->setFont(font);
        stackedWidget->addWidget(PasswordGeneratorMenu);
        CustomPasswordGenerator = new QWidget();
        CustomPasswordGenerator->setObjectName("CustomPasswordGenerator");
        headerLabel_3 = new QLabel(CustomPasswordGenerator);
        headerLabel_3->setObjectName("headerLabel_3");
        headerLabel_3->setGeometry(QRect(10, 10, 471, 41));
        headerLabel_3->setFont(font1);
        headerLabel_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(CustomPasswordGenerator);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 70, 141, 31));
        label->setFont(font);
        lengthInput = new QLineEdit(CustomPasswordGenerator);
        lengthInput->setObjectName("lengthInput");
        lengthInput->setGeometry(QRect(200, 70, 251, 31));
        lengthInput->setFont(font);
        lowerCaseCheck = new QCheckBox(CustomPasswordGenerator);
        lowerCaseCheck->setObjectName("lowerCaseCheck");
        lowerCaseCheck->setGeometry(QRect(50, 120, 401, 31));
        lowerCaseCheck->setFont(font);
        upperCaseCheck = new QCheckBox(CustomPasswordGenerator);
        upperCaseCheck->setObjectName("upperCaseCheck");
        upperCaseCheck->setGeometry(QRect(50, 170, 401, 31));
        upperCaseCheck->setFont(font);
        digitsCheck = new QCheckBox(CustomPasswordGenerator);
        digitsCheck->setObjectName("digitsCheck");
        digitsCheck->setGeometry(QRect(50, 220, 401, 31));
        digitsCheck->setFont(font);
        specialCheck = new QCheckBox(CustomPasswordGenerator);
        specialCheck->setObjectName("specialCheck");
        specialCheck->setGeometry(QRect(50, 270, 401, 31));
        specialCheck->setFont(font);
        generateCustomBtn = new QPushButton(CustomPasswordGenerator);
        generateCustomBtn->setObjectName("generateCustomBtn");
        generateCustomBtn->setGeometry(QRect(150, 330, 200, 50));
        generateCustomBtn->setFont(font);
        backBtnCustomGenerator = new QPushButton(CustomPasswordGenerator);
        backBtnCustomGenerator->setObjectName("backBtnCustomGenerator");
        backBtnCustomGenerator->setGeometry(QRect(10, 610, 100, 40));
        backBtnCustomGenerator->setFont(font);
        stackedWidget->addWidget(CustomPasswordGenerator);
        ComplexityPasswordGenerator = new QWidget();
        ComplexityPasswordGenerator->setObjectName("ComplexityPasswordGenerator");
        headerLabel_4 = new QLabel(ComplexityPasswordGenerator);
        headerLabel_4->setObjectName("headerLabel_4");
        headerLabel_4->setGeometry(QRect(10, 10, 471, 41));
        headerLabel_4->setFont(font1);
        headerLabel_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(ComplexityPasswordGenerator);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 70, 121, 31));
        label_2->setFont(font);
        complexityCombo = new QComboBox(ComplexityPasswordGenerator);
        complexityCombo->addItem(QString());
        complexityCombo->addItem(QString());
        complexityCombo->addItem(QString());
        complexityCombo->setObjectName("complexityCombo");
        complexityCombo->setGeometry(QRect(180, 70, 271, 31));
        complexityCombo->setFont(font);
        generateComplexityBtn = new QPushButton(ComplexityPasswordGenerator);
        generateComplexityBtn->setObjectName("generateComplexityBtn");
        generateComplexityBtn->setGeometry(QRect(150, 130, 200, 50));
        generateComplexityBtn->setFont(font);
        backBtnComplexityGenerator = new QPushButton(ComplexityPasswordGenerator);
        backBtnComplexityGenerator->setObjectName("backBtnComplexityGenerator");
        backBtnComplexityGenerator->setGeometry(QRect(10, 610, 100, 40));
        backBtnComplexityGenerator->setFont(font);
        stackedWidget->addWidget(ComplexityPasswordGenerator);
        SavePasswordMenu = new QWidget();
        SavePasswordMenu->setObjectName("SavePasswordMenu");
        headerLabel_5 = new QLabel(SavePasswordMenu);
        headerLabel_5->setObjectName("headerLabel_5");
        headerLabel_5->setGeometry(QRect(10, 10, 471, 41));
        headerLabel_5->setFont(font1);
        headerLabel_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(SavePasswordMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 121, 31));
        label_3->setFont(font);
        loginInput = new QLineEdit(SavePasswordMenu);
        loginInput->setObjectName("loginInput");
        loginInput->setGeometry(QRect(180, 70, 271, 31));
        loginInput->setFont(font);
        label_4 = new QLabel(SavePasswordMenu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 120, 121, 31));
        label_4->setFont(font);
        passwordInput = new QLineEdit(SavePasswordMenu);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setGeometry(QRect(180, 120, 271, 31));
        passwordInput->setFont(font);
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);
        showPasswordCheck = new QCheckBox(SavePasswordMenu);
        showPasswordCheck->setObjectName("showPasswordCheck");
        showPasswordCheck->setGeometry(QRect(180, 160, 271, 31));
        showPasswordCheck->setFont(font);
        label_5 = new QLabel(SavePasswordMenu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 200, 121, 31));
        label_5->setFont(font);
        keyInputSave = new QLineEdit(SavePasswordMenu);
        keyInputSave->setObjectName("keyInputSave");
        keyInputSave->setGeometry(QRect(180, 200, 271, 31));
        keyInputSave->setFont(font);
        keyInputSave->setEchoMode(QLineEdit::EchoMode::Password);
        showKeySaveCheck = new QCheckBox(SavePasswordMenu);
        showKeySaveCheck->setObjectName("showKeySaveCheck");
        showKeySaveCheck->setGeometry(QRect(180, 240, 271, 31));
        showKeySaveCheck->setFont(font);
        savePasswordBtn = new QPushButton(SavePasswordMenu);
        savePasswordBtn->setObjectName("savePasswordBtn");
        savePasswordBtn->setGeometry(QRect(230, 290, 200, 50));
        savePasswordBtn->setFont(font);
        backBtnSavePassword = new QPushButton(SavePasswordMenu);
        backBtnSavePassword->setObjectName("backBtnSavePassword");
        backBtnSavePassword->setGeometry(QRect(10, 610, 100, 40));
        backBtnSavePassword->setFont(font);
        stackedWidget->addWidget(SavePasswordMenu);
        SavedPasswordsMenu = new QWidget();
        SavedPasswordsMenu->setObjectName("SavedPasswordsMenu");
        headerLabel_6 = new QLabel(SavedPasswordsMenu);
        headerLabel_6->setObjectName("headerLabel_6");
        headerLabel_6->setGeometry(QRect(10, 10, 471, 41));
        headerLabel_6->setFont(font1);
        headerLabel_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(SavedPasswordsMenu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 60, 121, 31));
        label_6->setFont(font);
        searchInput = new QLineEdit(SavedPasswordsMenu);
        searchInput->setObjectName("searchInput");
        searchInput->setGeometry(QRect(180, 60, 271, 31));
        searchInput->setFont(font);
        passwordTable = new QTableWidget(SavedPasswordsMenu);
        if (passwordTable->columnCount() < 2)
            passwordTable->setColumnCount(2);
        QFont font2;
        font2.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        passwordTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        passwordTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        passwordTable->setObjectName("passwordTable");
        passwordTable->setGeometry(QRect(50, 100, 401, 371));
        passwordTable->setFont(font);
        passwordTable->setColumnCount(2);
        label_7 = new QLabel(SavedPasswordsMenu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 480, 121, 31));
        label_7->setFont(font);
        keyInputView = new QLineEdit(SavedPasswordsMenu);
        keyInputView->setObjectName("keyInputView");
        keyInputView->setGeometry(QRect(180, 480, 271, 31));
        keyInputView->setFont(font);
        keyInputView->setEchoMode(QLineEdit::EchoMode::Password);
        showKeyViewCheck = new QCheckBox(SavedPasswordsMenu);
        showKeyViewCheck->setObjectName("showKeyViewCheck");
        showKeyViewCheck->setGeometry(QRect(180, 510, 271, 31));
        showKeyViewCheck->setFont(font);
        viewPasswordBtn = new QPushButton(SavedPasswordsMenu);
        viewPasswordBtn->setObjectName("viewPasswordBtn");
        viewPasswordBtn->setGeometry(QRect(40, 550, 200, 50));
        viewPasswordBtn->setFont(font);
        removePasswordBtn = new QPushButton(SavedPasswordsMenu);
        removePasswordBtn->setObjectName("removePasswordBtn");
        removePasswordBtn->setGeometry(QRect(260, 550, 200, 50));
        removePasswordBtn->setFont(font);
        backBtnViewPasswords = new QPushButton(SavedPasswordsMenu);
        backBtnViewPasswords->setObjectName("backBtnViewPasswords");
        backBtnViewPasswords->setGeometry(QRect(40, 610, 421, 40));
        backBtnViewPasswords->setFont(font);
        stackedWidget->addWidget(SavedPasswordsMenu);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", nullptr));
        generateBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        saveBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        viewBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", nullptr));
        headerLabel_7->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", nullptr));
        headerLabel_2->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        customGenBtn->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\260\320\270\320\262\320\260\320\265\320\274\321\213\320\271 \320\263\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200", nullptr));
        complexityGenBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        backBtnGeneratorMenu->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        headerLabel_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\260\320\270\320\262\320\260\320\265\320\274\321\213\320\271 \320\263\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\277\320\260\321\200\320\276\320\273\321\217:", nullptr));
        lengthInput->setText(QString());
        lowerCaseCheck->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\321\200\320\276\321\207\320\275\321\213\320\265 \320\261\321\203\320\272\320\262\321\213 (a-z)", nullptr));
        upperCaseCheck->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\263\320\273\320\260\320\262\320\275\321\213\320\265 \320\261\321\203\320\272\320\262\321\213 (A-Z)", nullptr));
        digitsCheck->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\206\320\270\321\204\321\200\321\213 (0-9)", nullptr));
        specialCheck->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\201\320\277\320\265\321\206\321\201\320\270\320\274\320\262\320\276\320\273\321\213 (!@#$%^&*)", nullptr));
        generateCustomBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        backBtnCustomGenerator->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        headerLabel_4->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\276 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        complexityCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\270\320\267\320\272\320\260\321\217", nullptr));
        complexityCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        complexityCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\320\272\320\260\321\217", nullptr));

        generateComplexityBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        backBtnComplexityGenerator->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        headerLabel_5->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        showPasswordCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207:", nullptr));
        showKeySaveCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\273\321\216\321\207", nullptr));
        savePasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        backBtnSavePassword->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        headerLabel_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \320\277\320\260\321\200\320\276\320\273\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = passwordTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = passwordTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207:", nullptr));
        showKeyViewCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\273\321\216\321\207", nullptr));
        viewPasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        removePasswordBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        backBtnViewPasswords->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
