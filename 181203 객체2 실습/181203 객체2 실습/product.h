#pragma once

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product
{
private:
	int prodno;
	std::string desc;
	double price;
public:
	Product(int = 0, const std::string & = "", double = 0.0);
	void setProdno(int );
	void setDesc(std::string );
	void setPrice(double );
	int getProdno();
	std::string getDesc();
	double getPrice();
};

#endif // !PRODUCT_H
