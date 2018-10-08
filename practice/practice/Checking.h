#pragma once
#ifndef Checking_H
#define Checking_H
#include <string>
#include "Account.h"
class checking : public account
{
public:
	checking(std::string, std::string, std::string, double);
	void setDailyInterest(double);
private:
	std::string numberChecking;
	double checkInterest;
};
#endif // !Chenking_H
