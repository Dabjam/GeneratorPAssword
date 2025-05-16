#include "PasswordGenerator.h"
#include <random>
#include <QString>

PasswordGenerator::PasswordGenerator() {}

QString PasswordGenerator::generatePassword(int length, bool includeLower, bool includeUpper, bool includeDigits, bool includeSpecial) {
    const QString lowerChars = "abcdefghijklmnopqrstuvwxyz";
    const QString upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const QString digitChars = "0123456789";
    const QString specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    QString validChars;
    if (includeLower) validChars += lowerChars;
    if (includeUpper) validChars += upperChars;
    if (includeDigits) validChars += digitChars;
    if (includeSpecial) validChars += specialChars;

    if (validChars.isEmpty()) return "";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, validChars.length() - 1);

    QString password;
    for (int i = 0; i < length; ++i) {
        password += validChars[dis(gen)];
    }

    return password;
}
