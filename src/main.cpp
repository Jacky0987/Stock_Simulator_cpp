
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <conio.h>
#include <chrono>  
#include <thread>


#include "module/auth.h"
#include "module/stock.h"
#include "module/player.h"
#include "module/market.h"


bool loggedStatus = false;
void menu2();

void menu2() {
	Market market;
	int option2, quantity;
	double currentBalance = 2000000;
	std::string stock_name;
	Player player(currentLoggedInUser, currentBalance);
	std::cout << "1. View Stock List\n";
	std::cout << "2. Buy Stock\n";
	std::cout << "3. Sell Stock\n";
	std::cout << "4. View Stock Detail\n";
	std::cout << "5. View User Profile\n";
	std::cout << "6. View Transaction History\n";
	std::cout << "7. View Stock Price Chart\n";
	std::cin >> option2;
	switch (option2) {
	case 1:
		system("cls");
		std::cout << "The full list of stocks is as follows:" << std::endl;
		market.update_all_stock_prices();
		market.list_stocks();
		_getch();
		break;
	case 2:
		std::cout << "What stock do you want to buy?" << std::endl;
		std::cin >> stock_name;
		std::cout << "How many do you want to buy?" << std::endl;
		std::cin >> quantity;
		_getch();
		break;
	case 3:
		
		break;
	case 4:
		
		break;
	case 5:
		
		break;
	case 6:
		
		break;
	case 7:
		
		break;
	default:
		std::cout << "Invalid option." << std::endl;
		break;
	}
}


int main() {
	Market market;
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

			// 保存原来的缓冲区
			std::streambuf* orig_buf = std::cout.rdbuf();
			// 开启新的文件流，指向空设备
			std::ofstream null_stream("/dev/null");
			// 将 cout 的缓冲区指向空设备
			std::cout.rdbuf(null_stream.rdbuf());
			// 调用会产生输出的函数
			if (login(username, password)) loggedStatus = true;
			// 恢复 cout 的原始缓冲区
			std::cout.rdbuf(orig_buf);
			// 继续其他正确显示输出的操作
			_getch();

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
	while (currentLoggedInUser.empty() == false && loggedStatus == true) {
		system("cls");
		std::cout << "Welcome to Stock Simulator developed by Jacky0987!" << std::endl;
		std::cout << "You are logged in as " << currentLoggedInUser << std::endl;

		menu2();
	}
	return 0;
}