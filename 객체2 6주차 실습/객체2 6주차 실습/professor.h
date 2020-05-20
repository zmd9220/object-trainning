#pragma once

#ifndef professor_H
#define professor_H
#include "inha personh.h"
#include "Class.h"
#include <vector>
#include <string>
class professor : public inhaPerson
{
private:
	int rank;
	double salary;
	std::vector<Class*> classesTaught;
public:
	professor(int, std::string, std::string, int, double);
	void displayProfile() override; // override the method to display course & classes
	void addClassTaken(Class* newClass);
	void promote(int newRank);
};
#endif // !professor_H
