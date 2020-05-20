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

Distance operator+(Distance a, Distance b) // a + b �� �Ÿ�
{
	Distance c(0, 0, 0);
	c.setMiles(a.getMiles() + b.getMiles());
	c.setMeter(a.getMeter() + b.getMeter());
	c.setCentimeter(a.getCentimeter() + b.getCentimeter());
	return c;
}
Distance operator-(Distance a, Distance b) // a - b �� �Ÿ�
{
	Distance c(0, 0, 0);
	c.setMiles(a.getMiles() - b.getMiles());
	c.setMeter(a.getMeter() - b.getMeter());
	c.setCentimeter(a.getCentimeter() - b.getCentimeter());
	return c;
}
bool operator==(Distance a, Distance b) // ��� ũ�Ⱑ ���� ���
{
	if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() == b.getCentimeter())
		return 1;

	else
		return 0;
}
bool operator>(Distance a, Distance b) // a �� ū ��� => ���Ϻ��� ũ�ų� ������ ������ ���Ͱ� ũ�ų� ���ϰ� ���Ͱ� ������ ��Ƽ���Ͱ� ū ��츸 ��
{
	if (a.getMiles() > b.getMiles()) // ���Ϻ��� Ŭ ���
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() > b.getMeter()) //������ ���� ���Ͱ� ū ���
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() > b.getCentimeter()) // ���ϰ� ���Ͱ� ���� ��Ƽ���Ͱ� ū ���
		return 1;

	else
		return 0;
}
bool operator<(Distance a, Distance b) // a�� ���� ��� ���� ���� �ݴ�
{
	if (a.getMiles() < b.getMiles()) // ���Ϻ��� ���� ���
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() < b.getMeter()) //������ ���� ���Ͱ� ���� ���
		return 1;

	else if (a.getMiles() == b.getMiles() && a.getMeter() == b.getMeter() && a.getCentimeter() < b.getCentimeter()) // ���ϰ� ���Ͱ� ���� ��Ƽ���Ͱ� ���� ���
		return 1;

	else
		return 0;
}
// '<'���۷����ʹ� �������Ϸ��� a>b�� 0�̸� true, 1�̸� false�� ��ȯ�ϸ��