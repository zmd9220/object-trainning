#include <iostream>
#include <iomanip>
using namespace std;


template<class T>
T sum(T x, T y) { T a = x + y; return a; }// for addition

template<class T>
T difference(T x, T y) 
{
	T a = x - y;
	return a;
}// for subtraction
template<class T>
T product(T x, T y) {
	T a = x * y;
	return a;
} // for multiplication
template<class T>
T quotient(T x, T y) {
	T a = x / y;
	return a;
} // for division
char enterChoice(void);

int main() {
	double x, y; // you change this to int or float to test.
	char choice;
	cout << "Input two values of same type " << endl;
	cin >> x >> y;
	while ((choice = enterChoice()) != 'e') {
		system("cls");
		switch (choice) {
		case 's': cout << "\n\tResult : " << x << " + " << y << " = " << sum(x, y) << endl; break;
		case 'd': cout << "\n\tResult : " << x << " - " << y << " = " << difference(x, y) << endl; break;
		case 'p': cout << "\n\tResult : " << x << " * " << y << " = " << product(x, y) << endl; break;
		case 'q': cout << "\n\tResult : " << x << " / " << y << " = " << quotient(x, y) << endl; break;
		default: cerr << "Incorrect choice" << endl; break;
		}
	}
}
	char enterChoice(void)
	{	
		cout << endl << setw(10) << "" << ":----------- Main Menu ------------:" << endl
			<< setw(10) << "" << ":                                  :" << endl
			<< setw(10) << "" << ":" << setw(4) << "" << "<S>um of any two numbers      :" << endl
			<< setw(10) << "" << ":" << setw(4) << "" << "<D>ifference of two numbers   :" << endl
			<< setw(10) << "" << ":" << setw(4) << "" << "<P>roduct of two numbers      :" << endl
			<< setw(10) << "" << ":" << setw(4) << "" << "<Q>uotient of two numbers     :" << endl
			<< setw(10) << "" << ":" << setw(4) << "" << "<e>nd                         :" << endl
			<< setw(10) << "" << ":                                  :" << endl
			<< setw(10) << "" << ":----------------------------------:" << endl
			<< setw(10) << "";
		char a;
		cin >> a;
		return a;
	}