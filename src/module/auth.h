// auth.h
#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <map>

// 声明存储用户信息的容器
extern std::map<std::string, std::string> users;
// 声明存储用户文件位置的常量
extern const std::string USER_FILE;
// 声明当前登录用户的变量
extern std::string currentLoggedInUser;

// 函数声明
void loadUsers();
void saveUsers();
bool registerUser(const std::string& username, const std::string& password);
bool login(const std::string& username, const std::string& password);
void logout();

#endif  // AUTH_H