#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <memory>
#include "passwordgenerator.h"
#include "passwordmanager.h"
#include "clipboardhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showMainMenu();
    void showPasswordGeneratorMenu();
    void showCustomPasswordGenerator();
    void showComplexityPasswordGenerator();
    void showSavePasswordMenu();
    void showSavedPasswordsMenu();
    void generateCustomPassword();
    void generatePasswordByComplexity();
    void savePassword();
    void viewPassword();
    void removePassword();
    void togglePasswordVisibility(Qt::CheckState state);
    void toggleKeySaveVisibility(Qt::CheckState state);
    void toggleKeyViewVisibility(Qt::CheckState state);
    void goBack(const QString &buttonName);
    void toggleTheme();
    void filterPasswords();

private:
    enum PageIndex {
        MainMenu,
        PasswordGeneratorMenu,
        CustomPasswordGenerator,
        ComplexityPasswordGenerator,
        SavePasswordMenu,
        SavedPasswordsMenu
    };

    enum class Theme { Light, Dark };

    Ui::MainWindow *ui;
    QSettings settings;
    std::unique_ptr<PasswordGenerator> generator;
    std::unique_ptr<PasswordManager> manager;
    std::unique_ptr<ClipboardHandler> clipboard;
    bool masterPasswordSet = false;
    int previousPage = MainMenu;
    Theme currentTheme;

    bool requestMasterPassword();
    QString showMasterPasswordDialog(bool firstAttempt, bool &ok);
    QString showNewMasterPasswordDialog(bool &ok); // Добавляем объявление нового метода
    void showHint();
    void resetPasswordFile();
    void closeEvent(QCloseEvent *event) override;
    void applyTheme();
    QString evaluatePasswordStrength(const QString &password);
    void generateAndHandlePassword(const QString &password);
};

#endif // MAINWINDOW_H
