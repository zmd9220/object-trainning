#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	node(int x)
	{
		this->data = x;
		this->next = NULL;
		this->prev = NULL;
	}
	int data;
	node* next;
	node* prev;
};

class SLinkedList
{
public:
	node* head;
	node* tail;
	SLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	int front()
	{	
		if (head == NULL)
		{
			return -1;
		}
		else
			return head->data;
	}
	void addFront(int x)
	{
		node* newNode = new node(x);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void removeFront()
	{
		node* tmp = head;
		head = head->next;
		cout << tmp->data << endl;
		delete tmp;
	}

};


class DLinkedList
{
public:
	node* head;
	node* tail;
	DLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	int front()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
			return head->data;
	}
	void addFront(int x)
	{
		node* newNode = new node(x);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void removeFront()
	{
		node* tmp = head;
		head = head->next;
		cout << tmp->data << endl;
		delete tmp;
	}

};

class stack
{
public:

	int n;
	SLinkedList* S;
	stack()
	{
		this->S = new SLinkedList();
		this->n = 0;
	}
	bool empty()
	{
		return n == 0;
	}

	void push(int X)
	{

			S->addFront(X);
			n++;


	}
	void pop()
	{
		if (empty())
			cout << -1 << endl;
		else
		{
			S->removeFront();
			n = n - 1;

		}
	}
	int size()
	{
		return n;
	}
	void top()
	{
		if (empty())
			cout << -1 << endl;
		else
		{
			cout << S->front() << endl;
		}

	}
};

int main()
{
	stack A;
	int N;
	string X;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		if (X == "push")
		{
			int a;
			cin >> a;
			A.push(a);
		}
		else if (X == "top")
		{
			A.top();
		}
		else if (X == "size")
		{
			cout << A.size() << endl;
		}
		else if (X == "pop")
		{
			A.pop();
		}
		else if (X == "empty")
			cout << A.empty() << endl;
	}
}

/*
stack - LIFO(후입선출)
5페이지 size() - the number of elements stored in S; pop() - 최근 데이터 리턴하면서 삭제 delete() - 최근 데이터 삭제 (수업에서 배운것과 살짝 다름)
18페이지 front() - 예외처리 필요 removeFront() 예외처리필요+tmp+data 
19페이지 top() 예외처리
*/