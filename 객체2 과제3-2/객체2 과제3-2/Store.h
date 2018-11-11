#pragma once

#ifndef STORE_H
#define STORE_H
#include <string>
class Store 
{
	std::string name;
	std::string location;
	std::string telno;
public:
	Store(std::string a, std::string b, std::string c) : name(a), location(b), telno(c) {} 
	void print(int);// this function will print the output below 
};
#endif // !STORE_H
