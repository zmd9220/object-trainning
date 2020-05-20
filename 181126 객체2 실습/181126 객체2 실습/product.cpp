#include "product.h"

using namespace std;

void Product::setDesc(std::string b)
{
	desc = b;
}
void Product::setQtty(int a)
{
	qtty = a;
}
void Product::setPrice(double a)
{
	price = a;
}
std::string Product::getDesc()
{
	return desc;
}
int Product::getQtty()
{
	return qtty;
}
double Product::getPrice()
{
	return price;
}

