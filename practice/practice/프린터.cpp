#include <iostream>
#include <queue>
#include<string.h>
using namespace std;
queue<int> q;
int top = -1, bot = 0; //top�� �Է�(��ťenqueue) bot�� ���(��ťdequeue)
int N[101]; int M; int T; int a;
void push(int a)
{
	N[++top] = a; //enqueue
}
int empty()
{
	if (top < 0) //euqueue�� ���� ��
		return 1;
	else //enqueue �� ���� ��
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
		{ // �ڿ� �ִ� 2��°~ top��° ������ ������ ������ ��ĭ �� ���� 
			N[i - 1] = N[i];
		}
		--top; // ���� ���� ���� ��ĭ ���ܼ� �޾ƾ� �Ǵϱ� top-1 ����
	}
}
int main()
{
	cin >> T; //test case
	for (int i = 0; i < T; i++)  
	{
		cin >> a >> M; // ������ ���� ���� ã�� ��ȣ�� ��¹�ȣ 5 2(3��°)
		for (int j = 0; j < a; j++) // ������ �߿䵵 ����ֱ� 21342(�߿䵵)
		{
			int b;
			cin >> b;
			push(b);
		}
		int d = 0, f = 0;

		for (int j = 0; j < a-1; j++) // �߿䵵 �ѹ��� �� Ȯ�� 1��° ���� Ȯ�� ~ 4��° ���� Ȯ�α���
		{
			while (d == 0)//���Ϲ����� ������ // 0��° ���� �ڿ� ���� �� �ϳ��� �켱������ ������ �� ���� �ڷ� ���� �� ���� �������� �ٽ� ���ư� 
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
				if (f == a-1) // �ٵ����� f�� a �� ������ ���� Ȯ���ߴµ��� j�� ���� �켱������ ������� j�� �ֿ켱 ��´�� -> ������Ű�� ���� ���� ���� +1
				{
					break;// ��� �� ���� �� ������ ���ܼ� �ٽ� �ݺ�
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