#include <iostream>
#include "Store.h"

using namespace std;

int main()
{	
	string a, b, c;
	int d;
	cout << "Enter the name of company :\n";
	getline(cin, a);
	cout << "Enter address :\n";
	getline(cin, b);
	cout << "Enter telephone number :\n";
	getline(cin, c);
	cout << "Enter the width of the receipt :\n";
	cin >> d;

	Store e1(a, b, c);
	e1.print(d);
}