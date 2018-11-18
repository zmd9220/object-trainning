#include <queue>
#include <stdio.h>
using namespace std;
char map[251][251] = {};
int check[251][251] = {};
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M;
int BFS(pair<int, int> n) {
	queue<pair<int, int> > q;
	q.push(n);

	int wolf = 0;
	int sheep = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		char cur = map[y][x];
		if (cur == 'v') {
			wolf++;
		}
		else if (cur == 'o') {
			sheep++;
		}
		check[y][x] = 1;
		for (int i = 0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx <M && ny >= 0 && ny <N) {
				if (check[ny][nx] == 0 && map[ny][nx] != '#') {
					q.push(make_pair(ny, nx));
					check[ny][nx] = 1;
				}
			}
		}
	}
	if (sheep > wolf) {
		return sheep;
	}
	else {
		return wolf * -1;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i<N; i++) {
		char temp[251];
		scanf("%s", temp);
		for (int j = 0; j<M; j++) {
			map[i][j] = temp[j];
		}
	}
	int ansWolf = 0;
	int ansSheep = 0;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (check[i][j] == 0 && map[i][j] != '#') {
				int tp = BFS(make_pair(i, j));
				if (tp > 0) {
					ansSheep += tp;
				}
				else {
					ansWolf += tp*-1;
				}

			}

		}
	}
	printf("%d %d\n", ansSheep, ansWolf);
}