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
	double S0 = 100.0; // ��ʼ��Ʊ�۸�
	double mu = 0.05;  // Ԥ����ر���
	double sigma = 0.2; // ��Ʊ���겨����
	double dt = 1.0 / 252; // ʱ�䲽��������һ����252��������
	int steps = 252; // ģ��һ��Ľ�����

	double finalPrice = simulateStockPrice(S0, mu, sigma, dt, steps);
	std::cout << "ģ���Ĺ�Ʊ�۸�: " << finalPrice << std::endl;

	return 0;
}*/