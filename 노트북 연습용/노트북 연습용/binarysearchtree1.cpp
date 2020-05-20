#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
	node* parent;
	node* left;
	node* right;
	int data;

	node()
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		data = NULL;
	}
	node(int a)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		data = a;
	}

	void setLeft(node* a)
	{
		left = a;
	}

	void setParent(node* a)
	{
		parent = a;
	}
	void setRight(node* a)
	{
		right = a;
	}
};

class BTS
{
public:
	node* root;
	vector<node*> node_list;
	int size;
	int c=-1;
	node* pa;
	BTS()
	{
		root = NULL;
		pa = NULL;
		size = 0;
	}
	BTS(int a)
	{
		root = new node(a);
		pa = NULL;
		size = 1;
		node_list.push_back(root);
	}

	node* find(node* roots, int x) //��Ʈ���� ã�Ƴ��� ����
	{	
		//1. ��Ʈ�� NULL�̰ų� root�� �����Ͱ� ã�� ���� �� �׸��� external�� ���� ������
		if (roots == NULL || roots->data == x)
		{
			return roots;
		}
		pa = roots;
		//for (int i = 0; i < node_list.size(); i++)
		//{
		//	if (node_list[i]->data > x)
		//	{
		//		find(node_list[i]->left, x);
		//	}
		//	else
		//}
		if (roots->data > x) // ��Ʈ���� ���� ��� (���� Ʈ���� �Ѿ)
		{
			return find(roots->left, x); //������ ���ϸ� ��� ������� ���� �ٳ���(preorder�� �Ǿ����)
		}
		else // ��Ʈ���� ū ���(������ Ʈ���� �Ѿ)
			return find(roots->right, x);
	}

	void insert(int x, node* N)
	{	
		c++;
		if (root == NULL) // ��ó�� ��Ʈ��嵵 ��� �ִ� ���)
		{
			root = new node(x);
			size++;
			return;
		}
		
		node* findN = find(root, N->data); // N�� ���� ���� ��ġ�� ã��
		// ���ʿ� ���� ���� N�� �������� ���� ���
		/*if (findN == NULL)
		{
			node* newNode = new node(x);
			node* parent = pa;
			
			findN = newNode;
			if (findN->data < parent->data)
			{
				findN->setParent(parent);
				parent->setLeft(findN);
			}
			else
			{
				findN->setParent(parent);
				parent->setRight(findN);
			}

			pa = NULL;
			size++;
			return;
		}*/
		if (findN->data > x) // N�� �����ϰ� N���� x���� ū���
		{
			if (findN->left == NULL){
				node* newNode = new node(x);
				findN->setLeft(newNode);
				newNode->setParent(findN);
				size++;
				return;
			}
			else
			{
				insert(x, findN->left);
			}
		}
		else // N���� x���� �������(x�� ŭ)
		{
			if (findN->right == NULL) {
				node* newNode = new node(x);
				findN->setRight(newNode);
				newNode->setParent(findN);
				size++;
				return;
			}
			else
			{
				insert(x, findN->right);
			}

			
		}
		//size++;
	}
};

int main()
{
	int N;
	BTS Bs;
	cin >> N;
	for (int i = 0; i < N; i++)
	{	
		int x;
		
		cin >> x;
		//node* V = new node(x);
		Bs.insert(x, Bs.root);
		cout << Bs.c << endl;
	}
}
/*
�ұ��� Ʈ�� - o(n) = o(h)
���� o(log n)
���� ����(�ݺ� or ���)

���� ����
1- �����ϴ� ��尡 external
2- �����ϴ� ����� �ڽ� �� 1���� internal
3- �Ѵ� internal - ���Ǳ��� sucssesor�� ����

expected o(log n) -�־��� ��츸 o(n)�̰� ��������� o(log n)�̹Ƿ�

transplant - �ű�� ���� ���� ����� �θ�(�Ҿƹ���)�� �ڽ�(����)�� ���� ��Ű�� �ڵ�
*/