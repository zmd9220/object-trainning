#include <iostream>
#include <sstream>
#include <vector>
#include "point.h"
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	stringstream ss("2 10 8 10 4 50 5 10 6 20 10 11 4 11 5 11 4 12 7 10 1 10");
	int a;
	int b;
	vector<Point> tokenOut;
	vector<Point> tokenIn;
	Circle c1(Point(4, 10), 2);

	while (ss >> a >> b)
	{	
		Point ex(a, b);
		if (sqrt(pow(ex.getX() - c1.getPoint().getX(), 2) + (pow(ex.getY() - c1.getPoint().getY(), 2))) > 2)
		{
			tokenOut.push_back(ex);
		}
		else
			tokenIn.push_back(ex);
	}

	cout << "Number of points inside the circle " << tokenIn.size() << "\nNumber of points outside the circle " << tokenOut.size() << endl << endl;
	
	cout << "Inside side points\n";
	for (int i = 0; i < tokenIn.size(); i++)
	{
		cout << setw(10) << left << tokenIn[i].getX() << tokenIn[i].getY() << endl;
	}
	cout << "Outside side points\n";
	for (int i = 0; i <= tokenIn.size(); i++)
	{
		cout << setw(10) << left << tokenOut[i].getX() << tokenOut[i].getY() << endl;
	}

}