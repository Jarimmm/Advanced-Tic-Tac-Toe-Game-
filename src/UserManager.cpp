/*
 * UserManager.cpp
 * Rana's Login & Register System with Hashing + Duplicate Check
 */

#include "../include/UserManager.h"
#include "../include/game_constants.h"
#include <fstream>
#include <string>
#include <functional> // for std::hash
#include <iostream>

using namespace std;

// ✅ دالة لتشفير الباسورد
string UserManager::hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

// ✅ تسجيل مستخدم جديد: يمنع التكرار + يشفر الباسورد
bool UserManager::registerUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string line;

    while (getline(infile, line)) {
        size_t delimPos = line.find(':');
        if (delimPos != string::npos) {
            string storedUser = line.substr(0, delimPos);
            if (storedUser == username) {
                cout << RED << "Username already exists!\n" << RESET;
                return false;
            }
        }
    }

    infile.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << ":" << hashPassword(password) << "\n";
    outfile.close();

    cout << GREEN << "Registration successful!\n" << RESET;
    return true;
}

// ✅ تسجيل دخول المستخدم: يتحقق من الاسم والباسورد المشفر
bool UserManager::loginUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string line;
    string hashed = hashPassword(password);

    while (getline(infile, line)) {
        size_t delimPos = line.find(':');
        if (delimPos == string::npos) continue;

        string storedUser = line.substr(0, delimPos);
        string storedHash = line.substr(delimPos + 1);

        if (storedUser == username && storedHash == hashed) {
            cout << GREEN << "Login successful!\n" << RESET;
            return true;
        }
    }

    cout << RED << "Invalid credentials.\n" << RESET;
    return false;
}
