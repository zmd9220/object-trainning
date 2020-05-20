#include <iostream>
#include <array>
#include <string>
using namespace std;

int stack[10001], top = -1;

void push(int a) {
	stack[++top] = a;
}

int empty() {
	if (top < 0)
		return 1;
	else
		return 0;
}

void pop() {
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		cout << stack[top] << endl;
		stack[top--] = 0;
	}
}

int main() {

	int a{ 0 }, b = 0, c = 0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string b;
		cin >> b;
		if (b == "push") {
			int c;
			cin >> c;
			push(c);
		}
		else if (b == "top") {
			if (empty() == 1)
				cout << "-1" << endl;
			else
				cout << stack[top] << endl;
		}
		else if (b == "pop")
			pop();
		else if (b == "empty") {
			cout << empty() << endl;
		}
		else
			cout << top + 1 << endl;
	}
}