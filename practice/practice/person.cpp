#include <iostream>
#include <string>
#include "Person.h"
#include <sstream>
using namespace std;

person::person()
{
	pName = "";
	ssn = "";
	address = "";
}
person::person(std::string a, std::string b, std::string c)
{
	pName = a;
	ssn = b;
	address = c;
}
void person::setName(std::string a)
{
	pName = a;
}
void person::setSSN(std::string b)
{
	ssn = b;
}
void person::setAddress(std::string c)
{
	address = c;
}
std::string person::getName()
{
	return pName;
}
std::string person::getSSN()
{
	return ssn;
}
void person::print() 
{

	cout << "Name :" << getName() << endl
		<< "SSN :" << getSSN() << endl
		<< "Address :" << address << endl;
	
}