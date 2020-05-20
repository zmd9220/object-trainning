#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{	
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		priority_queue<int, vector<int>, less<int> > min_heap;
		priority_queue<int, vector<int>, greater<int> > max_heap;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (i == 0)
			{
				min_heap.push(a);
			}
			else
			{
				int b = min_heap.top();
				if (a > b)
				{
					max_heap.push(a);
				}
				else
				{
					min_heap.push(a);
				}
			}
			if (min_heap.size() > max_heap.size() + 1)
			{
				int b = min_heap.top();
				min_heap.pop();
				max_heap.push(b);
			}
			else if (max_heap.size() > min_heap.size())
			{
				int b = max_heap.top();
				max_heap.pop();
				min_heap.push(b);
			}

			cout << min_heap.top() << " ";
		}
		cout << endl;
	}
}