#pragma once

#ifndef saving_H
#define saving_H
#include <string>
#include "Account.h"
class saving : public account
{
public:
	saving();
	saving(std::string a, std::string b, std::string c, double d);
	void setDailyInterest(double a);
private:
	std::string savingsChecking;
	double checkInterest;

	
};
#endif // !saving_H
