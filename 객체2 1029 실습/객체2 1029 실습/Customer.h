#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
class Customer
{
private:
	std::string name;
	std::string address;
	std::string datePurchase;
	int quantity;
public:
	Customer(std::string name, std::string address,
		std::string datePurchase, int quantity);
	std::string getName();
	std::string getAddress();
	int getQuantity();
	~Customer();
};
#endif // !CUSTOMER_h
