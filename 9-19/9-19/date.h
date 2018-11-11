#pragma once
#include <string>

#ifndef Date_H
#define Date_H

class date {
	public:
		static const unsigned int monthsPerYear{ 12 }; // months in a year
		explicit date(unsigned int = 6, unsigned int = 14, unsigned int = 1992);
		std::string toString() const; // date string in month/day/year format
		std::string toString2() const;
		std::string toString3() const;
		void setCtime();

		~date(); // provided to confirm destruction order
	private:
		unsigned int month; // 1-12 (January-December)
		unsigned int day; // 1-31 based on month
		unsigned int year; // any year

		// utility function to check if day is proper for month and year
		unsigned int checkDay(int) const;
		std::string checkMonth(int) const;
};

#endif // !Date_H
