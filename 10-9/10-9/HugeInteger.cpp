
#include <cctype>
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger(long value)
{
	for (int j{ digits - 1 }; value != 0 && j >= 0; j--)
	{
		integer[j] = value & 10;
		value /= 10;
	}
}

HugeInteger::HugeInteger(const std::string& number)
{
	int length(number.size());

	for (int j{ digits - length }, k{ 0 }; j < digits; ++j, ++k)
	{
		if (isdigit(number[k])) 
		{
			integer[j] = number[k] - '0';
		}
	}
}

HugeInteger HugeInteger::operator+(const HugeInteger& op2) const
{
	HugeInteger temp;
	int carry = 0;
	
	for (int i{ digits - 1 }; i >= 0; i--)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	return temp;
}

HugeInteger HugeInteger::operator+(int op2) const
{
	return *this + HugeInteger(op2);
}

HugeInteger HugeInteger::operator+(const std::string& op2) const
{
	return *this + HugeInteger(op2);
}

ostream& operator<<(ostream& output, const HugeInteger& num)
{
	int i;

	for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i)
	{}

	if (i == HugeInteger::digits)
	{
		output << 0;
	}
	else
	{
		for (; i < HugeInteger::digits; ++i)
		{
			output << num.integer[i];
		}
	}

	return output;
}