#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>


using namespace std;

class prize
{
public:
	
	bool yellow;
	int prizeget;
	prize()
	{
		yellow = false;
		prizeget = 0;
	}
};

prize table[1013];
int counts;
int prize_people;
bool prize_getpeople;
int make_key(int index)
{
	return index % 1013;
}
int make_key2(int index)
{
	return 37 - (index % 37);
}

void insert_and_search(int key, int key2, int index)
{
	if (table[key].prizeget == 5001)
	{
		if (table[key].yellow == true)
		{
			return;
		}
		else
		{
			table[key].yellow = true;
			prize_people = index;
			cout << 1000000 - (counts * 10000) << endl;
			prize_getpeople = true;
			return;
		}
	}

	if (table[key].yellow == false)
	{
		table[key].yellow = true;
		table[key].prizeget = index;
		return;
	}
	else
	{
		counts++;
		insert_and_search(((key + key2) % 1013), key2, index);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{	
		memset(table, 0, sizeof(table));
		prize_people = 0;
		prize_getpeople = false;
		int N, gets;
		cin >> N >> gets;
		table[gets].prizeget = 5001;
		for (int i = 0; i < N; i++)
		{
			int index;
			cin >> index;
			counts = 0;
			insert_and_search(make_key(index), make_key2(index), index);
		}
		if (prize_getpeople == false)
		{
			cout << "N" << endl;
		}
	}
	
}