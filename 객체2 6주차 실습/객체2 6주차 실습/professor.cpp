
#include <iostream>
#include "professor.h"
using namespace std;



professor::professor(int a, std::string b, std::string c, int d, double e) : inhaPerson(id = a, name = b, address = c)
{
	id = a;
	name = b;
	address = c;
	rank = d;
	salary = e;
}
void professor::displayProfile() // override the method to display course & classes
{
	cout << "----------Professor----------\n";
	inhaPerson::displayProfile();
	cout <<"Rank : " << rank
		<< endl << "Salary : " << salary << endl << "Classes taught : " << endl;
}
void professor::addClassTaken(Class* newClass)
{
	classesTaught.push_back(newClass);
}
void professor::promote(int newRank)
{
	rank = newRank;
}