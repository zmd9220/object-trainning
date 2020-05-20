#include <iostream>
#include "Point.h"
#include <string>
#include <cmath>
using namespace std;
//ostream  입출력시 바이트 스트림을 사용하는(iostream) 연산자를 오퍼레이트 할때 사용 주소 문자열을 그대로읽기위해
//friend 사용이유 다른 클래스에서도 사용하기 위해 friend 사용 클래스 내부만 사용하면 friend 안써도됨

//바이트 스트림에 자동으로 들어간것을 자신의 의도에 맞게 입력되서 출력됨?????
point::point(int a, int b) 
{
	x = a;
	y = b;
}
void point::setX(int a) 
{
	x = a;
}
void point::setY(int b)
{
	y = b;
}
int point::getX() 
{
	return x;
}
int point::getY()
{
	return y;
}


point operator+(point a, point b) 
{
	point res(0, 0);
	res.setX(a.getX() + b.getX());
	res.setY(a.getY() + b.getY());
	return res;

}
point operator-(point a, point b)
{

	point res(0, 0);
	res.setX(a.getX() - b.getX());
	res.setY(a.getY() - b.getY());
	return res;

}
point operator*(point a, point b) 
{
	point res(0, 0);
	res.setX(a.getX() * b.getX());
	res.setY(a.getY() * b.getY());
	return res;
}
point operator/(point a, point b) 
{
	point res(0, 0);
	res.setX(a.getX() / b.getX());
	res.setY(a.getY() / b.getY());
	return res;
}



line::line(point* a, point* b) //생성자
{
	*p1 = *a;
	*p2 = *b;
}
void line::setLine(point* a, point* b) 
{
	*p1 = *a;
	*p2 = *b;
}
double line::slope()
{
	point mul = *p2 - *p1;

	return (mul.getY() / mul.getX());
}
string line::inclined() //기울기가 양수면 우측 + 음수면 - 왼쪽
{
	if (line::slope() > 0)
	{
		cout << "right" << endl;
	}
	else
		cout << "left" << endl;
}
double line::distance()
{

	point mul = *p2 - *p1;
	//return sqrt((mul.getY() * mul.getY()) + (mul.getX() * mul.getX()));
	return sqrt(double(pow(mul.getX(), 2)) + double(pow(mul.getY(), 2)));
}
bool line::parallel(line *l) // 평행인지 여부
{
	if (slope() == *l.slope())
	{
		return 1;
		cout << "YES" <<endl;
	}
	else 
	{
		return 0;
		cout << "NO" << endl;
	}
		
}
bool line::intersection(line *l)// 평행도 아니고 수직도 아니면 보통
{
	if (parallel(*l) == 1 || perpendicular(*l) == 1)
	{
		cout << "NO" << endl;
	}
	else
		cout << "YES" << endl;
}
bool line::perpendicular(line *l) //수직일때
{
	if (-1 / line::slope()* *l.slope() == line::slope())
	{
		return 1;
		cout << "YES" << endl;
	}
	else 
	{
		return 0;
		cout << "NO" << endl;
	}
}

/*
간단한 사칙연산 
비교연산자도 사칙연산 연산자와 같이 오퍼레이터 쓰면 됨
*/