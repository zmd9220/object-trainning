#pragma once
#include <iostream>
#include <string>
#ifndef Person_H
#define Person_H



class person
{
private:
	std::string pName;
	std::string ssn;
	std::string address;

public:
	person();
	person(std::string, std::string, std::string);
	void setName(std::string);
	void setSSN(std::string);
	void setAddress(std::string);
	std::string getName();
	std::string getSSN();
	void print();

};
#endif // !Person_H
