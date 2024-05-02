/*
#ifndef PLAYER_H  
#define PLAYER_H  

#include <string>  
#include <unordered_map>  
#include <vector>  
#include "stock.h"  

class Transaction {
public:
    std::string player_id;
    std::string stock_code;
    double price;
    int quantity;

    Transaction(std::string player_id, std::string stock_code, double price, int quantity)
        : player_id(player_id), stock_code(stock_code), price(price), quantity(quantity) {}
};

class Player {
public:
    std::string player_id;
    double cash_balance;
    std::unordered_map<std::string, int> stock_holdings;
    std::vector<Transaction> transaction_history;

    Player(std::string player_id, double initial_cash_balance)
        : player_id(player_id), cash_balance(initial_cash_balance) {}

    // Add more member functions as needed  
};

#endif // PLAYER_H

*/