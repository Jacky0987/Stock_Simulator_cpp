/*#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

std::map<std::string, std::string> users;
const std::string USER_FILE = "users.dat";
std::string currentLoggedInUser = " NaN ";

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
	currentLoggedInUser = username; // 记录当前登录的用户名
	return true;
}

void logout() {
	if (!currentLoggedInUser.empty()) {
		std::cout << "User " << currentLoggedInUser << " has logged out." << std::endl;
		currentLoggedInUser = ""; // 清空当前登录的用户名
	}
	else {
		std::cout << "No user is currently logged in." << std::endl;
	}
}

// Usage Example:

int main() {
	loadUsers();
	while (true) {
		std::cout << "1. Register\n";
		std::cout << "2. Login\n";
		std::cout << "3. Exit\n";
		std::cout << "4. Log out\n";
		std::cout << "Cuurent Logged User:" << currentLoggedInUser << std::endl;
		std::cout << "Enter your choice: ";

		int choice;
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "Enter username: ";
			std::string username;
			std::cin >> username;
			std::cout << "Enter password: ";
			std::string password;
			std::cin >> password;
			if (registerUser(username, password)) {
				std::cout << "Registration successful!" << std::endl;
			}
		}
		else if (choice == 2) {
			std::cout << "Enter username: ";
			std::string username;
			std::cin >> username;
			std::cout << "Enter password: ";
			std::string password;
			std::cin >> password;
			login(username, password);
		}
		else if (choice == 3) {
			break;
		}
		else if (choice == 4) {
			logout();
		}
		else {
			std::cout << "Invalid choice." << std::endl;
		}
	}
	return 0;
}

*/