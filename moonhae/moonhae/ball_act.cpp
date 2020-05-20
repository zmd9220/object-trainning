#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> ab;
		int n, l, k;
		cin >> n >> l >> k;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a > 0)
			{
				ab.push_back(l - a);
			}
			else
			{
				ab.push_back(-a);
			}
		}
		sort(ab.begin(), ab.end());
		cout << ab[k - 1] << endl;
	}
}