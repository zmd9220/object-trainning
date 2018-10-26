#pragma once

#ifndef class_H
#define class_H

#include <string>
class Class 
{
private:
	int subject;
	std::string Section;
public:
	Class(int a, std::string c) :
		subject(a), Section(c) {}
	std::string getSection();
	int getSubject();
};

#endif // !class_H
