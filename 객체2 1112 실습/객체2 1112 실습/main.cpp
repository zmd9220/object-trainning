#include <iostream>
#include "bookData.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/**/
void outputLine(ostream&, const BookData &a) // for output
{
	cout << setw(15) << left << a.getProductNumber() << setw(35) << left << a.getProductName() << setw(15) << left << a.getQuantity()
		<< setw(15) << right << a.getPrice() << setw(15) << right << a.getPrice()*a.getQuantity() << endl;

}
char enterChoice(void); // choose selection
void showRecords(fstream&) //show record on screen
{
	cout << setw(15) << left << "BkNum" << setw(35) << left << "Prod Name" << setw(15) << left << "Quantity"
		<< setw(15) << right << "Price" << setw(15) << right << "Total"
		<< endl << "---------------------------------------------------------------------------------------------------------";
	fstream inBook("book.dat", ios:: out | ios::in | ios::binary);
	//iostream 변수 파일을 읽고?
	inBook.seekg(0); //input
	BookData book;

	inBook.read(reinterpret_cast<char *>(&book), sizeof(BookData));

	double total = 0;

	while (inBook && !inBook.eof())
	{
		if (book.getProductNumber() != 0)
		{
			outputLine(cout, book);
			total = book.getPrice()*book.getQuantity() + total;
		}
		inBook.read(reinterpret_cast<char*>(&book), sizeof(BookData));

	}

	cout << "\n\t\t Total Amount  \t: " << total << endl;

	//updateFile.seekp((prodno - 1) * sizeof(BookData)); //output??
	
}
void updateRecord(fstream&) //update a book
{
	cout << setw(40) << setfill('-') << right << "EDIT " << setw(40) << left << "RECORD" << endl << endl
		<< "Enter prodno number to edit : ";
	int c;
	cin >> c;
	cout << endl << setw(20) << setfill(' ') << left << "ProdNo" << setw(20) << right << "Prod Name" << setw(20) << left << "  Quantity" << setw(20) << left << "Price" << endl;
	fstream inBook("book.dat", ios::out | ios::in | ios::binary);
	//iostream 변수 파일을 읽고?
	inBook.seekg(c); //input
	BookData book;

	inBook.read(reinterpret_cast<char *>(&book), sizeof(BookData));
	outputLine(cout, book);

	cout << "Enter New productName, New quantity, New price\n? ";
	string pro;
	int quan;
	double pri;
	cin >> pro >> quan >> pri;
	book.setProductName(pro);
	book.setQuantity(quan);
	book.setPrice(pri);

	inBook.write(reinterpret_cast<const char*>(&book), sizeof(BookData));
}
void newRecord(fstream&) // add a new book
{

}
void deleteRecord(fstream&) //delete an book record
{

}
void buildFile() // build a file
{

}
void SellBuy(fstream&) // purchase and sell
{	
	cout << "---------------  BUY AND SELL ---------------\n\n";
	cout << "Enter prodno number : ";
	int x;
	cin >> x;
	//while (inClientFile >> )

}

/*void buildFile()
{
	system("cls");
	int x;
	cout << "\n---------------BUILD THE FILE---------------" << endl;
	cout << "\nEnter number of records :";
	cin >> x;

	ofstream outCredit1("book.dat", ios::out | ios::binary);

	if (!outCredit1)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	BookData blankbook;

	for (int i = 0; i < x; ++i)
	{
		outCredit1.write(reinterpret_cast<const char*>(&blankbook), sizeof(BookData));
	}

	outCredit1.close();

}*/
int main()
{	
	while (1) 
	{
		cout << setw(40) << setfill('-') << right << "---------------Main " << setw(40) << left << "Menu---------------" << endl;
		cout << setw(40) << setfill(' ') << left << ":" << setw(40) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<S>how records on screen" << setw(10) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<U>pdate a Book" << setw(10) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<A>dd a new Book" << setw(10) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<D>elete an Book record" << setw(10) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<B>uild a File" << setw(10) << right << ":" << endl;
		cout << setw(10) << left << ":" << setw(60) << left << "<Q>uit" << setw(10) << right << ":" << endl;
		cout << setw(40) << left << ":" << setw(40) << right << ":" << endl;
		cout << setw(40) << setfill('-') << "-" << setw(40) << left << "-" << endl;

		char a[7] = { 's','u','a','d','b','q' };
		char b;
		cin >> b;
		switch (b)
		{
		case 's':
			showRecords();
			break;
		case 'u':
			updateRecord();
			break;
		case 'a':
			newRecord();
			break;
		case 'd':
			deleteRecord();
			break;
		case 'p':
			SellBuy();
			break;
		case 'b':
			buildFile();
			break;
		case 'q':
			break;
		}
		
		if (b == 'q')
			break;

	}
	


}

