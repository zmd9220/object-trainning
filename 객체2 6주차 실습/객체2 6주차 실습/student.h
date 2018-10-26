#pragma once


#ifndef student_H
#define student_H
#include <vector>
#include "inha personh.h"
#include "Class.h"
class Student : public inhaPerson
{
private:
	int course;
	int year; // 1 = freshman, 2 = sophomore, etc.
	std::vector<Class*> classesTaken;
public:
	Student(int, std::string, std::string, int, int);
	void displayProfile() override; // override the method to display course & classes
	void addClassTaken(Class* newClass);
	void changeCourse(int newCourse);
};

#endif // !student_H
