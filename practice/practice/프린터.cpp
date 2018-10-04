#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int N[101]; int M; int T; int a;

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
			q.push(b); 
			N[j] = b;
		}
		int d = 0, f = 0;

		for (int j = 0; j < a-1; j++) // 중요도 한번씩 다 확인 1번째 숫자 확인 ~ 4번째 숫자 확인까지
		{
			while (d == 0)//와일문으로 돌리고 // 0번째 값이 뒤에 수들 중 하나라도 우선순위가 낮으면 그 값을 뒤로 리턴 후 위의 포문으로 다시 돌아감 
			{
				
				if (N[j] < N[++f])
				{
					int c = q.front();
					q.pop();
					q.push(c);
					f = j+1;
					M--;
					if (M == -1)
					{
						M += a;
					}
				}
				if (f == a-1) // 다돌려서 f가 a 즉 마지막 까지 확인했는데도 j의 값이 우선순위가 높은경우 j가 최우선 출력대상 -> 삭제시키고 내가 뽑을 순서 +1
				{
					break;// 출력 후 삭제 및 앞으로 땡겨서 다시 반복
				}
			}
			
			if 
			f= j+1;

		}

	}
}