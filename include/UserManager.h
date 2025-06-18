#pragma once
#include <string>

class UserManager {
public:
    static bool registerUser(const std::string& username, const std::string& password);
    static bool loginUser(const std::string& username, const std::string& password);
private:
    static std::string hashPassword(const std::string& password);
};
