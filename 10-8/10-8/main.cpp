#include <iostream>
#include "motorVehicle.h"
#include <string>
using namespace std;

string TNF(bool a)
{
	if (a == 1)
		return "TRUE";
	else
		return "FALSE";
}

int main()
{
	motorVehicle BMW("bmw", "diesel", 2017, "red", 1500);
	motorVehicle BMW2("bmw", "diesel", 2007, "blue", 2500);

	cout << TNF(BMW == BMW2) << endl;
	cout << TNF(BMW != BMW2) << endl;
	cout << TNF(BMW > BMW2) << endl;
	cout << BMW;
}