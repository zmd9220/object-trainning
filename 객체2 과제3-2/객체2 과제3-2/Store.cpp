#include <iostream>
#include <iomanip>
#include "Store.h"
using namespace std;



	void Store::print(int w)
	{
		double total = 0;
		double amtT = 0;
		string r = "RECEIPT";
		cout << setfill('=') << setw(w / 2 + name.length() / 2) << name << setw(w / 2 - name.length() / 2) << "=" << endl;
		cout << setfill('=') << setw(w / 2 + location.length() / 2) << location << setw(w / 2 - location.length() / 2) << "=" << endl;
		cout << setfill('=') << setw(w / 2 + telno.length() / 2) << telno << setw(w / 2 - telno.length() / 2) << "=" << endl << endl;
		cout << setfill('=') << setw(w / 2 + r.length() / 2) << r << setw(w / 2 - r.length() / 2) << "=" << endl << endl;
	}
	// this function will print the output below 
