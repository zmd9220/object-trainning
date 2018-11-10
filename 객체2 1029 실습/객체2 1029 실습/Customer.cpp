#include <iostream>
#include "Customer.h"
#include "Clothes.h"
#include "Item.h"
#include "Meat.h"

using namespace std;

//커스터머 cpp
Customer::Customer(std::string names, std::string addressa,
	std::string datePurchasea, int quantitys)
{
	name = names;
	address = addressa;
	datePurchase = datePurchasea;
	quantity = quantitys;
}
string Customer::getName()
{
	return name;
}
std::string Customer::getAddress()
{
	return address;
}
int Customer::getQuantity()
{
	return quantity;
}

//Item cpp
Item::Item(int id, std::string a, double b)
{
	barCode = id;
	description = a;
	price = b;
}

void displayInformation()
{

}
	//virtual function for polymorphic effect
void Item::addCustomerPurchase(Customer, int) //pure virtual function
{

}
void Item::changePrice(double a)
{
	price = a;
}


//Clothes cpp
Clothes(int, std::string, double, std::string);
void displayInformation(); // override the method to display course & classes 
void addCustomerPurchase(Customer newCustomer, int);
void changeSize(std::string size);