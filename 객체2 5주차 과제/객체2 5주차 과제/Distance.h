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
	Distance(int a = 0, int b = 0, double c = 0); // 입력 없을 때 디폴트 값
	void setDist(int, int, double);
	void setMiles(int);
	void setMeter(int);
	void setCentimeter(double);
	int getMiles();
	int getMeter();
	double getCentimeter();



};
#endif // !Distance_H

Distance operator+(Distance a, Distance b); // a + b 의 거리

Distance operator-(Distance a, Distance b); // a - b 의 거리

bool operator==(Distance a, Distance b); // 모든 크기가 같을 경우

bool operator>(Distance a, Distance b); // a 가 큰 경우

bool operator<(Distance a, Distance b); // a가 작은 경우
