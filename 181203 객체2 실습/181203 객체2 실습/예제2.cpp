#include <iostream>
#include "product.h"
#include <iomanip>
#include <array>
using namespace std;

template < class T >
void swap(T * element1Ptr, T * element2Ptr) 
{
	T temp;
	temp = element1Ptr;
	element1Ptr = element2Ptr;
	element2Ptr = temp;
}
template < class T >
void mySort(T * marray, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (marray[i] > marray[j])
			{
				swap(marray[i], marray[j]);
				//T temp;
				//temp = marray[j];
				//marray[j] = marray[i];
				//marray[i] = temp;
				i = i - 1;
				break;
			}
		}
	}
}
bool operator>(Product a, Product b) {
	if (a.getPrice() > b.getPrice())
	{
		return true;
	}
	else false;
}
void stringData();
void intData();
void doubleData();
void productData();
char enterChoice(void); //for the menu

int main()
{
	char choice;
	while ((choice = enterChoice()) != 'q') {
		system("cls");
		switch (choice) {
		case 's': stringData(); break;
		case 'i': intData(); break;
		case 'd': doubleData(); break;
		case 'p': productData(); break;
		default: cerr << "Incorrect choice" << endl; break;
		}
	}
	system("pause");
	return 0;
}

void stringData()
{
	//array<string,7> ex = { "China","Australia","Russia","Japan","Vietnam", "Korea" };
	string ex[6] = { "China","Australia","Russia","Japan","Vietnam", "Korea" };

	cout << "------------------- Unsorted --------------------" << endl;
	int space = (sizeof(ex) / sizeof(ex[0]));
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}
	cout << endl << "-------------------- Sorted ---------------------" << endl;
	mySort(ex, space);
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}

}
void intData()
{
	int ex[6] = { 5,4,3,3,2,1 };

	cout << "------------------- Unsorted --------------------" << endl;
	int space = (sizeof(ex) / sizeof(ex[0]));
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}
	cout << endl << "-------------------- Sorted ---------------------" << endl;
	mySort(ex, space);
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}
}
void doubleData()
{
	double ex[6] = { 5.5,4.25,10.1,3.6,2,1 };
	cout << "------------------- Unsorted --------------------" << endl;
	int space = (sizeof(ex) / sizeof(ex[0]));
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}
	cout << endl << "-------------------- Sorted ---------------------" << endl;
	mySort(ex, space);
	for (int i = 0; i < space; i++)
	{
		cout << ex[i] << " ";
	}
}
void productData()
{
	Product ex[6] = { (1,"ballpen",2.50),(2,"Book",12.5),(3,"pencil",10.4),(4,"eraser",3.5),(5,"paper",2.1),(5,"paper",2.1) };

	cout << "------------------- Unsorted --------------------" << endl << endl;
	int space = (sizeof(ex) / sizeof(ex[0]));
	for (int i = 0; i < space; i++)
	{
		cout << setprecision(2) << fixed << setw(5) << right << ex[i].getProdno() << setw(5) << "" << setw(15) << ex[i].getDesc() << setw(10)  <<ex[i].getPrice() << endl;
	}
	cout << endl << "-------------------- Sorted ---------------------" << endl;
	mySort(ex, space);
	for (int i = 0; i < space; i++)
	{
		cout << setw(5) << right << ex[i].getProdno() << setw(5) << "" << setw(15) << ex[i].getDesc() <<  setw(10) << ex[i].getPrice() << endl;
	}
}

char enterChoice(void)
{
	cout << endl << setw(10) << "" << ":----------- Main Menu ------------:" << endl
		<< setw(10) << "" << ":                                  :" << endl
		<< setw(10) << "" << ":" << setw(4) << "" << "Sort array of <i>nteger       :" << endl
		<< setw(10) << "" << ":" << setw(4) << "" << "Sort array of <d>ouble        :" << endl
		<< setw(10) << "" << ":" << setw(4) << "" << "Sort array of <s>tring        :" << endl
		<< setw(10) << "" << ":" << setw(4) << "" << "Sort array of <P>roduct object:" << endl
		<< setw(10) << "" << ":" << setw(4) << "" << "<Q>uit                        :" << endl
		<< setw(10) << "" << ":                                  :" << endl
		<< setw(10) << "" << ":----------------------------------:" << endl
		<< setw(10) << "";
	char a;
	cin >> a;
	return a;
}