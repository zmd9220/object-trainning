#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{	
		map<string, set<int> > m;
		map<string, set<int> >::iterator mi;
		set<int> dup_set;
		set<int> temp;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a;
			string b;
			cin >> a >> b;
			
			if (m.find(b) == m.end())
			{	
				//temp.insert(a);
				//m[b] = temp;
				m[b].insert(a);
				//temp.clear();
			}
			else
			{
				if (m[b].find(a) == m[b].end())
				{
					m[b].insert(a);
				}
				else
					dup_set.insert(a);
			}
		}
		int dupl = 0, cs = 0;
		for (mi = m.begin(); mi != m.end(); mi++)
		{
			if (mi->second.size() > 1)
			{
				dupl = dupl + mi->second.size();
			}
		}
		cs = dup_set.size();
		cout << cs << " " << dupl << endl;
	}
}