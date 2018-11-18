#include <iostream>
#include <fstream>
#include "bookData.h"
#include <iomanip>
using namespace std;
void outputLine(ostream&, const BookData &a) // for output
{
	cout << setw(15) << left << a.getProductNumber() << setw(35) << left << a.getProductName() << setw(15) << left << a.getQuantity()
		<< setw(15) << right << a.getPrice() << setw(15) << right << a.getPrice()*a.getQuantity() << endl;

}
int main()
{
	while (1) {
		cout << "Enter prodno number <1 to 100, 0 to end input>\n? ";
		int c;
		cin >> c;
		if (c == 0)
			break;

		fstream inBook("book2.txt", ios::in);

		//iostream 변수 파일을 읽고?
		inBook.seekg(c - 1 * sizeof(BookData)); //input

		BookData books;


		inBook.read(reinterpret_cast<char *>(&books), sizeof(BookData));
		if (books.getProductNumber() == 0) {
			cout << "Enter New productName, New quantity, New price\n? ";
			string pro;
			int quan;
			double pri;
			cin >> pro >> quan >> pri;
			books.setProductName(pro);
			books.setQuantity(quan);
			books.setPrice(pri);
			books.setProductNumber(c);
			inBook.seekg(c - 1 * sizeof(BookData));

			inBook.write(reinterpret_cast<const char*>(&books), sizeof(BookData));
		}
		else
		{
			cerr << "Prodno# already Exist" << endl;
		}
		inBook.close();
	}

	cout << setw(15) << left << "BkNum" << setw(35) << left << "Prod Name" << setw(15) << left << "Quantity"
		<< setw(15) << right << "Price" << setw(15) << right << "Total"
		<< endl << "---------------------------------------------------------------------------------------------------------";
	fstream inBooks("book2.txt", ios::out | ios::in);
	//iostream 변수 파일을 읽고?
	inBooks.seekg(0); //input
	BookData book;

	inBooks.read(reinterpret_cast<char *>(&book), sizeof(BookData));

	double total = 0;

	while (inBooks && !inBooks.eof())
	{
		if (book.getProductNumber() != 0)
		{
			outputLine(cout, book);
			total = book.getPrice()*book.getQuantity() + total;
		}
		inBooks.read(reinterpret_cast<char*>(&book), sizeof(BookData));

	}
}