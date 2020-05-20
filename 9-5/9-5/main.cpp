#include <iostream>
#include "quadratic.h"
#include <string>
#include <cmath>
using namespace std;

int main()
{
	quadratic a(3, 7, 1);
	quadratic c(2, 1, 3);
	a.add(c);
	cout << a.toString() << endl;
	a.subtract(c);
	cout << a.toString() << endl;
	cout << a.solve() << endl;
}