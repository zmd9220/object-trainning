#include <iostream>
#include <vector>
using namespace std;


/*
0 10
2 10
0초 시작 0초 대기 10초 끝 10초 완료
2초 시작 8초 대기(10초 완료 기다림)  18초 걸린시간 (20 - 2) 20초 완료시각

1 3
2 4
3 7
1초 시작 1초 대기 1초에서 시작 완료시각 4초 걸린(응답)시간 3초
2초 시작 2초 대기 4초에서 시작 완료시각 8초 걸린(응답)시간 6초
3초 시작 5초 대기 8초에서 시작 완료시각 15초 걸린시간 12초
2 21
*/
int main()
{	
	std::ios::sync_with_stdio(false);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		vector<unsigned int> stt; //대기시간
		vector<unsigned int> stu; //응답시간
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
