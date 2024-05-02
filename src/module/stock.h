// stock.h  
#ifndef STOCK_H  
#define STOCK_H  

#include <string>  
#include <vector>  
#include <utility> // for std::pair  

class Stock {
public:
    std::string code;
    std::string name;
    double initial_price;
    double current_price;
    double change;
    double last_price;
    std::vector<std::pair<double, std::string>> price_history;

    Stock(const std::string& code, const std::string& name, double initial_price);

    std::string get_code() const;
    std::string get_name() const;
    double get_initial_price() const;
    double get_current_price() const;
    double get_change() const;
    void record_price_history(double price, const std::string& timestamp);
    void update_price(double mu, double sigma, double dt, int steps);
    void set_current_price(double price);
    double get_change_since_last_update() const;

};

#endif // STOCK_H