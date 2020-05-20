#include <iostream>
#include "Myfather.h"

using namespace std;

int main()
{	
	char* a = "Brown";
	char* h = "Bald";

	MyFather F1(a,h,100000,4);

	char* b = "Blue";
	char* c = "Culry Blonde";
	
	MyMother F2(b, c, 3);

	char* d = "Straight Black";
	char* e = "Post Graduate";

	

	char* f = "Black";
	
	MySister F4(f, 1000, F1, F2);

	MySelf F3(d, e, F1);
}