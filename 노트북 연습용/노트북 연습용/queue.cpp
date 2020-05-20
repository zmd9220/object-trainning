#include <iostream>
#include <string>
using namespace std;

class node {
public:
	node()
	{	
		this->next = NULL;
		this->prev = NULL;
	}
	int data;
	node* next;
	node* prev;
};


class DLinkedList
{
public:
	DLinkedList()
	{
		header = new node;
		tailer = new node;
		header->prev = tailer->next = NULL;
		header->next = tailer;
		tailer->prev = header;
	}
	void addFront(int x)
	{
		//if (header->next == tailer)
		//{
			node* newNode = new node;
			newNode->data = x;
			newNode->prev = header;
			newNode->next = tailer;
			header->next->prev = newNode;
			header->next = newNode;
			//tailer->prev = newNode;

		//}
		/*else
		{
			node* newNode = new node;
			node* oldNode = header->next;
			newNode->data = x;
			oldNode->prev = newNode;
			newNode->next = oldNode;
			header->next = newNode;
			newNode->prev = header;

		}*/
	}
	int front()
	{	
		if (empty())
			return -1;
		else
			return header->next->data;
	}
	bool empty()
	{
		return header->next == tailer;
	}
	void addBack(int x)
	{
		//if (header->next == tailer)
		//{
			node* newNode = new node;
			newNode->data = x;
			newNode->prev = header;
			newNode->next = tailer;
			tailer->prev->next = newNode;
			tailer->prev = newNode;
			
		//}
		/*else
		{
			node* newNode = new node;
			node* oldNode = tailer->prev;
			newNode->data = x;
			oldNode->next = newNode;
			newNode->prev = oldNode;
			tailer->prev = newNode;
			newNode->next = tailer;

		}*/
	}
	int back()
	{
		if (empty())
			return -1;
		return tailer->prev->data;
	}
	int removeBack()
	{
		if (empty())
			return -1;
		else {
			node* dNode = tailer->prev;
			node* tNode = dNode->prev;
			tailer->prev = tNode;
			tNode->next = tailer;
			int d = dNode->data;
			delete dNode;
			return d;
		}
	}
	int removeFront()
	{
		if (empty())
			return -1;
		else {
			node* dNode = header->next;
			node* hNode = dNode->next;
			header->next = hNode;
			hNode->prev = header;
			int d = dNode->data;
			delete dNode;
			return d;
		}
	}

	node* header;
	node* tailer;
};

class Queue
{
public:
	Queue()
	{
		this->Q = new DLinkedList();
		this->n = 0;
	}
	void enqueue(int x)
	{	
		n++;
		Q->addBack(x);
		
	}
	int dequeue()
	{
		if (empty()) // ��ť���� dequeue �ϸ� n�� ������ �������� ���� ����
			return -1;
		else {
			n--;
			return Q->removeFront();
		}
		
	}
	int size()
	{
		return n;
	}
	bool empty()
	{
		//return Q->empty();
		return n == 0;
	}
	
	int front()
	{
		return Q->front();
	}
	int rear()
	{
		return Q->back();
	}

	DLinkedList* Q;
	int n;
};
int main()
{	
	Queue listq;
	int N;
	string X;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X;
		if (X == "enqueue")
		{
			int a;
			cin >> a;
			listq.enqueue(a);
		}
		else if (X == "dequeue")
		{
			cout << listq.dequeue() << endl;
		}
		else if (X == "size")
			cout << listq.size() << endl;
		else if (X == "empty")
			cout << listq.empty() << endl;
		else if (X == "front")
			cout << listq.front() << endl;
		else if (X == "rear")
			cout << listq.rear() << endl;
	}

	return 0;
}


/*
void dequeue()
	node* tempNode = cursor->next;
	cursor->next = tempNode->next;
	delete tempNode;
	n--;
	ȯ���� �ʱ⿡ �ڱ��ڽŸ������� next�� �ڱ��ڽ��� �����Ѿ���

	���̳��,���ͳ�-header,trailer
	singly- removeback ����ð��� ó�� ����
	
	new �Լ� ���캸��(�����͸� ����:?)
*/