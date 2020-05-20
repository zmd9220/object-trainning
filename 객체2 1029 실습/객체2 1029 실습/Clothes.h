#pragma once

#include "Item.h"
#include <string>

#ifndef CLOTHES_H
#define CLOTHES_H
class Clothes : public Item
{
private:
	std::string size; // 1 small, 2 medium , 3 large
	Customer* customerPurchase;
public:
	Clothes(int, std::string, double, std::string);
	void displayInformation(); // override the method to display course & classes 
	void addCustomerPurchase(Customer newCustomer, int);
	void changeSize(std::string size);
};
#endif // !CLOTHES_H
