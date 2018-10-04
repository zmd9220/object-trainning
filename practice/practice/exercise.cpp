#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

int main() 
{
	point a(5, -5);
	point b(10, -8);
	point c(5, -8);
	point d(10, -11); //parallel data
	point result(0, 0);
	line l1 = line(&a, &b);
	line l2 = line(&c, &d);
	point slope1(0,0), slope2(0,0);
	result = a - b;
	slope1 = a / b;
	slope2 = c / d;
	cout << "Given points: " << endl;
	cout << "Point 1 : P" << a.getX() << "," << a.getY() << ")" << endl;
	cout << "Point 2 : P" << b.getX() << "," << b.getY() << ")" << endl;

}