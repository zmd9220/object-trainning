#include <iostream>
#include <string>
#include "product.h"
using namespace std;


Product::Product(int a, const string &b, double c)
	{
		prodno = a;
		desc = b;
		price = c;
	}
	void Product::setProdno(int a)
	{
		prodno = a;
	}
	void Product::setDesc(string a)
	{
		desc = a;
	}
	void Product::setPrice(double a)
	{
		price = a;
	}
	int Product::getProdno()
	{
		return prodno;
	}
	string Product::getDesc()
	{
		return desc;
	}
	double Product::getPrice()
	{
		return price;
	}



