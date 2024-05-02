
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include "module/auth.h"

bool loggedStatus = false;
void menu2();

void menu2() {
	
}
int main() {
	loadUsers();
	while (currentLoggedInUser == "" && (loggedStatus == false)) {
		std::cout << "Welcome to Stock Simulator developed by Jacky0987!" << std::endl;
		std::cout << "Please choose an option:" << std::endl;
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

			// ����ԭ���Ļ�����
			std::streambuf* orig_buf = std::cout.rdbuf();
			// �����µ��ļ�����ָ����豸
			std::ofstream null_stream("/dev/null");
			// �� cout �Ļ�����ָ����豸
			std::cout.rdbuf(null_stream.rdbuf());
			// ���û��������ĺ���
			if (login(username, password)) loggedStatus = true;
			// �ָ� cout ��ԭʼ������
			std::cout.rdbuf(orig_buf);
			// ����������ȷ��ʾ����Ĳ���

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
	int choice_2;
	while (currentLoggedInUser.empty() == false && loggedStatus == true) {
		std::cout << "You are logged in as " << currentLoggedInUser << std::endl;
		menu2();
	}
	return 0;
}