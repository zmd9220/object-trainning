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
		cin >> a >> M; // ������ ���� ���� ã�� ��ȣ�� ��¹�ȣ 5 2(3��°)
		for (int j = 0; j < a; j++) // ������ �߿䵵 ����ֱ� 21342(�߿䵵)
		{
			int b;
			cin >> b;
			q.push(b); 
			N[j] = b;
		}
		int d = 0, f = 0;

		for (int j = 0; j < a-1; j++) // �߿䵵 �ѹ��� �� Ȯ�� 1��° ���� Ȯ�� ~ 4��° ���� Ȯ�α���
		{
			while (d == 0)//���Ϲ����� ������ // 0��° ���� �ڿ� ���� �� �ϳ��� �켱������ ������ �� ���� �ڷ� ���� �� ���� �������� �ٽ� ���ư� 
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
				if (f == a-1) // �ٵ����� f�� a �� ������ ���� Ȯ���ߴµ��� j�� ���� �켱������ ������� j�� �ֿ켱 ��´�� -> ������Ű�� ���� ���� ���� +1
				{
					break;// ��� �� ���� �� ������ ���ܼ� �ٽ� �ݺ�
				}
			}
			
			if 
			f= j+1;

		}

	}
}