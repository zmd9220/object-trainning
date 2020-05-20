#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
int T;
vector<string> postfix;
vector<string> input;
stack<char> st;
stack<string> op;
stack<long long int> operand;

bool isMatch1() {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == "(") {
			st.push('(');
		}
		else if (input[i] == ")") {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}
	}
	return (st.empty());
}
bool isMatch2() {
	int Count = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == "+" || input[i] == "-") {
			if (Count == 0) {
				return false;
			}
			else {
				Count--;
			}
		}
		else if (input[i] != "("&&input[i] != ")") {
			if (Count == 1) {
				return false;
			}
			else {
				Count++;
			}
		}
	}
	return (Count == 1);
}

void infixToPostfix() {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == "(") {
			op.push(input[i]);
		}
		else if (input[i] == "+" || input[i] == "-") {
			while (!op.empty() && op.top() != "(") {
				postfix.push_back(op.top());
				op.pop();
			}
			op.push(input[i]);
		}
		else if (input[i] == ")") {
			while (op.top() != "(") {
				postfix.push_back(op.top());
				op.pop();
			}
			op.pop();
		}
		else {
			postfix.push_back(input[i]);
		}
	}

	while (!op.empty()) {
		postfix.push_back(op.top());
		op.pop();
	}
}

void calculate() {
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == "+" || postfix[i] == "-") {
			int t2 = operand.top();
			operand.pop();
			int t1 = operand.top();
			operand.pop();
			if (postfix[i] == "+") {
				operand.push(t1 + t2);
			}
			else {
				operand.push(t1 - t2);
			}
		}
		else {
			operand.push(atoi(postfix[i].c_str()));
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin.ignore();
		postfix.clear();
		input.clear();
		while (!st.empty()) {
			st.pop();
		}
		while (!op.empty()) {
			op.pop();
		}
		while (!operand.empty()) {
			operand.pop();
		}
		string s;


		while (cin >> s) {
			if (s == "$") {
				break;
			}
			input.push_back(s);
			cin.ignore();
		}
		if (isMatch1() && isMatch2()) {
			infixToPostfix();
			calculate();
			cout << operand.top() << endl;
			operand.pop();
		}
		else {
			cout << "N" << endl;
		}
	}
}

