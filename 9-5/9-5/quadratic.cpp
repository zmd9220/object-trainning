#include <iostream>
#include "quadratic.h"
#include <cmath>
#include <sstream>
using namespace std;

quadratic::quadratic(double aa, double bb, double cc)
{	
	if (aa == 0)
	{
		a = 1;
	}
	else
	{
		a = aa;
	}
	b = bb;
	c = cc;
}

void quadratic::add(quadratic d)
{
	a += d.a;
	b += d.b;
	c += d.c;
}
void quadratic::subtract(quadratic d)
{
	a -= d.a;
	b -= d.b;
	c -= d.c;
}
double quadratic::solve()
{
	if ((pow(b, 2) - (4 * a * c)) > 0)
	{
		return (sqrt(pow(b, 2) - 4 * a * c)-b) / (2 * a);
	}
	else
		return 0;
		cout << "No Real Roots." << endl;
}


string quadratic::toString()
{	
	ostringstream output;
	output << a << "x^2+" << b << "x+" << c << "=0";
	return output.str();
}