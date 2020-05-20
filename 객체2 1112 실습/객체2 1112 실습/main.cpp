#include <iostream>
#include "bookData.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void outputLine(ostream&, const BookData &a) // for output
{
	cout << setw(15) << left << a.getProductNumber() << setw(35) << left << a.getProductName() << setw(15) << left << a.getQuantity()
		<< setw(15) << right << a.getPrice() << setw(15) << right << a.getPrice()*a.getQuantity() << endl;

}
char enterChoice(void)
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
	cout << setw(40) << setfill('-') << "-" << setw(40) << left << "-" << setfill(' ') << endl;

	char choice;
	cin >> choice;
	return choice;
}// choose selection
void showRecords(fstream& inBook) //show record on screen ok
{
	cout << setw(15) << left << "BkNum" << setw(35) << left << "Prod Name" << setw(15) << left << "Quantity"
		<< setw(15) << right << "Price" << setw(15) << right << "Total"
		<< endl << "---------------------------------------------------------------------------------------------------------";
	//fstream inBook("book.dat", ios:: out | ios::in | ios::binary);
	//iostream 변수 파일을 읽고?
	inBook.seekg(0); //input
	BookData book;

	inBook.read(reinterpret_cast<char *>(&book), sizeof(BookData));

	double total = 0;

	while (inBook && !inBook.eof()) //
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
void updateRecord(fstream& updateFile) //update a book ok
{
	cout << setw(40) << setfill('-') << right << "EDIT " << setw(40) << left << "RECORD" << endl << endl
		<< "Enter prodno number to edit : ";
	int c;
	cin >> c;
	cout << endl << setw(20) << setfill(' ') << left << "ProdNo" << setw(20) << right << "Prod Name" << setw(20) << left << "  Quantity" << setw(20) << left << "Price" << endl;
	//fstream inBook("book.dat", ios::out | ios::in );
	//iostream 변수 파일을 읽고?
	updateFile.seekg(c - 1 * sizeof(BookData)); //input
	BookData book;

	updateFile.read(reinterpret_cast<char *>(&book), sizeof(BookData));
	if (book.getProductNumber() != 0) {
		outputLine(cout, book);

		cout << "Enter New productName, New quantity, New price\n? ";
		string pro;
		int quan;
		double pri;
		cin >> pro >> quan >> pri;
		book.setProductName(pro);
		book.setQuantity(quan);
		book.setPrice(pri);
		outputLine(cout, book);
		updateFile.seekp(c - 1 * sizeof(BookData));
		updateFile.write(reinterpret_cast<const char*>(&book), sizeof(BookData));
		cout << "Product #" << book.getProductNumber() << "Updated.\n";
	}
	else
	{
		cerr << "Product #" << c << " has no information." << endl;
	}

}
void newRecord(fstream& insertInFile) // add a new book
{

	while (1) {
		cout << "Enter prodno number <1 to 100, 0 to end input>\n? ";
		int c;
		cin >> c;
		if (c == 0)
			break;
		
		//fstream insertInFile;//("book.txt", ios::out);
		//insertInFile.open("book.txt", ios::out | ios::in);
		//iostream 변수 파일을 읽고?
		insertInFile.seekg(c - 1 * sizeof(BookData)); //input
		

		BookData book;


		insertInFile.read(reinterpret_cast<char*>(&book), sizeof(BookData));
		if (book.getProductNumber() == 0) 
		{
			cout << "Enter New productName, New quantity, New price\n? ";
			string pro;
			int quan;
			double pri;
			cin >> pro >> quan >> pri;
			book.setProductName(pro);
			book.setQuantity(quan);
			book.setPrice(pri);
			book.setProductNumber(c);
			outputLine(cout, book);
			insertInFile.seekp(c - 1 * sizeof(BookData));

			insertInFile.write(reinterpret_cast<const char*>(&book), sizeof(BookData));
		}
		else
		{
			cerr << "Prodno# already Exist" << endl;
		}
	
	}

	
}
void deleteRecord(fstream& inBook) //delete an book record
{
	cout << setw(40) << setfill('-') << right << "DELETE " << setw(40) << left << "RECORD" << endl << endl
		<< "Enter prodno number to edit : ";
	int c;
	cin >> c;
	cout << endl << setw(20) << setfill(' ') << left << "ProdNo" << setw(20) << right << "Prod Name" << setw(20) << left << "  Quantity" << setw(20) << left << "Price" << endl;
	//fstream inBook("book.dat", ios::out | ios::in | ios::binary);
	//iostream 변수 파일을 읽고?
	inBook.seekg(c - 1 * sizeof(BookData)); //input
	BookData book;

	inBook.read(reinterpret_cast<char *>(&book), sizeof(BookData));
	if (book.getProductNumber() != 0) {
		outputLine(cout, book);
		BookData blankBook;
		inBook.seekp(c - 1 * sizeof(BookData));
		inBook.write(reinterpret_cast<const char*>(&blankBook), sizeof(BookData));
	}
	else
	{
		cerr << "Product #" << c << " is empty." << endl;
	}


}
/*void buildFile() // build a file
{

}*/
void SellBuy(fstream& inBook) // purchase and sell
{	
	cout << "---------------  BUY AND SELL ---------------\n\n";
	cout << "Enter prodno number : ";
	//while (inClientFile >> )
	int c;
	cin >> c;
	cout << endl << setw(20) << setfill(' ') << left << "ProdNo" << setw(20) << right << "Prod Name" << setw(20) << left << "  Quantity" << setw(20) << left << "Price" << endl;
	//fstream inBook("book.dat", ios::out | ios::in | ios::binary);
	//iostream 변수 파일을 읽고?
	inBook.seekg(c - 1 * sizeof(BookData)); //input
	BookData book;

	inBook.read(reinterpret_cast<char *>(&book), sizeof(BookData));
	if (book.getProductNumber() != 0) {
		outputLine(cout, book);

		cout << "Enter Quantity <-> Sell or <+> Buy\n? ";
		int y = book.getQuantity();
		int x;
		cin >> x;
		book.setQuantity(y + x);
		inBook.seekp(c - 1 * sizeof(BookData));
		inBook.write(reinterpret_cast<char *>(&book), sizeof(BookData));
		cout << "Product #" << book.getProductNumber() << "Updated.\n";
	}
	else
	{
		cerr << "Product #" << c << "has no information." << endl;
	}

	inBook.close();

}

void buildFile()
{
	//system("cls");
	int x;
	cout << "\n---------------BUILD THE FILE---------------" << endl;
	cout << "\nEnter number of records :";
	cin >> x;

	ofstream outCredit1("book.txt", ios::out );

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

}
int main()
{	
	fstream inOutRecord{ "book.txt", ios::in | ios::out | ios::binary };
	if (!inOutRecord)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	char b;
	while ((b = enterChoice()) != 'q')
	{
		switch (b)
		{
		case 's':
			showRecords(inOutRecord);
			break;
		case 'u':
			updateRecord(inOutRecord);
			break;
		case 'a':
			newRecord(inOutRecord);
			break;
		case 'd':
			deleteRecord(inOutRecord);
			break;
		case 'p':
			SellBuy(inOutRecord);
			break;
		case 'b':
			buildFile();
			break;
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}
		inOutRecord.clear();
	}
	


}

