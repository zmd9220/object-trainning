#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex(double realPart, double imainaryPart)
	: real{ realPart }, imaginary{imainaryPart}{}

Complex Complex::operator+(const Complex& operand2) const {
	return Complex{ real + operand2.real, imaginary + operand2.imaginary };

}

Complex Complex::operator-(const Complex& operand2) const {
	return Complex{ real - operand2.real, imaginary - operand2.imaginary };
}
string Complex::toString() const {
	return "("s + to_string(real) + ", "s + to_string(imaginary) + ")"s;
}