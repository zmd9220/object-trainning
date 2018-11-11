#pragma once
#ifndef HugeInteger_H
#define HugeInteger_H

#include <array>
#include <iostream>
#include <string>

class HugeInteger {
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
public:
	static const int digits{ 40 };

	HugeInteger(long = 0);
	HugeInteger(const std::string&);

	HugeInteger operator+(const HugeInteger&) const;
	
	HugeInteger operator+(int) const;
	HugeInteger operator*(const HugeInteger&) const;
	bool operator==(const HugeInteger&) const;
	HugeInteger operator+(const std::string&) const;

private:
	std::array<short, digits> integer{};
};

#endif // !HugeInteger_H
