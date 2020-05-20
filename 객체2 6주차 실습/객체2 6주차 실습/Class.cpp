#include <iostream>
#include "Class.h"
using namespace std;


/*Class::Class(int d, std::string b)
{
	subject = d;
	Section = b;
}*/
		
string Class::getSection()
{
	return Section;
}
int Class::getSubject()
{
	return subject;
}