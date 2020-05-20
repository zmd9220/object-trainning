#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <string.h>
using namespace std;

class node
{
public:
	int data;
	node* parent;
	//node* right;
	//node* left;
	node()
	{
		data = 0;
		parent = NULL;
		//right = NULL;
		//left = NULL;
	}
	node(int a)
	{
		data = a;
		parent = NULL;
		//right = NULL;
		//left = NULL;
	}
};

node* list[10001];

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		
		deque<int> a_list;
		deque<int> b_list;
		vector<int> answer;
		int N, K;
		memset(list, 0, sizeof(list));
		cin >> N >> K;
		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;
			if (list[a] == NULL)
			{
				node* ab = new node(a);
				list[a] = ab;
			}
			if (list[b] == NULL)
			{
				node* bs = new node(b);
				list[b] = bs;
			}
			list[b]->parent = list[a];
			/*if (list[a]->left == NULL)
			{
				list[a]->left = list[b];
			}
			else
			{
				list[a]->right = list[b];
			}*/
		}
		for (int i = 0; i < K; i++)
		{
			a_list.clear();
			b_list.clear();
			int a, b;
			cin >> a >> b;
			while (list[a] != NULL)
			{
				a_list.push_front(a);
				if (list[a]->parent == NULL)
					break;
				a = list[a]->parent->data;
			}
			while (list[b] != NULL)
			{
				b_list.push_front(b);
				if (list[b]->parent == NULL)
					break;
				b = list[b]->parent->data;
			}
			unsigned int idx = 0;
			while (a_list[idx] == b_list[idx])
			{
				idx++;
				if (idx == a_list.size() || idx == b_list.size())
					break;
			}
			answer.push_back(a_list[idx - 1]);
			
		}
		for (unsigned int i =0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}
		cout << endl;
	}
}