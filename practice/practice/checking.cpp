#include <iostream>
#include "Checking.h"
#include <string>

using namespace std;

checking::checking(std::string a, std::string b, std::string c, double d)
{
	setName(a);
	setSSN(b);
	setAddress(c);
	setDailyInterest(d);
}
void checking::setDailyInterest(double a) 
{
	if (this->getBalance()<50) 
	{
		daily_interest = 0;
	}
	else 
	{
		daily_interest = a;
	}
}
