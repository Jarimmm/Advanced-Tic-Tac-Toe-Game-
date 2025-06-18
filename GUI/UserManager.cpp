#include "UserManager.h"
#include <fstream>
#include <sstream>

bool UserManager::registerUser(const User& user) {
    std::ifstream infile("users.txt");
    std::string line;
    while (getline(infile, line)) {
        std::stringstream ss(line);
        std::string existingUsername;
        getline(ss, existingUsername, ',');
        if (existingUsername == user.username) {
            return false;
        }
    }
    infile.close();

    std::ofstream outfile("users.txt", std::ios::app);
    outfile << user.username << "," << user.password << "\n";
    return true;
}

bool UserManager::loginUser(const std::string& username, const std::string& password) {
    std::ifstream infile("users.txt");
    std::string line;
    while (getline(infile, line)) {
        std::stringstream ss(line);
        std::string storedUsername, storedPassword;
        getline(ss, storedUsername, ',');
        getline(ss, storedPassword);
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}
