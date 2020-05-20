#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
	int data;
	node* parent;
	node* right;
	node* left;
	
	node()
	{
		data = NULL;
		parent = NULL;
		right = NULL;
		left = NULL;
	}
	node(int a)
	{
		data = a;
		parent = NULL;
		right = NULL;
		left = NULL;
	}

	void setLeft(node* a)
	{
		left = a;
	}
	void setRight(node* a)
	{
		right = a;
	}
	void setParent(node* a)
	{
		parent = a;
	}
};

class BTS
{
public:
	//vector<node*> e_list;
	node* root;
	int size;
	int c;
	BTS()
	{
		root = NULL;
		size = 0;
		c = -1;
	}
	node* find(int x, node* stan)
	{
		if (stan->data == x || stan == NULL) // root NULL?
		{
			return stan;
		}
		if (stan->data > x) //x가 기준보다 작은 경우 - 왼쪽
		{
			find(x, stan->left);
		}
		else if (stan->data < x) // 큰 경우
		{
			find(x, stan->right);
		}
	}

	void insertNode(int x, node* stan)
	{
		c++;
		if (root == NULL)
		{	
			node* v = new node(x);
			root = v;
			size++;
			return;
		}
		if (stan->data > x)
		{
			if (stan->left == NULL)
			{
				node* v = new node(x);
				v->setParent(stan);
				stan->setLeft(v);
				size++;
				return;
			}
			else
			{
				insertNode(x, stan->left);
			}
		}
		else
		{
			if (stan->right == NULL)
			{
				node* v = new node(x);
				v->setParent(stan);
				stan->setRight(v);
				size++;
				return;
			}
			else
			{
				insertNode(x, stan->right);
			}
		}
	}

	void deleteNode(int x, node* stan)
	{

	}
};


int main()
{
	int N;
	BTS B;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		B.insertNode(a, B.root);
		cout << B.c << endl;
	}
}