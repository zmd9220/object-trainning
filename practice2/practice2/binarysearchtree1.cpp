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

	node* find(node* roots, int x) //루트부터 찾아나갈 것임
	{	
		//1. 루트가 NULL이거나 root의 데이터가 찾는 값일 때 그리고 external에 도착 했을때
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
		if (roots->data > x) // 루트보다 작은 경우 (왼쪽 트리로 넘어감)
		{
			return find(roots->left, x); //리턴을 안하면 모든 진행과정 값이 다나옴(preorder가 되어버림)
		}
		else // 루트보다 큰 경우(오른쪽 트리로 넘어감)
			return find(roots->right, x);
	}

	void insert(int x, node* N)
	{	
		c++;
		if (root == NULL) // 맨처음 루트노드도 비어 있는 경우)
		{
			root = new node(x);
			size++;
			return;
		}
		
		node* findN = find(root, N->data); // N의 값을 가진 위치를 찾고
		// 애초에 값을 가진 N가 존재하지 않을 경우
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
		if (findN->data > x) // N이 존재하고 N값이 x보다 큰경우
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
		else // N값이 x보다 작은경우(x가 큼)
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
불균형 트리 - o(n) = o(h)
균형 o(log n)
삽입 연산(반복 or 재귀)

삭제 연산
1- 삭제하는 노드가 external
2- 삭제하는 노드의 자식 중 1개가 internal
3- 둘다 internal - 강의기준 sucssesor로 수행

expected o(log n) -최악인 경우만 o(n)이고 평균적으론 o(log n)이므로

transplant - 옮기고 나서 남은 노드의 부모(할아버지)와 자식(손자)를 연결 시키는 코드
*/