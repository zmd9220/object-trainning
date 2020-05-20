#include <iostream>
#inlcude "time.h"
using namespace std;

int main()
{
	Time t1;
	Time t2(12, 25, 42);
	cout << "Constructed with:\n\nt1: all arguments defaulted\n ";
	t1.printUniversal(); // 00:00:00
	cout << "\n ";
	t1.printStandard(); // 12:00:00 AM
	cout << "\n\nt4: hour, minute and second specified\n ";
	t2.printUniversal(); // 12:25:42
	cout << "\n ";
	t2.printStandard(); // 12:25:42 PM
	try
	{
		Time t3(27, 74, 99);
	}
	catch (exception &e) {
		cerr << "\n\nException while initializing t3: " << e.what() << endl;
	}
}