#include "PasswordManager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCryptographicHash>

PasswordManager::PasswordManager() {
    QFile file("passwords.dat");
    if (file.exists()) {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(":");
                if (parts.size() >= 3) {
                    PasswordEntry entry;
                    entry.login = parts[0];
                    entry.encryptedPassword = parts[1];
                    entry.key = parts[2];
                    passwords.append(entry);
                }
            }
            file.close();
            qDebug() << "Loaded" << passwords.size() << "passwords from passwords.dat";
        } else {
            qWarning() << "Failed to open passwords.dat for reading";
        }
    } else {
        qDebug() << "passwords.dat does not exist, starting with empty password list";
    }
}

bool PasswordManager::setMasterPassword(const QString &newMasterPassword) {
    if (newMasterPassword.isEmpty()) {
        qWarning() << "Master password cannot be empty";
        return false;
    }

    // Хешируем новый мастер-пароль
    QByteArray newHash = hashMasterPassword(newMasterPassword);
    QByteArray storedHash = loadMasterPasswordHash();

    if (storedHash.isEmpty()) {
        // Первый запуск: сохраняем хеш мастер-пароля
        qDebug() << "First launch: saving master password hash";
        if (!saveMasterPasswordHash(newHash)) {
            qWarning() << "Failed to save master password hash";
            return false;
        }
        qDebug() << "Master password hash saved successfully";
    } else if (newHash != storedHash) {
        qDebug() << "Master password hash does not match";
        return false; // Позволим родительскому коду обработать неверный пароль
    }

    // Устанавливаем мастер-пароль для шифрования
    masterPassword = newMasterPassword;

    // Проверяем, можем ли расшифровать существующие пароли
    if (!passwords.isEmpty()) {
        bool decryptionFailed = false;
        QList<PasswordEntry> decryptedPasswords;
        for (const auto &entry : passwords) {
            QString decryptedPassword = decrypt(entry.encryptedPassword, masterPassword);
            if (decryptedPassword.isEmpty()) {
                qDebug() << "Failed to decrypt password for login:" << entry.login;
                decryptionFailed = true;
                break;
            }
            PasswordEntry decryptedEntry = entry;
            decryptedEntry.encryptedPassword = decryptedPassword;
            decryptedPasswords.append(decryptedEntry);
        }
        if (decryptionFailed) {
            return false; // Позволим родительскому коду показать диалог
        }
        passwords = decryptedPasswords;
        qDebug() << "Successfully decrypted existing passwords";
    }

    return true;
}

void PasswordManager::savePassword(const QString &login, const QString &password, const QString &key) {
    QString encryptedPassword = encrypt(password, masterPassword);
    PasswordEntry entry;
    entry.login = login;
    entry.encryptedPassword = encryptedPassword;
    entry.key = key;
    passwords.append(entry);
    savePasswords();
    qDebug() << "Saved password for login:" << login;
}

QString PasswordManager::getPassword(const QString &login, const QString &key) {
    for (const auto &entry : passwords) {
        if (entry.login == login && entry.key == key) {
            return decrypt(entry.encryptedPassword, masterPassword);
        }
    }
    return QString();
}

bool PasswordManager::removePassword(const QString &login, const QString &key) {
    for (int i = 0; i < passwords.size(); ++i) {
        if (passwords[i].login == login && passwords[i].key == key) {
            passwords.removeAt(i);
            savePasswords();
            qDebug() << "Removed password for login:" << login;
            return true;
        }
    }
    return false;
}

void PasswordManager::savePasswords() {
    QFile file("passwords.dat");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto &entry : passwords) {
            out << entry.login << ":" << entry.encryptedPassword << ":" << entry.key << "\n";
        }
        file.close();
        qDebug() << "Saved" << passwords.size() << "passwords to passwords.dat";
    } else {
        qWarning() << "Failed to save passwords to file";
    }
}

QList<PasswordEntry> PasswordManager::getPasswordList() const {
    return passwords;
}

void PasswordManager::saveHint(const QString &hint) {
    QFile file("hint.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << hint;
        file.close();
        qDebug() << "Saved hint to hint.txt";
    } else {
        qWarning() << "Failed to save hint to file";
    }
}

QString PasswordManager::loadHint() const {
    QFile file("hint.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString hint = in.readAll();
        file.close();
        qDebug() << "Loaded hint from hint.txt";
        return hint;
    }
    return QString();
}

void PasswordManager::clearPasswords() {
    passwords.clear();
    savePasswords();
    qDebug() << "Cleared all passwords and saved empty list to passwords.dat";
}

QByteArray PasswordManager::hashMasterPassword(const QString &password) const {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    qDebug() << "Generated hash for master password";
    return hash;
}

bool PasswordManager::saveMasterPasswordHash(const QByteArray &hash) {
    QFile file("masterpassword.hash");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(hash);
        file.close();
        qDebug() << "Successfully wrote master password hash to masterpassword.hash";
        return true;
    }
    qWarning() << "Failed to save master password hash to file";
    return false;
}

QByteArray PasswordManager::loadMasterPasswordHash() const {
    QFile file("masterpassword.hash");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray hash = file.readAll();
        file.close();
        qDebug() << "Loaded master password hash from masterpassword.hash";
        return hash;
    }
    qDebug() << "masterpassword.hash does not exist";
    return QByteArray();
}

QString PasswordManager::encrypt(const QString &data, const QString &key) const {
    if (data.isEmpty() || key.isEmpty()) return QString();
    QByteArray dataBytes = data.toUtf8();
    QByteArray keyBytes = key.toUtf8();
    QByteArray result(dataBytes.size(), 0);

    for (int i = 0; i < dataBytes.size(); ++i) {
        result[i] = dataBytes[i] ^ keyBytes[i % keyBytes.size()];
    }

    return result.toBase64();
}

QString PasswordManager::decrypt(const QString &data, const QString &key) const {
    if (data.isEmpty() || key.isEmpty()) return QString();
    QByteArray dataBytes = QByteArray::fromBase64(data.toUtf8());
    QByteArray keyBytes = key.toUtf8();
    QByteArray result(dataBytes.size(), 0);

    for (int i = 0; i < dataBytes.size(); ++i) {
        result[i] = dataBytes[i] ^ keyBytes[i % keyBytes.size()];
    }

    return QString::fromUtf8(result);
}
