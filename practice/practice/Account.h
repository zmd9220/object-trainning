#pragma once

#ifndef Account_H
#define Account_H
#include "Person.h"
class account : public person
{
public:
	account();
	account(double, double);
	void withdraw(double);
	void deposit(double);
	double getBalance();
	double get_daily_interest();
	void setDailyBalance();
	void setDailyInterest(double);
	void print();

protected:
	double balance;
	double daily_interest;
};
#endif // !Account_H
