#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class makeMoney
{
private:
	int price;
	string prodName;
	int ID;
public:
	makeMoney::makeMoney(int ID = 0, string prodName = "", int price = 0) {};
	int getPrice()
	{
		return price;
	}
	string getProdName()
	{
		return prodName;
	}
	int getID()
	{
		return ID;
	}
	void setPrice(int pri)
	{
		price = pri;
	}
	void setProdName(string ab)
	{
		prodName = ab;
	}
	void setID(int set)
	{
		ID = set;
	}
};

int getRequest()
{
	cout << "Enter Request" << endl
		<< " 1 - Enter a new Item to store\n"
		<< " 2 - List items of the store\n"
		<< " 3 - Enter a new sale <Purchase>\n"
		<< " 4 - List sales <Purchases>\n"
		<< " 5 - End of run\n? ";
	int requests;
	cin >> requests;
	return requests;
}// get user’s request
void new_item() // create new recorde to item file (Writing to item file)
{	
	fstream itemIO{ "item.txt", ios::out | ios::app };
	fstream itemIO2{ "item.txt", ios::in };
	if (!itemIO)
	{
		cerr << "itemIO is not opened" << endl;
	}

	string b;
	int a, c;
	cout << "Enter item ID:  ";
	cin >> a;
	cout << "\nEnter item Name:  ";
	cin.get();
	getline(cin, b);
	cout << "\nEnter item Price:  ";
	cin >> c;
	

	/*makeMoney mm;
	int seek = 1;
	while (1) 
	{	
		
		itemIO2.seekg((seek-1) * sizeof(makeMoney));
		itemIO2.read(reinterpret_cast<char*>(&mm), sizeof(makeMoney));
		if (mm.getID() == 0)
		{	
			mm.setID(a);
			mm.setPrice(c);
			mm.setProdName(b);
			itemIO.seekp((seek-1) * sizeof(makeMoney));
			itemIO.write(reinterpret_cast<const char*>(&mm), sizeof(makeMoney));
			break;
		}
		++seek;
	}*/
	
	 
	itemIO << a << " " << b << " " << c << endl;


}
void new_sale() // create new recorde to sale file (Writing to sale file)
{
	string a;
	int b, c;
	cout << "Enter buyer's Name:  ";
	cin.get();
	getline(cin, a);
	cout << "\nEnter Item Number:  ";
	cin >> b;
	cout << "\nEnter Quantity:  ";
	cin >> c;

	ofstream salesIO{ "sales.txt", ios::app };

	salesIO << setw(30) << a << setw(30) << b << setw(30) << c;
}
void display_items() // Display items from file (Reading from item file )
{
	ifstream itemI{ "item.txt", ios::in };

}
void display_sales() // Display sales from file (Reading from sale file)
{

}
//bool search(string) // search if a specific item exist in item file
//{

//}
string found_item[] = { "","","" };// global variable for searching item
enum RequestType { NEW_ITEM = 1, SHOW_ITEMS, NEW_SALE, SHOW_SALES, END }; // 1,2,3,4,5 자동지정(enum)

int main() {
	// get user's request (e.g., zero, credit or debit balance)
	//fstream itemIO{ "item.txt", ios::in | ios::out };
	fstream salesIO{ "sales.txt", ios::in | ios::out };
	int request = getRequest();
	// process user's request
	while (request != END) {
		switch (request) {
		case NEW_ITEM:
			cout << "\n Entering a new Item to store:\n";
			new_item();
			break;
		case SHOW_ITEMS:
			cout << "\n List items of the store:\n";
			display_items();
			break;
		case NEW_SALE:
			cout << "\nEnter a new sale (Purchase):\n";
			new_sale();
			break;
		case SHOW_SALES:
			cout << "\n List sales (Purchases):\n";
			display_sales();
			break;
		} // end switch
		request = getRequest(); // get additional request from user
	}
	system("pause");
	return(0);
}
//16진수 보는 프로그램? 패킷?프로그램?