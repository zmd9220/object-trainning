#include <iostream>
#include <vector>
using namespace std;


/*
0 10
2 10
0�� ���� 0�� ��� 10�� �� 10�� �Ϸ�
2�� ���� 8�� ���(10�� �Ϸ� ��ٸ�)  18�� �ɸ��ð� (20 - 2) 20�� �Ϸ�ð�

1 3
2 4
3 7
1�� ���� 1�� ��� 1�ʿ��� ���� �Ϸ�ð� 4�� �ɸ�(����)�ð� 3��
2�� ���� 2�� ��� 4�ʿ��� ���� �Ϸ�ð� 8�� �ɸ�(����)�ð� 6��
3�� ���� 5�� ��� 8�ʿ��� ���� �Ϸ�ð� 15�� �ɸ��ð� 12��
2 21
*/
int main()
{	
	std::ios::sync_with_stdio(false);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		vector<unsigned int> stt; //���ð�
		vector<unsigned int> stu; //����ð�
		int N;
		int count = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			unsigned int b,c;
			cin >> b >> c;
			if (j == 0) {
				stt.push_back(0);
				stu.push_back(c);
				count = b + c;
			}
			else {
				stt.push_back(count - b);
				stu.push_back(stt[j] + c);
				count = count + c;
			}
			

			
		}
		unsigned int A = 0, B = 0;
		for (int k = 0; k < stt.size(); k++)
		{	
			
			A += stt[k];
		}
		for (int l = 0; l < stu.size(); l++)
		{
			B += stu[l];
		}
		//cout << stt.size() << endl << stt.max_size() << endl;
		cout << A / N << " " << B / N << endl;

	}

}
