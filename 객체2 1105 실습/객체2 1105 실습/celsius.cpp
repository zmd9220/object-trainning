#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << setw(30) << "Fahrenheit" << setw(30) << "Celsius" << endl;
	for (int i = 0; i <= 212; i++) 
	{
		cout << setw(30) << i << setw(30) << fixed << setprecision(3) << setiosflags(ios::showpos|ios::showpoint) << 5.0 / 9.0*(i - 32) << endl;
	}
}
//unsetf (ios::showpos)그줄만 선택해서 표현하게 가능
//ios::left ios::internal 과같은 정렬기능도 가능
// ios::width setw() 공간여백 만들기