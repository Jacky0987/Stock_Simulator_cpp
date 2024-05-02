// stock.cpp  
#include "stock.h"  
#include <cmath>  
#include <random>  
#include <iostream>  

// 辅助函数  
double generateGaussianNoise(double mu, double sigma) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> d(mu, sigma);
    return d(gen);
}

double simulateStockPrice(double S0, double mu, double sigma, double dt, int steps) {
    double S = S0;
    for (int i = 0; i < steps; ++i) {
        double noise = generateGaussianNoise(0, 1);
        S *= exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * noise);
    }
    return S;
}

// 构造函数  
Stock::Stock(const std::string& code, const std::string& name, double initial_price)
    : code(code), name(name), initial_price(initial_price), current_price(initial_price), change(0.0) {
    record_price_history(initial_price, "Initial Price");
}

// 成员函数的定义  
std::string Stock::get_code() const {
    return code;
}

std::string Stock::get_name() const {
    return name;
}

double Stock::get_initial_price() const {
    return initial_price;
}

double Stock::get_current_price() const {
    return current_price;
}

void Stock::set_current_price(double price) {
    double previous_price = current_price;
    current_price = price;

    // 计算并存储从上一次价格到当前价格的变化百分比  
    if (last_price != 0.0) {
        change = ((current_price - last_price) / last_price) * 100.0;
    }
    last_price = current_price; // 更新上一次的价格为当前价格  

    // 可以在这里添加记录价格历史的代码，如果需要的话  
    record_price_history(price, "Price Update");  
}

double Stock::get_change_since_last_update() const {
    return change;
}

double Stock::get_change() const {
    return change;
}

void Stock::record_price_history(double price, const std::string& timestamp) {
    price_history.push_back(std::make_pair(price, timestamp));
}

void Stock::update_price(double mu, double sigma, double dt, int steps) {
    double new_price = simulateStockPrice(current_price, mu, sigma, dt, steps);
    set_current_price(new_price);
}

