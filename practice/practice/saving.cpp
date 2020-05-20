#include <iostream>
#include "saving.h"

using namespace std;

saving::saving()
{
	daily_interest = 0.06;
	balance = 10;
}
saving::saving(std::string a, std::string b, std::string c, double d)
{
	setName(a);
	setSSN(b);
	setAddress(c);

}
void saving::setDailyInterest(double a)
{
	daily_interest = a;
}