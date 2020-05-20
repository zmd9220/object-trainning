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

arr Hasharr[100003];
int MAX = 100003;
int sz = 0;

int hashfunc(int inp)
{	
	if (inp < 0)
	{
		return (-1 * inp) % 100003;
	}
	return inp % 100003;
}

//int hashfunc2(int inp)
//{
//	return 17 - (inp % 17);
//}

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
	//sz++;
}

void linear_probing(int keys)
{
	int index = hashfunc(keys);
	int i = index;
	//int probing = 1;
	while (Hasharr[i].flag == true)// 빈칸에 해쉬가 있음 (충돌) -> 옆으로 가면서 탐색
	{
		if (Hasharr[i].data->key == keys) // 충돌한 해쉬가 같은 키 = 찾는 것
		{
			//cout <<  1 << " " << probing << endl;
			cout << 1 << endl;
			break;
		}

		i = (i + 1) % MAX;
		//probing++;
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

/*void double_insert(int keys, int values)
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

}*/


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

