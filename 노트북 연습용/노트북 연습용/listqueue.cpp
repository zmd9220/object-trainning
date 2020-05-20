#include <iostream>
#include <string>

using namespace std;

class node 
{
public:
	int data;
	node* next;
	node(int e)
	{	
		this->data = e;
		this->next = NULL;
	}

};

class sList {
public:
	node* f;
	node* r;
	sList()
	{
		f = NULL;
		r = NULL;
	}
	void addBack(int x)
	{
		if (f == NULL)
		{
			node* v = new node(x);
			//v->data = x;
			f = v;
			r = v;
		}
		else {
			node* v = new node(x);
			//v->data = x;
			r = v;
			r->next = NULL;
		}
	}
	int removeFront()
	{
		if (f == NULL)
		{
			return -1;
		}
		else
		{	
		
			node* d = f;
			f = f->next;
			int df = d->data;
			delete d;
			return df;
		}
	}

	int front()
	{
		return f->data;
	}

	int rear()
	{
		return r->data;
	}



};

class queue {
public:
	sList* q;
	int n;
	queue()
	{
		this->q = new sList();
		this->n = 0;
	}

	void enqueue(int x)
	{
		q->addBack(x);
		n++;
	}
	int dequeue()
	{	
		if (empty())
			return -1;
		else {
			n--;
			return q->removeFront();
		}
			
	}
	int size() {
		return n;
	}
	bool empty()
	{
		return n == 0;
	}

	int front()
	{
		if (empty())
			return -1;
		else
			return q->front();
	}

	int rear()
	{
		if (empty())
			return -1;
		else
			return q->rear();
	}
};

int main()
{
	queue ab;
	
	int N;
	string ex;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ex;
		if (ex == "enqueue")
		{
			int a;
			cin >> a;
			ab.enqueue(a);
		}
		else if (ex == "dequeue")
			cout << ab.dequeue() << endl;
		else if (ex == "empty")
			cout << ab.empty() << endl;
		else if (ex == "size")
			cout << ab.size() << endl;
		else if (ex == "front")
			cout << ab.front() << endl;
		else if (ex == "rear")
			cout << ab.rear() << endl;
	}

}