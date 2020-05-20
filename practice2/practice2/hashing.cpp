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
	sz++;
}

void linear_probing(int keys)
{
	int index = hashfunc(keys);
	int i = index;
	int probing = 1;
	while (Hasharr[i].flag == true)// ��ĭ�� �ؽ��� ���� (�浹) -> ������ ���鼭 Ž��
	{
		if (Hasharr[i].data->key == keys) // �浹�� �ؽ��� ���� Ű = ã�� ��
		{
			//cout <<  1 << " " << probing << endl;
			cout << 1 << endl;
			break;
		}
		
		i = (i + 1) % MAX;
		probing++;
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

void double_insert(int keys, int values)
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
2���� �迭�� ����- �޸� ���� seperate  chaining(�޸𸮸� �� ����Ѵ�) -> ����Ʈ�� ������ ���� �������� �鿡���� open addresing���� seperate chaining�� �� ������
�� �ؽ��� ���� ����(hash)- ��ü�� �迭�� ���ϸ���Ʈ(hash table)

���� ���� �浹�� �Ͼ�� ���(ó�� ���� ������ �浹)
ex) �ؽ����̺��� ���󺸴� ���� elem�� ������, ����� �� ū �ؽ� ���̺��� ���� �̵�(�迭 ���� �� á������ ������) -> rehashing
����  mod N �� A �ؽ� ���̺��� mod N'(2N)�� B �ؽ� ���̺�� �ٽ� �ؽ������ �Ͽ��� ����

����Ž�� log n+n(���Ի���- Ž���ð�+shift n/2�ð�)

hashing ����ǰ�� ����ð��� Ž��,����,���� ����

div �ؽ� -�Ҽ�
div2 �����ؽ� -�Ҽ�

�ؽ��ڵ� h1,h2���ϴ� �ڵ� 2��
���� Ž��(����)
���� Ž��
�����ؽ� ����
�����ؽ� Ž��

*/