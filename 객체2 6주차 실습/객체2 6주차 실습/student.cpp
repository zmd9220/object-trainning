#include <iostream>
#include "student.h"

using namespace std;


Student::Student(int a , std::string b, std::string c, int d, int e) : inhaPerson(id=a,name=b,address=c)
{
	course = d;
	year = e;
}
void Student::displayProfile()  // override the method to display course & classes 
{
	cout << "----------Student---------\n";
	inhaPerson::displayProfile();
	cout << "Course : " << course << endl << "Year : " << year
		<< endl << "Classes taken : \n";
}
void Student::addClassTaken(Class* newClass)
{
	classesTaken.push_back(newClass);
}
void Student::changeCourse(int newCourse)
{
	course = newCourse;
}