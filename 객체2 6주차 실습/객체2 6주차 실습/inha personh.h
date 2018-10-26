#pragma once

#ifndef INHA_H
#define INHA_H
#include <string>
class inhaPerson
{
protected:
	int id;
	std::string name;
	std::string address;
public: //virtual function for polymorphic effect
	inhaPerson(int id, std::string, std::string);
	virtual void displayProfile();
	void changeAddress(std::string);

};
#endif // !INHA_H
