#pragma once

#ifndef TIME_H
#define TIME_H
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	void setTime(int, int, int); //set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation) // get functions
	int getHour() const; // return hour
	int getMinute() const; // return minute
	int getSecond() const; // return second
	void printUniversal(); // print Universal time
	void printStandard(); // print Standard time
};

#endif // !TIME_H

