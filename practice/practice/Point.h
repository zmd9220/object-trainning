#pragma once

#include <iostream>
#include <string>

#ifndef point_H
#define point_H
class point 
{
private:
	int x, y;

public:
	point(int, int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};
#endif // !point_H

point operator+(point a, point b); //��Ģ������ ���� ostream ���� �ʿ� x
point operator-(point a, point b);
point operator*(point a, point b);
point operator/(point a, point b);

#ifndef Line_H
#define Line_H
class line 
{
private:
	point *p1, *p2;

public:
	line(point*, point*); //������ xy�� ���� ������ ���� ��
	void setLine(point*, point*);
	double slope();
	std::string inclined();
	double distance();
	bool parallel(line *);
	bool intersection(line *);
	bool perpendicular(line *);
	
};
#endif // !Line_H

