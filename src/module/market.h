// market.h  
#ifndef MARKET_H  
#define MARKET_H  

#include "stock.h"  
#include <map>  

class Market {
public:
    Market();
    ~Market();

    void add_stock(const Stock& stock);
    void remove_stock(const std::string& code);
    Stock* get_stock(const std::string& code);
    void list_stocks() const;
    std::map<std::string, Stock*> stocks;
};

#endif // MARKET_H