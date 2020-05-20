#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int N, T, M;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> a;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			int ab;
			cin >> ab;
			a.push_back(ab);
		}
		for (int j = 0; j < M; j++)
		{
			int search;
			cin >> search;
			int ab = lower_bound(a.begin(), a.end(), search) - a.begin() + 1;
			
			cout << ab << endl;
		}
	}

	return 0;
}