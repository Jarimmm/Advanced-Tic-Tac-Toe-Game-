#ifndef USERMANAGER_QT_H
#define USERMANAGER_QT_H

#include "User.h"
#include <QString>

class UserManagerQt {
public:
    static bool registerUser(const User& user);
    static bool loginUser(const std::string& username, const std::string& password);

private:
    static QString hashPassword(const QString& password);
};

#endif // USERMANAGER_QT_H
