#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct item {
	int key, value;
};

struct arr {
	item *data;
	bool flag = false; // flag Ű���� �����Ѵٰ� �˷��ִ� �ڵ�

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
	while (Hasharr[i].flag == true)// ��ĭ�� �ؽ��� ���� (�浹)
	{
		if (Hasharr[i].data->key == keys) //�Ȱ��� Ű�� ������ �ٲ�(Ű�� ���� ���� ���)- �ߺ� Ű ��� X
		{
			Hasharr[i].data->value = values;
			return;
		}
		i = (i + 1) % MAX;
		if (i == index) return; // �� ���� �ٵ��Ҵµ� �� �ؽ��� ����( ����)
	}
	Hasharr[i].flag = true;// ó�� ��ĭ�� �´� �ؽ��� ����ִ� ���
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
	while (Hasharr[i].flag == true)// ��ĭ�� �ؽ��� ���� (�浹) -> ������ ���鼭 Ž��
	{
		if (Hasharr[i].data->key == keys) // �浹�� �ؽ��� ���� Ű = ã�� ��
		{
			//cout <<  1 << " " << probing << endl;
			cout << 1 << endl;
			break;
		}

		i = (i + 1) % MAX;
		//probing++;
		if (i == index) // �ε��� ������ ���Ҵµ� �ȳ��� = ����
		{
			//cout << 0 <<" " << probing << endl;
			cout << 0 << endl;
		}
	}
	if (Hasharr[i].flag == false)
		//cout << 0 << " " << probing << endl;
		cout << 0 << endl;
	// ���ʿ� ���� ���

}

/*void double_insert(int keys, int values)
{
	int index = hashfunc(keys);
	int ha2 = hashfunc2(keys);
	int i = index;
	while (Hasharr[i].flag == true)// ��ĭ�� �ؽ��� ���� (�浹)
	{
		if (Hasharr[i].data->key == keys) //�Ȱ��� Ű�� ������ �ٲ�(Ű�� ���� ���� ���)- �ߺ� Ű ��� X
		{
			Hasharr[i].data->value = values;
			return;
		}
		i = i + ha2;
		if (i == index) return; // �� ���� �ٵ��Ҵµ� �� �ؽ��� ����( ����)
	}
	Hasharr[i].flag = true;// ó�� ��ĭ�� �´� �ؽ��� ����ִ� ���
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
	while (Hasharr[i].flag == true)// ��ĭ�� �ؽ��� ���� (�浹) -> ������ ���鼭 Ž��
	{
		if (Hasharr[i].data->key == keys) // �浹�� �ؽ��� ���� Ű = ã�� ��
		{
			cout << 1 << endl;
			break;
		}

		i = i + ha2;
		probing++;
		if (i == index) // �ε��� ������ ���Ҵµ� �ȳ��� = ����
		{
			cout << 0 << endl;
		}
	}
	if (Hasharr[i].flag == false)
		cout << 0 << endl;
	// ���ʿ� ���� ���

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

