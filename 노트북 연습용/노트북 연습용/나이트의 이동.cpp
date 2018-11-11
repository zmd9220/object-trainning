#include <iostream>
#include <queue>

using namespace std;

int mx[8] = { -1,-2,-2,-1,1,2,2,1 };
int my[8] = { -2,-1,1,2,-2,-1,1,2 }; // 대각선 2,1 이동 8방향

int main()
{
	int T, l, nx, ny, ox, oy; // T-test case l-length(l*l = 체스판 크기) nx,ny-출발 좌표 ox,oy-도착 좌표
	cin >> T;

	for (int test = 0; test < T; test++)
	{	
		cin >> l >> nx >> ny >> ox >> oy;
		int chess[300][300] = { 0 }; //체스판의 칸 수 최대 300x300칸 (l-1*l-1)이니
		
		queue<pair<int, pair<int, int>>> q; // 시간, x,y 좌표 3개 페어 페어(시간,(페어(x,y)))의 구조
		q.push(make_pair(0, make_pair(nx, ny))); // 초기 값(시간0, 현재 x,y좌표)
		chess[nx][ny]++; //체스판 nx,ny좌표는 밟았으니까 지났다는 표시

		while (!q.empty()) //밑에 계속 q.push를 써서 값을 넣기 때문에 break 나올때 까지 무한반복문 나옴.
		{
			int x = q.front().second.first; // x좌표는 q자료의 두번째변수의 첫번째 변수
			int y = q.front().second.second; // y좌표는 q자료의 두번째변수의 두번째변수
			int count = q.front().first; //시간횟수는 q 자료의 맨첫번째 변수
			q.pop(); //저장한 자료 다시 빼냄(필요없으니깐 - 필요한 x,y,count 값은 다 빼냈으므로)

			if (x == ox && y == oy) 
			{  //목표 좌표에 도착 한경우
				cout << count << endl; // 얼마나 걸렸는지 카운트 센거 출력
				break; // 정답에 도착했으니 반복문 돌 필요가 없음 빠져나옴
			}

			for (int i = 0; i < 8; i++) // 좌표 도달 안했으면 8가지 경우의수(이동하는)에 따라 돌아가는 것을 구해봄
			{
				int dx = x + mx[i];
				int dy = y + my[i];

				if (dx < 0 || dx >= l || dy < 0 || dy >= l)
				{
					continue; //위의 4가지 경우는 체스판에서 벗어나는 경우 그럴땐 거르고 다른 경우의 수 찾으면 됨
				}

				if (chess[dx][dy])
					continue;

				chess[dx][dy]++; //새로 도착한 위치에 와본적있다는 표시해주고
				q.push(make_pair(count + 1, make_pair(dx, dy))); // 도착한 곳의 q자료 추가
			}
		}
	}
}