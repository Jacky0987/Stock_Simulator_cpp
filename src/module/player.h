#ifndef PLAYER_H  
#define PLAYER_H  

#include <string>  
#include <unordered_map>  
#include <vector>  

#include "stock.h" 
#include "auth.h"
#include "player.h"
#include "market.h"

class Transaction {
public:
    std::string player_id;
    std::string stock_code;
    double price;
    int quantity;
    // 可以根据需要添加构造函数、析构函数等  
};

class Player {
public:
    std::string player_id;
    double cash_balance;
    std::unordered_map<std::string, int> stock_holdings;
    std::vector<Transaction> transaction_history;

    Player(const std::string& id, double initial_cash);
    ~Player();

    void buy_stock(const Stock& stock, int quantity);
    void sell_stock(const std::string& stock_code, int quantity);
    void view_holdings() const;
    void view_transaction_history() const;
private:
    // 私有成员函数，用于处理交易记录  
    void record_transaction(const std::string& stock_code, double price, int quantity);
};

#endif // PLAYER_H