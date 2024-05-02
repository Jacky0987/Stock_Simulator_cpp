// market.cpp  
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include "auth.h"
#include "stock.h"
#include "player.h"
#include "market.h"


Market::Market() {
    // Initialize the market with some stocks
    add_stock(Stock("AAPL", "Apple Inc.", 150.00));
    add_stock(Stock("AMZN", "Amazon.com Inc.", 2000.00));
    add_stock(Stock("GOOG", "Alphabet Inc.", 1000.00));
}
Market::~Market() {
    for (auto& pair : stocks) {
        delete pair.second;
    }
}

void Market::add_stock(const Stock& stock) {
    stocks[stock.get_code()] = new Stock(stock);
}

void Market::remove_stock(const std::string& code) {
    if (stocks.find(code) != stocks.end()) {
        delete stocks[code];
        stocks.erase(code);
    }
}

Stock* Market::get_stock(const std::string& code) {
    if (stocks.find(code) != stocks.end()) {
        return stocks[code];
    }
    return nullptr;
}


void Market::list_stocks() const {
    for (const auto& pair : stocks) {
        const Stock* stock = pair.second;
        std::cout << "Code: " << stock->get_code()
            << ", Name: " << stock->get_name()
            << ", Current Price: " << stock->get_current_price()
            << ", Change: " << stock->get_change_since_last_update() << "%"
            << std::endl;
    }
}

void Market::update_all_stock_prices() {
     for (auto& pair : stocks) {
        Stock* stock = pair.second;
        stock->update_price(0.05 , 0.2, 1.0 / 252 , 1);
    }
}