#include <iostream>
#include "Point.h"
#include <string>
#include <cmath>
using namespace std;
//ostream  ����½� ����Ʈ ��Ʈ���� ����ϴ�(iostream) �����ڸ� ���۷���Ʈ �Ҷ� ��� �ּ� ���ڿ��� �״���б�����
//friend ������� �ٸ� Ŭ���������� ����ϱ� ���� friend ��� Ŭ���� ���θ� ����ϸ� friend �Ƚᵵ��

//����Ʈ ��Ʈ���� �ڵ����� ������ �ڽ��� �ǵ��� �°� �ԷµǼ� ��µ�?????
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



line::line(point* a, point* b) //������
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
string line::inclined() //���Ⱑ ����� ���� + ������ - ����
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
bool line::parallel(line *l) // �������� ����
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
bool line::intersection(line *l)// ���൵ �ƴϰ� ������ �ƴϸ� ����
{
	if (parallel(*l) == 1 || perpendicular(*l) == 1)
	{
		cout << "NO" << endl;
	}
	else
		cout << "YES" << endl;
}
bool line::perpendicular(line *l) //�����϶�
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
������ ��Ģ���� 
�񱳿����ڵ� ��Ģ���� �����ڿ� ���� ���۷����� ���� ��
*/