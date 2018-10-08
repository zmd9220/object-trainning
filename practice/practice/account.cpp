#include <iostream>
#include "Account.h"
#include <sstream>
using namespace std;

account::account()
{
	balance = 0;
	daily_interest = 0;
}
account::account(double a, double b)
{
	balance = a;
	daily_interest = b;
}
void account::withdraw(double a)
{
	balance -= a;
}
void account::deposit(double a) //매일 입금액
{
	balance +=  a; //+ 매일 새로 넣을 돈
}
double account::getBalance()
{
	return balance;
}
double account::get_daily_interest()
{
	return daily_interest;
}
void account::setDailyBalance() //매일 이자 합한 자산
{
	balance += (balance*daily_interest * 1) ;  // 원금*이자*1(하루) 
}
void account::setDailyInterest(double a)
{
	daily_interest = a;
}
void account::print()
{
	person::print();
	cout << "Balance :" << getBalance() << endl << endl
		<< "Checking Daily deposit = " << getBalance() << ", daily interest=0 if balance<50 otherwise .03\n"
		<< "Savings Daily deposit = " << getBalance() << ", daily interest =.06\n\n";


}