/*
#include <iostream>
#include <cmath>
#include <random>
#include <vector>

// Based on Geometric Brownian Motion.
// Generate a random number from a normal distribution with mean mu and standard deviation sigma.

double generateGaussianNoise(double mu, double sigma) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::normal_distribution<> d(mu, sigma);
	return d(gen);
}

// mu: the mean of the normal distribution
// sigma: the standard deviation of the normal distribution
double simulateStockPrice(double S0, double mu, double sigma, double dt, int steps) {
	double S = S0;
	for (int i = 0; i < steps; ++i) {
		double noise = generateGaussianNoise(0, 1);
		S *= exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * noise);
		// Stepped Output. Showing the process of the stock price simulation.
		std::cout << S << std::endl;
	}
	return S;
}

int main() {
	double S0 = 100.0; // 初始股票价格
	double mu = 0.05;  // 预期年回报率
	double sigma = 0.2; // 股票的年波动率
	double dt = 1.0 / 252; // 时间步长，假设一年有252个交易日
	int steps = 252; // 模拟一年的交易日

	double finalPrice = simulateStockPrice(S0, mu, sigma, dt, steps);
	std::cout << "模拟后的股票价格: " << finalPrice << std::endl;

	return 0;
}*/