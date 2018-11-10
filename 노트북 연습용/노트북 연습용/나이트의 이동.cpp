#include <iostream>
#include <queue>

using namespace std;

int mx[8] = { -1,-2,-2,-1,1,2,2,1 };
int my[8] = { -2,-1,1,2,-2,-1,1,2 }; // �밢�� 2,1 �̵� 8����

int main()
{
	int T, l, nx, ny, ox, oy; // T-test case l-length(l*l = ü���� ũ��) nx,ny-��� ��ǥ ox,oy-���� ��ǥ
	cin >> T;

	for (int test = 0; test < T; test++)
	{	
		cin >> l >> nx >> ny >> ox >> oy;
		int chess[300][300] = { 0 }; //ü������ ĭ �� �ִ� 300x300ĭ (l-1*l-1)�̴�
		
		queue<pair<int, pair<int, int>>> q; // �ð�, x,y ��ǥ 3�� ��� ���(�ð�,(���(x,y)))�� ����
		q.push(make_pair(0, make_pair(nx, ny))); // �ʱ� ��(�ð�0, ���� x,y��ǥ)
		chess[nx][ny]++; //ü���� nx,ny��ǥ�� ������ϱ� �����ٴ� ǥ��

		while (!q.empty()) //�ؿ� ��� q.push�� �Ἥ ���� �ֱ� ������ break ���ö� ���� ���ѹݺ��� ����.
		{
			int x = q.front().second.first; // x��ǥ�� q�ڷ��� �ι�°������ ù��° ����
			int y = q.front().second.second; // y��ǥ�� q�ڷ��� �ι�°������ �ι�°����
			int count = q.front().first; //�ð�Ƚ���� q �ڷ��� ��ù��° ����
			q.pop(); //������ �ڷ� �ٽ� ����(�ʿ�����ϱ� - �ʿ��� x,y,count ���� �� �������Ƿ�)

			if (x == ox && y == oy) 
			{  //��ǥ ��ǥ�� ���� �Ѱ��
				cout << count << endl; // �󸶳� �ɷȴ��� ī��Ʈ ���� ���
				break; // ���信 ���������� �ݺ��� �� �ʿ䰡 ���� ��������
			}

			for (int i = 0; i < 8; i++) // ��ǥ ���� �������� 8���� ����Ǽ�(�̵��ϴ�)�� ���� ���ư��� ���� ���غ�
			{
				int dx = x + mx[i];
				int dy = y + my[i];

				if (dx < 0 || dx >= l || dy < 0 || dy >= l)
				{
					continue; //���� 4���� ���� ü���ǿ��� ����� ��� �׷��� �Ÿ��� �ٸ� ����� �� ã���� ��
				}

				if (chess[dx][dy])
					continue;

				chess[dx][dy]++; //���� ������ ��ġ�� �ͺ����ִٴ� ǥ�����ְ�
				q.push(make_pair(count + 1, make_pair(dx, dy))); // ������ ���� q�ڷ� �߰�
			}
		}
	}
}