#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
	node* parent;
	vector<node*> child;
	int data;
	node()
	{
		data = NULL;
		parent = NULL;
	}
	node(int a)
	{
		data = a;
		parent = NULL;
	}

	void setChild(node* a)
	{
		child.push_back(a);
	}
	void setParent(node* a)
	{
		parent = a;
	}

	void delChild(node* a)
	{
		for (int i = 0; i < child.size(); i++)
		{
			if (child[i] == a)
			{
				child.erase(child.begin() + i);
			}
		}
	}

	
};

class Tree
{
public:
	int tree_size = 0;
	node* root;
	vector<node*> node_list;
	void insertNode()
	{

	}
	void deleteNode()
	{

	}
	void printChild(int a)
	{

	}
	void preorder(node* node)
	{
		cout << node->data << " ";
	}
	void postorder(node* node)
	{
		cout << node->data << " ";
	}
};

int main()
{

}