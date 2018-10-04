#include <iostream>
#include <array>
#include <string>
using namespace std;

int stack[10001], top = -1, bot = 0; //top�� �Է�(��ťenqueue) bot�� ���(��ťdequeue)

void push(int a)
{
	stack[++top] = a; //enqueue
}

int empty()
{
	if (top < 0) //euqueue�� ���� ��
		return 1;
	else //enqueue �� ���� ��
		return 0;
}

void pop() {
	if (empty() == 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << stack[bot] << endl; // bot�� ù��° �ڸ� ���� ù��°�� ����
		stack[bot] = 0; //ù ��° �� 0���� ����
		for (int i = 1; i <= top; i++)
		{ // �ڿ� �ִ� 2��°~ top��° ������ ������ ������ ��ĭ �� ���� 
			stack[i - 1] = stack[i];
		}
		--top; // ���� ���� ���� ��ĭ ���ܼ� �޾ƾ� �Ǵϱ� top-1 ����
	}
}

int main()
{

	int a{ 0 }, b = 0, c = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		string b;
		cin >> b;
		if (b == "push")
		{
			int c;
			cin >> c;
			push(c);
		}
		else if (b == "front")
		{
			if (empty() == 1)
				cout << "-1" << endl;
			else
				cout << stack[bot] << endl;
		}
		else if (b == "pop")
			pop();
		else if (b == "empty")
		{
			cout << empty() << endl; //empty
		}
		else if (b == "size")
		{
			cout << top + 1 << endl; //������
		}
		else if (b == "back")
		{
			if (empty() == 1)
				cout << "-1" << endl;
			else
				cout << stack[top] << endl;
		}
	}
}