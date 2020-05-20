#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

using namespace std;


class node
{
public:
	long long int data;
	node* parent;
	vector<node*> child;
	int name;
	node()
	{
		data = 1;
		name = 0;
		parent = NULL;
	}
	node(int a)
	{
		data = 1;
		name = a;
		parent = NULL;
	}
};

long long int gc[101];
node* nodes[101];
void preorder(node* a, long long int co)
{
	long long int new_count = co * a->data;
	if (a->child.size() == 0)
	{
		gc[a->name] = new_count;
	}
	else
	{
		for (int i = 0; i < a->child.size(); i++)
		{
			preorder(a->child[i], new_count);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		memset(nodes, 0, sizeof(nodes));
		memset(gc, 0, sizeof(gc));
		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (nodes[a] == NULL)
			{
				node* pa = new node(a);
				nodes[a] = pa;
			}
			if (nodes[b] == NULL)
			{
				node* chi = new node(b);
				nodes[b] = chi;
			}
			nodes[a]->child.push_back(nodes[b]);
			nodes[b]->parent = nodes[a];
			nodes[b]->data = c;
		}
		preorder(nodes[N], 1);
		for (int i = 0; i < 101; i++)
		{
			if (gc[i] != 0)
			{
				cout << i << " " << gc[i] << endl;
			}
		}
	}
}