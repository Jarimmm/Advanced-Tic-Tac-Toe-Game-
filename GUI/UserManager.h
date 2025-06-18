#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"

class UserManager {
public:
    static bool registerUser(const User& user);
    static bool loginUser(const std::string& username, const std::string& password);
};

#endif
