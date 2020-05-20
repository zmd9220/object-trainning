#include <vector>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{	
	stringstream ss("The Standard Library is a fundamental part of the C++ Standard. It provides C++ programmers with a comprehensive set of efficiently implemented tools and facilities that can be used for most types of applications.");
	
	char a;
	set<char> x;

	while (ss >> a)
	{
		x.insert(a);
	}

	for (auto constIterator = x.cbegin();
		constIterator != x.cend(); ++constIterator)
	{
		cout << *constIterator << ' ';
	}

	cout << endl;
}