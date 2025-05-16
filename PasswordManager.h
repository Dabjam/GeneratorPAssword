#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <QList>
#include <QString>
#include <QCryptographicHash>

struct PasswordEntry {
    QString login;
    QString encryptedPassword;
    QString key;
};

class PasswordManager {
public:
    PasswordManager();
    bool setMasterPassword(const QString &masterPassword);
    void savePassword(const QString &login, const QString &password, const QString &key);
    QString getPassword(const QString &login, const QString &key);
    bool removePassword(const QString &login, const QString &key);
    void savePasswords();
    QList<PasswordEntry> getPasswordList() const;
    void saveHint(const QString &hint);
    QString loadHint() const;
    void clearPasswords();

private:
    QString masterPassword;
    QList<PasswordEntry> passwords;
    QString encrypt(const QString &data, const QString &key) const;
    QString decrypt(const QString &data, const QString &key) const;
    QByteArray hashMasterPassword(const QString &password) const;
    bool saveMasterPasswordHash(const QByteArray &hash);
    QByteArray loadMasterPasswordHash() const;
};

#endif // PASSWORDMANAGER_H
