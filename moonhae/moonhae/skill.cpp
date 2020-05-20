#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct pa
{
	int parent;
	bool parent_exist;
	pa()
	{
		parent = 0;
		parent_exist = false;
	}
};

vector<int> a_parent;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		
		cin >> N >> K;
		pa arr[10001];
		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[b].parent = a;
			arr[b].parent_exist = true;
		}
		for (int i = 0; i < K; i++)
		{
			int a, b;
			bool exist = false;
			cin >> a >> b;
			while (arr[a].parent_exist)
			{
				a_parent.push_back(a);
				a = arr[a].parent;
			}
			while (arr[b].parent_exist)
			{	
				for (int j = 0; j < a_parent.size(); j++)
				{
					if (b == a_parent[j])
					{
						exist = true;
						break;
					}
				}
				if (exist)
					break;
				b = arr[b].parent;
				
			}
			cout << b << endl;
			a_parent.clear();
		}
	}
}