#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int xy[100][100] = { 0 };

int main()
{
	std::ios::sync_with_stdio(false);
	int N, T, M;
	cin >> T;
	for (int i = 0; i < T; i++)
	{	
		queue<pair<int, int> > q;
		cin >> N >> M;
		int H = N*N;
		int R = 0;
		int Y = N - 1;
		for (Y; Y >= 0; Y--)
		{	
			for (int k = 0; k < N; k++)
			{
				int germ;
				cin >> germ;
				xy[k][Y] = germ;
				if (germ == 1)
				{
					H--;
				}
			}
		}
		for (int j = 0; j < M; j++)
		{
			int x, y;
			cin >> x >> y;
			xy[x][y] = 1;
			H--;
			q.push(make_pair(x, y));
		}
		while (q.empty() != true)
		{
			int L = q.size();
			for (int j = 0; j < L; j++)
			{
				pair<int, int> cell = make_pair(q.front().first,q.front().second);
				q.pop();
				if (xy[cell.first +1][cell.second] != 1 && cell.first+1 != N) // ¿ì
				{
					xy[cell.first + 1][cell.second] = 1;
					q.push(make_pair(cell.first + 1, cell.second));
					H--;
				}
				if (xy[cell.first-1][cell.second] != 1 && cell.first - 1 != -1) // ÁÂ
				{
					xy[cell.first -1][cell.second] = 1;
					q.push(make_pair(cell.first -1, cell.second));
					H--;
				}
				if (xy[cell.first][cell.second+1] != 1 && cell.second + 1 != N) // À§
				{
					xy[cell.first][cell.second + 1] = 1;
					q.push(make_pair(cell.first, cell.second + 1));
					H--;
				}
				if (xy[cell.first][cell.second - 1] != 1 && cell.second - 1 != -1) // ¾Æ·¡
				{
					xy[cell.first][cell.second - 1] = 1;
					q.push(make_pair(cell.first, cell.second-1));
					H--;
				}
				
			}
			R++;
		}
		if (H != 0)
		{
			R = 0;
		}
		cout << R-1 << endl;
		
	}
	return 0;
}