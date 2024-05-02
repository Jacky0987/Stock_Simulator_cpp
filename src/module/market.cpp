// market.cpp  
#include "market.h"  
#include <iostream>  

Market::Market() {
    // Constructor implementation if needed  
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