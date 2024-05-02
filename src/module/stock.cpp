// stock.cpp  
#include "stock.h"  
#include <cmath>  
#include <random>  
#include <iostream>  

// ��������  
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

// ���캯��  
Stock::Stock(const std::string& code, const std::string& name, double initial_price)
    : code(code), name(name), initial_price(initial_price), current_price(initial_price), change(0.0) {
    record_price_history(initial_price, "Initial Price");
}

// ��Ա�����Ķ���  
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

    // ���㲢�洢����һ�μ۸񵽵�ǰ�۸�ı仯�ٷֱ�  
    if (last_price != 0.0) {
        change = ((current_price - last_price) / last_price) * 100.0;
    }
    last_price = current_price; // ������һ�εļ۸�Ϊ��ǰ�۸�  

    // ������������Ӽ�¼�۸���ʷ�Ĵ��룬�����Ҫ�Ļ�  
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

