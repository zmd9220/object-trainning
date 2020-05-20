#pragma once
#include <string>
class Product {
private:

	std::string desc;
	int qtty;
	double price;
public:
	Product(std::string a, int b, double c) :desc(a), qtty(b), price(c) {}//constructor
	void setDesc(std::string);
	void setQtty(int);
	void setPrice(double);
	std::string getDesc();
	int getQtty();
	double getPrice();
};