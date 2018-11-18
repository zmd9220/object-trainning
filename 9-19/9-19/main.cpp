#include <iostream>
#include "date.h"
#include <ctime>
using namespace std;

int main()
{
	date a(2, 18, 1993);
	cout << a.toString3() << endl << a.toString() << endl << a.toString2() << endl;
	a.setCtime();
	cout << a.toString3() << endl << a.toString() << endl << a.toString2() << endl;
}