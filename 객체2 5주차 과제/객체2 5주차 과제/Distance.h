#pragma once

#include <iostream>

#ifndef Distance_H
#define Distance_H

class Distance 
{
private:
	int miles;
	int meter;
	double centimeter;

public:
	Distance(int a = 0, int b = 0, double c = 0); // �Է� ���� �� ����Ʈ ��
	void setDist(int, int, double);
	void setMiles(int);
	void setMeter(int);
	void setCentimeter(double);
	int getMiles();
	int getMeter();
	double getCentimeter();



};
#endif // !Distance_H

Distance operator+(Distance a, Distance b); // a + b �� �Ÿ�

Distance operator-(Distance a, Distance b); // a - b �� �Ÿ�

bool operator==(Distance a, Distance b); // ��� ũ�Ⱑ ���� ���

bool operator>(Distance a, Distance b); // a �� ū ���

bool operator<(Distance a, Distance b); // a�� ���� ���
