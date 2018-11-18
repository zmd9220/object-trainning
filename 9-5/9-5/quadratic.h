#pragma once

#ifndef quadratic_H
#define quadratic_H
#include <string>
class quadratic
{
public:
	quadratic(double a = 1, double b = 0, double c = 0);
	void add(quadratic);
	void subtract(quadratic);
	double solve();
	std::string toString();
private:
	double a, b, c;
};
#endif // !quadratic_H
