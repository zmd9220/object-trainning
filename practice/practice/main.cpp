#include <iostream>
#include <string>
#include "Checking.h"
#include "saving.h"
using namespace std;

int main()
{
	checking c = checking("Obama", "1324", "Incheon Korea", 0.3);
	saving s = saving();
	s.deposit(10);
	c.deposit(10);
	c.print();
	for (int i = 1; i <= 7; i++)
	{
		cout << "- day " << i << "-\n";
		s.deposit(10);
		s.setDailyInterest();
		s.setDailyBalance();
		cout << "Checking balance :       " << s.getBalance() << endl;
		c.deposit(10);
		c.setDailyBalance();
		cout << "Savings balance  :       " << c.getBalance() << endl << endl;

	}
	
}