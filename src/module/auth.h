// auth.h
#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <map>

// �����洢�û���Ϣ������
extern std::map<std::string, std::string> users;
// �����洢�û��ļ�λ�õĳ���
extern const std::string USER_FILE;
// ������ǰ��¼�û��ı���
extern std::string currentLoggedInUser;

// ��������
void loadUsers();
void saveUsers();
bool registerUser(const std::string& username, const std::string& password);
bool login(const std::string& username, const std::string& password);
void logout();

#endif  // AUTH_H