#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>

// 初始化外部变量
std::map<std::string, std::string> users;
const std::string USER_FILE = "users.dat";
std::string currentLoggedInUser = "";


void loadUsers() {
    std::ifstream file(USER_FILE);
    std::string line, username, password;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> username >> password)) {
            break;
        }
        users[username] = password;
    }
}

void saveUsers() {
    std::ofstream file(USER_FILE);
    for (const auto& user : users) {
        file << user.first << " " << user.second << std::endl;
    }
}

bool registerUser(const std::string& username, const std::string& password) {
    if (users.find(username) != users.end()) {
        std::cout << "Username already exists." << std::endl;
        return false;
    }
    users[username] = password;
    saveUsers();
    return true;
}

bool login(const std::string& username, const std::string& password) {
    loadUsers();
    if (users.find(username) == users.end()) {
        std::cout << "Username does not exist." << std::endl;
        return false;
    }
    if (users[username] != password) {
        std::cout << "Incorrect password." << std::endl;
        return false;
    }
    std::cout << "Login successful!" << std::endl;
    currentLoggedInUser = username;
    return true;
}

void logout() {
    if (!currentLoggedInUser.empty()) {
        std::cout << "User " << currentLoggedInUser << " has logged out." << std::endl;
        currentLoggedInUser = "";
    }
    else {
        std::cout << "No user is currently logged in." << std::endl;
    }
}
