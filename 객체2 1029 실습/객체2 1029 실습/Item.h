#pragma once

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Customer.h"
class Item 
{
protected:
	int barCode;
	std::string description;
	double price;
public:
	Item(int id, std::string, double);
	virtual ~Item();
	virtual void displayInformation();
	//virtual function for polymorphic effect
	virtual void
		addCustomerPurchase(Customer,
			int) = 0; //pure virtual function
	void changePrice(double);
};
#endif // !ITEM_H
