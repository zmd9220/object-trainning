#pragma once

#ifndef MotorVehicle_H
#define MotorVehicle_H
#include <string>
class motorVehicle
{
	friend std::ostream& operator<<(std::ostream&, motorVehicle&);
private:
	std::string make;
	std::string fuelType;
	int yearOfManufacture;
	std::string color;
	int engineCapacity;

public:
	explicit motorVehicle(std::string ,std::string, int, std::string,int); 
	bool operator==(motorVehicle&);
	bool operator!=(motorVehicle&);
	bool operator>(motorVehicle&);
	
};
#endif
