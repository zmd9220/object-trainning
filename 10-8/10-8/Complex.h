#pragma once

#include <string>

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	explicit Complex(double = 0.0, double = 0.0);
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	std::string toString() const;
private:
	double real;
	double imaginary;
};
#endif // !COMPLEX_H
