#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{	
		vector<int> stt;
		int N, M;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			int b;
			cin >> b;
			stt.push_back(b);
		}
		for (int k = 0; k < M; k++)
		{
			int c;
			int sta = 0;
			int la = N-1;
			int mi = la / 2;
			cin >> c;
			while (true)
			{	
				
				if (stt[mi] == c)
				{
					cout << mi+1 << endl;
					break;
				}
				else if (stt[mi] > c) // 찾을 값이 작은 경우
				{
					la = mi;
					mi = la / 2;
				}
				else if (stt[mi] < c)
				{
					sta = mi;
					mi = (sta + la) / 2;
				}
					
			}
			
			
		}

	}

}

