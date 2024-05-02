// player.cpp  
#include "player.h"  
#include "market.h"
#include "stock.h"
#include <string>
#include <iostream>  
#include <iomanip>  

#include "auth.h"


Player::Player(const std::string& id, double initial_cash)
    : player_id(id), cash_balance(initial_cash) {
}


Player::~Player() {
    // 在这个例子中，我们不需要在析构函数中做特殊的清理工作  
}

void Player::buy_stock(const Stock& stock, int quantity) {
    if (quantity <= 0) return; // 防止无效交易  
    double total_cost = stock.get_current_price() * quantity;
    if (cash_balance >= total_cost) {
        cash_balance -= total_cost;
        stock_holdings[stock.get_code()] += quantity;
        record_transaction(stock.get_code(), stock.get_current_price(), quantity);
        std::cout << "Bought " << quantity << " shares of " << stock.get_code() << " at "
            << stock.get_current_price() << " each." << std::endl;
    }
    else {
        std::cout << "Insufficient funds to buy " << quantity << " shares of "
            << stock.get_code() << "." << std::endl;
    }
}


void Player::sell_stock(const std::string& stock_code, int quantity) {

    if (quantity <= 0) return; // 防止无效交易数量  

    auto stock_iter = stock_holdings.find(stock_code);
    if (stock_iter == stock_holdings.end() || stock_iter->second < quantity) {
        std::cout << "You do not hold enough shares of " << stock_code << " to sell " << quantity << " shares." << std::endl;
        return; // 边界处理：如果玩家没有持有该股票或持有量不足，则不进行交易  
    }

    // 获取股票的当前市场价格  
    Market market; // 假设市场数据已经在外部初始化完成
    Stock* stock = market.get_stock(stock_code);
    if (stock == nullptr) {
        std::cout << "Stock code " << stock_code << " not found in the market." << std::endl;
        return;
    }
    double current_price = stock->get_current_price();

    // 计算交易后的现金余额和股票持有量
    double proceeds = current_price * quantity;

    cash_balance += proceeds;
    stock_iter->second -= quantity;
    if (stock_iter->second == 0) {
        stock_holdings.erase(stock_iter); // 如果卖完后没有剩余，则从持股映射中移除该股票  
    }

    record_transaction(stock_code, current_price, -quantity);
    std::cout << "Sold " << quantity << " shares of " << stock_code << " at "
        << current_price << " each." << std::endl;
}

void Player::view_holdings() const {
    std::cout << "Stock Holdings:" << std::endl;
    for (const auto& holding : stock_holdings) {
        std::cout << "Stock Code: " << holding.first << ", Quantity: " << holding.second << std::endl;
    }
    std::cout << "Cash Balance: " << cash_balance << std::endl;
}

void Player::view_transaction_history() const {
    std::cout << "Transaction History:" << std::endl;
    for (const auto& transaction : transaction_history) {
        std::cout << "Player ID: " << transaction.player_id
            << ", Stock Code: " << transaction.stock_code
            << ", Price: " << transaction.price
            << ", Quantity: " << transaction.quantity
            << (transaction.quantity > 0 ? " (Buy)" : " (Sell)") << std::endl;
    }
}

void Player::record_transaction(const std::string& stock_code, double price, int quantity) {
    Transaction transaction;
    transaction.player_id = player_id;
    transaction.stock_code = stock_code;
    transaction.price = price;
    transaction.quantity = quantity;
    transaction_history.push_back(transaction);
}