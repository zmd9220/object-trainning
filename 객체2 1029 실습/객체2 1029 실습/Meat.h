#pragma once
#include "Item.h"

#ifndef MEAT_H
#define MEAT_H
class Meat
{
private:
	double weight; // 1 kilos, pound etc
	Customer* customerPurchase;
public:
	Meat(int, std::string, double, double);
	void displayProfile(); // override the method to display course & classes
	void addCustomerPurchase(Customer newCustomer, int);
	void changeWeight(double weight);
};
#endif // !MEAT_H
