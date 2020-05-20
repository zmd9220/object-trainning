#include <iostream>
#include "inha personh.h"

using namespace std;

inhaPerson::inhaPerson(int ids, std::string a, std::string b)
{
	id = ids;
	name = a;
	address = b;
}
void inhaPerson::displayProfile()
{
	cout << "Name : " << name << endl << "ID : " << id << endl
		<< "Address : " << address << endl;
}
void inhaPerson::changeAddress(std::string b)
{
	address = b;
}