#include <iostream>
#include <array>
#include <string>
using namespace std;

int stack[10001], top = -1, bot = 0; //top이 입력(인큐enqueue) bot이 출력(디큐dequeue)

void push(int a)
{
	stack[++top] = a; //enqueue
}

int empty()
{
	if (top < 0) //euqueue가 없을 때
		return 1;
	else //enqueue 가 있을 때
		return 0;
}

void pop() {
	if (empty() == 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << stack[bot] << endl; // bot은 첫번째 자리 유지 첫번째값 제출
		stack[bot] = 0; //첫 번째 값 0으로 만듬
		for (int i = 1; i <= top; i++)
		{ // 뒤에 있는 2번째~ top번째 까지의 값들을 앞으로 한칸 씩 땡김 
			stack[i - 1] = stack[i];
		}
		--top; // 다음 받을 값도 한칸 땡겨서 받아야 되니깐 top-1 적용
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
			cout << top + 1 << endl; //사이즈
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