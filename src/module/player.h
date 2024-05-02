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
    // ���Ը�����Ҫ��ӹ��캯��������������  
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
    // ˽�г�Ա���������ڴ����׼�¼  
    void record_transaction(const std::string& stock_code, double price, int quantity);
};

#endif // PLAYER_H