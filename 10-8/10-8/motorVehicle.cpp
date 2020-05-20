#include <iostream>
#include "motorVehicle.h"
using namespace std;

motorVehicle::motorVehicle(std::string a, std::string b, int c, std::string d, int e)
{
	make = a;
	fuelType = b;
	yearOfManufacture = c;
	color = d;
	engineCapacity = e;
}
bool motorVehicle::operator==(motorVehicle& a)
{
	if (make == a.make && fuelType == a.fuelType && yearOfManufacture == a.yearOfManufacture && color == a.color && engineCapacity == a.engineCapacity)
		return true;
	else
		return false;
}
bool motorVehicle::operator!=(motorVehicle& a)
{
	if (make != a.make || fuelType != a.fuelType || yearOfManufacture != a.yearOfManufacture || color != a.color || engineCapacity != a.engineCapacity)
		return true;
	else
		return false;
}
bool motorVehicle::operator>(motorVehicle& a)
{
	if (yearOfManufacture > a.yearOfManufacture)
		return true;
	else
		return false;
}
ostream& operator<<(ostream& output, motorVehicle& a)
{ 
	output << "make: " << a.make << "\nfuelType: " << a.fuelType << "\nyearOfManufacture: " << a.yearOfManufacture << "\ncolor: " << a.color << "\nengineCapacity: " << a.engineCapacity << endl;
	return output;
}