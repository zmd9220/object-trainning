#include <iostream>
#include <queue>
#include<string.h>
using namespace std;
queue<int> q;
int top = -1, bot = 0; //top이 입력(인큐enqueue) bot이 출력(디큐dequeue)
int N[101]; int M; int T; int a;
void push(int a)
{
	N[++top] = a; //enqueue
}
int empty()
{
	if (top < 0) //euqueue가 없을 때
		return 1;
	else //enqueue 가 있을 때
		return 0;
}

void pop() {
	if (empty() == 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		int b = N[bot];
		push(b);
		for (int i = bot+1; i <= top; i++)
		{ // 뒤에 있는 2번째~ top번째 까지의 값들을 앞으로 한칸 씩 땡김 
			N[i - 1] = N[i];
		}
		--top; // 다음 받을 값도 한칸 땡겨서 받아야 되니깐 top-1 적용
	}
}
int main()
{
	cin >> T; //test case
	for (int i = 0; i < T; i++)  
	{
		cin >> a >> M; // 문서의 수와 내가 찾는 번호의 출력번호 5 2(3번째)
		for (int j = 0; j < a; j++) // 각각의 중요도 집어넣기 21342(중요도)
		{
			int b;
			cin >> b;
			push(b);
		}
		int d = 0, f = 0;

		for (int j = 0; j < a-1; j++) // 중요도 한번씩 다 확인 1번째 숫자 확인 ~ 4번째 숫자 확인까지
		{
			while (d == 0)//와일문으로 돌리고 // 0번째 값이 뒤에 수들 중 하나라도 우선순위가 낮으면 그 값을 뒤로 리턴 후 위의 포문으로 다시 돌아감 
			{
				
				if (N[j] < N[++f])
				{	
					int e = N[M];
					pop();
					f = j;
					if (e != N[M] || e == N[M+1] || e == N[j])
						--M;
					if (M == j-1)
					{
						M += a-j;
					}
				}
				if (f == a-1) // 다돌려서 f가 a 즉 마지막 까지 확인했는데도 j의 값이 우선순위가 높은경우 j가 최우선 출력대상 -> 삭제시키고 내가 뽑을 순서 +1
				{
					break;// 출력 후 삭제 및 앞으로 땡겨서 다시 반복
				}
			}
			f= j+1;
			++bot;

		}
		cout << M+1 << endl;
		fill_n(N, 101, 0);
		bot = 0;
		top = -1;
	}
}