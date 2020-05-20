#include <iostream>
#include <sstream>
#include "product.h"
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	stringstream ss("Banana 12 5.5 Apple 13 10.0 Orange 3 4.0 Apple 12 10 Banana 10 4 Mango 15 15.0");
	string a;
	int b;
	double c;
	vector <Product> token;
	while (ss >> a >> b >> c)
	{
		Product ex(a, b, c);
		token.push_back(ex);
	}
	cout << "--------NO DISCOUNT --------" << endl;
	/*	for (auto constIterator = token.cbegin();
			constIterator != token.cend(); ++constIterator)
		{
			cout << *constIterator << ' ';
		}*/
	for (int i = 0; i <= token.size(); i++)
	{
		cout << setw(10) << left << token[i].getDesc() << token[i].getQtty() << " * " << token[i].getPrice() << " = " << token[i].getQtty()*token[i].getPrice() << endl;
	}

	cout << "-----With 50% DISCOUNT for Banana------" << endl;
	for (int i = 0; i < token.size(); i++)
	{
		if (token[i].getDesc() == "Banana")
		{
			token[i].setPrice(token[i].getPrice()*0.5);
		}
	}

	for (int i = 0; i <= token.size(); i++)
	{
		cout << setw(10) << left << token[i].getDesc() << token[i].getQtty() << " * " << token[i].getPrice() << " = " << token[i].getQtty()*token[i].getPrice() << endl;
	}
}
