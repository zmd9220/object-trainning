#include <iostream>
#include "Distance.h"

using namespace std;

Distance::Distance(int a, int b, double c)
{
	miles = a;
	meter = b;
	centimeter = c;
}

void Distance::setDist(int a, int b, double c)
{
	miles = a;
	meter = b;
	centimeter = c;
}
void Distance::setMiles(int a)
{
	miles = a;
}

void Distance::setMeter(int b)
{
	meter = b;
}

void Distance::setCentimeter(double c)
{
	centimeter = c;
}

int Distance::getMiles()
{
	return miles;
}

int Distance::getMeter()
{
	return meter;
}

double Distance::getCentimeter()
{
	return centimeter;
}

Distance operator+(Distance a, Distance b) // a + b 의 거리
{
	Distance c(0, 0, 0);
	c.setMiles(a.getMiles() + b.getMiles());
	c.setMeter(a.getMeter() + b.getMeter());
	c.setCentimeter(a.getCentimeter() + b.getCentimeter());
	return c;
}
Distance operator-(Distance a, Distance b) // a - b 의 거리
{
	Distance c(0, 0, 0);
	c.setMiles(a.getMiles() - b.getMiles());
	c.setMeter(a.getMeter() - b.getMeter());
	c.setCentimeter(a.getCentimeter() - b.getCentimeter());
	return c;
}
bool operator==(Distance a, Distance b) // 모든 크기가 같을 경우
{
	if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() == b.getCentimeter())
		return 1;

	else
		return 0;
}
bool operator>(Distance a, Distance b) // a 가 큰 경우 => 마일부터 크거나 마일은 같은데 미터가 크거나 마일과 미터가 같은데 센티미터가 큰 경우만 참
{
	if (a.getMiles() > b.getMiles()) // 마일부터 클 경우
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() > b.getMeter()) //마일이 같고 미터가 큰 경우
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() > b.getCentimeter()) // 마일과 미터가 같고 센티미터가 큰 경우
		return 1;

	else
		return 0;
}
bool operator<(Distance a, Distance b) // a가 작은 경우 위의 경우와 반대
{
	if (a.getMiles() < b.getMiles()) // 마일부터 작을 경우
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() < b.getMeter()) //마일이 같고 미터가 작은 경우
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() < b.getCentimeter()) // 마일과 미터가 같고 센티미터가 작은 경우
		return 1;

	else
		return 0;
}
// '<'오퍼레이터는 더쉽게하려면 a>b가 0이면 true, 1이면 false로 반환하면됨