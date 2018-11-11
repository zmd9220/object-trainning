#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "date.h" // include Date class definition
#include <ctime>
using namespace std;

date::date(unsigned int mn, unsigned int dy, unsigned int yr)
 : month{ mn }, day{ checkDay(dy) }, year{ yr } 
{
	if (mn < 1 || mn > monthsPerYear) 
	{ // validate the month
	 throw invalid_argument("month must be 1-12");
	}
	 // output Date object to show when its constructor is called
	cout << "Date object constructor for date " << toString() << endl;
}

void date::setCtime()
{
	time_t curr;
	struct tm d;
	time(&curr);
	localtime_s(&d, &curr);
	year = d.tm_year + 1900;
	month = d.tm_mon + 1;
	day = d.tm_mday;
}

// print Date object in form month/day/year
string date::toString() const 
{
	ostringstream output;
	output << month << '/' << day << '/' << year;
	return output.str();
	
}

string date::toString2() const
{
	ostringstream output;
	output << checkMonth(month) << " " << day << ", " << year;
	return output.str();
}
string date::toString3() const
{
	ostringstream output;
	output << day << " " << year;
	return output.str();
}

 // output Date object to show when its destructor is called
 date::~date() 
{
	cout << "Date object destructor for date " << toString() << endl;
	
}

 // utility function to confirm proper day value based on
 // month and year; handles leap years, too
unsigned int date::checkDay(int testDay) const 
{
	static const array<int, monthsPerYear + 1> daysPerMonth
	{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
	};
	
		 // determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month]) 
	{
		return testDay;
	}
	
		 // February 29 check for leap year
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) 
	{
		return testDay;
	}
	throw invalid_argument("Invalid day for current month and year");
	
}

string date::checkMonth(int testMonth) const
{
	static const array<string, monthsPerYear + 1> daysPerMonth
	{
		"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};

	if (testMonth > 0 && testMonth < 13)
		return daysPerMonth[testMonth];
}