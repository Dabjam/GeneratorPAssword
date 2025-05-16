#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>

class PasswordGenerator {
public:
    PasswordGenerator();
    QString generatePassword(int length, bool includeLower, bool includeUpper, bool includeDigits, bool includeSpecial);
};

#endif // PASSWORDGENERATOR_H
