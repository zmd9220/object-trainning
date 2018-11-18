#include <iostream>
#include "Distance.h"
#include <string>

using namespace std;

string TnF(int t) // TRUE FALSE 값을 문자로 반환할 함수
{
	if (t == 1)
	{
		return "TRUE";
	}
	else
		return "FALSE";
}
int main()
{
	Distance a(1, 2, 4); Distance b(1, 1, 4);
	Distance c(0, 0, 0);
	int tnf = a == b;
	c = a + b;

	cout << "DISTANCE CALCULATOR" << endl << endl;
	
	cout << "Given : " << endl << "  Distance a<1,2,4>\n" << "  Distance b<1,1,4>\n\n";

	cout << "The sum of distance is        : " << c.getMiles() << " miles " << c.getMeter() << " meters " << c.getCentimeter() << " centimeters" << endl;

	c.setDist(0, 0, 0);
	c = a - b;

	cout << "The difference of distance is : " << c.getMiles() << " miles " << c.getMeter() << " meters " << c.getCentimeter() << " centimeters" << endl << endl;

	cout << "CONDITIONAL OPERATORS" << endl << endl;

	cout << "The statement distances a==b is : " << TnF(tnf) << endl;
	tnf = a > b;
	cout << "The statement distances a>b is  : " << TnF(tnf) << endl;
	tnf = a < b;
	cout << "The statement distances a<b is  : " << TnF(tnf) << endl;
}