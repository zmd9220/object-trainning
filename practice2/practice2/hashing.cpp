#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct item {
	int key, value;
};

struct arr {
	item *data;
	bool flag = false; // flag 키값이 존재한다고 알려주는 코드

};

arr Hasharr[353333];
int MAX = 353333;
int sz = 0;

int hashfunc(int inp)
{
	return inp % 353333;
}

int hashfunc2(int inp)
{
	return 17 - (inp % 17);
}

void linear_insert(int keys, int values)
{	
	int index = hashfunc(keys);
	int i = index;
	while (Hasharr[i].flag == true)// 빈칸에 해쉬가 있음 (충돌)
	{
		if (Hasharr[i].data->key == keys) //똑같은 키가 있으면 바꿈(키값 까지 같은 경우)- 중복 키 허용 X
		{
			Hasharr[i].data->value = values;
			return;
		}
		i = (i + 1) % MAX;
		if (i == index) return; // 한 바퀴 다돌았는데 빈 해쉬가 없음( 꽉참)
	}
	Hasharr[i].flag = true;// 처음 빈칸에 맞는 해쉬가 비어있는 경우
	item* items = new item;
	items->key = keys;
	items->value = values;
	//Hasharr[i].data->key = keys;
	Hasharr[i].data = items;
	//Hasharr[i].data->value = values;
	sz++;
}

void linear_probing(int keys)
{
	int index = hashfunc(keys);
	int i = index;
	int probing = 1;
	while (Hasharr[i].flag == true)// 빈칸에 해쉬가 있음 (충돌) -> 옆으로 가면서 탐색
	{
		if (Hasharr[i].data->key == keys) // 충돌한 해쉬가 같은 키 = 찾는 것
		{
			//cout <<  1 << " " << probing << endl;
			cout << 1 << endl;
			break;
		}
		
		i = (i + 1) % MAX;
		probing++;
		if (i == index) // 인덱스 끝까지 돌았는데 안나옴 = 없음
		{
			//cout << 0 <<" " << probing << endl;
			cout << 0 << endl;
		}
	}
	if (Hasharr[i].flag == false)
		//cout << 0 << " " << probing << endl;
		cout << 0 << endl;
	// 애초에 없는 경우
	
}

void double_insert(int keys, int values)
{
	int index = hashfunc(keys);
	int ha2 = hashfunc2(keys);
	int i = index;
	while (Hasharr[i].flag == true)// 빈칸에 해쉬가 있음 (충돌)
	{
		if (Hasharr[i].data->key == keys) //똑같은 키가 있으면 바꿈(키값 까지 같은 경우)- 중복 키 허용 X
		{
			Hasharr[i].data->value = values;
			return;
		}
		i = i + ha2;
		if (i == index) return; // 한 바퀴 다돌았는데 빈 해쉬가 없음( 꽉참)
	}
	Hasharr[i].flag = true;// 처음 빈칸에 맞는 해쉬가 비어있는 경우
	item* items = new item;
	items->key = keys;
	items->value = values;
	//Hasharr[i].data->key = keys;
	Hasharr[i].data = items;
	//Hasharr[i].data->value = values;
	sz++;
}

void double_probing(int keys)
{
	int index = hashfunc(keys);
	int i = index;
	int ha2 = hashfunc2(keys);
	int probing = 1;
	while (Hasharr[i].flag == true)// 빈칸에 해쉬가 있음 (충돌) -> 옆으로 가면서 탐색
	{
		if (Hasharr[i].data->key == keys) // 충돌한 해쉬가 같은 키 = 찾는 것
		{
			cout << 1 << endl;
			break;
		}

		i = i + ha2;
		probing++;
		if (i == index) // 인덱스 끝까지 돌았는데 안나옴 = 없음
		{
			cout << 0 << endl;
		}
	}
	if (Hasharr[i].flag == false)
		cout << 0 << endl;
	// 애초에 없는 경우

}


int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{	
		int num;
		cin >> num;
		linear_insert(num, num);
		//double_insert(num, num);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		linear_probing(num);
		//double_probing(num);
	}
}




/*
2차원 배열로 구현- 메모리 낭비 seperate  chaining(메모리를 더 사용한다) -> 리스트로 구현이 적절 성능적인 면에서는 open addresing보단 seperate chaining이 더 빠른편
각 해쉬의 셀을 버켓(hash)- 전체의 배열을 버켓리스트(hash table)

가장 많이 충돌이 일어나는 경우(처음 부터 끝까지 충돌)
ex) 해쉬테이블의 예상보다 많은 elem이 들어오면, 사이즈가 더 큰 해쉬 테이블을 만들어서 이동(배열 내용 다 찼을때와 유사함) -> rehashing
기존  mod N 의 A 해쉬 테이블에서 mod N'(2N)의 B 해쉬 테이블로 다시 해쉬펑션을 하여서 삽입

이진탐색 log n+n(삽입삭제- 탐색시간+shift n/2시간)

hashing 평균의경우 상수시간내 탐색,삽입,삭제 가능

div 해쉬 -소수
div2 더블해싱 -소수

해쉬코드 h1,h2구하는 코드 2개
선형 탐색(삽입)
선형 탐색
더블해싱 삽입
더블해싱 탐색

*/