#include <iostream>
#include <vector>

class item
{
public:

	int key, value;
	item()
	{
		key = NULL;
		value = NULL;
	}
	
};

class arr
{public:
	item* data;
	bool flag;
	bool available;
	arr()
	{
		flag = false;
		available = false;
	}
};

arr hasharr[353333];
int max = 353333;
int sz = 0;

int hashcode(int key) // �⺻ hash code
{
	return key % max;
}

int hashcode2(int key2) // double hashing �� �ʿ��� �κ�
{
	return 17 - (key2 % 17);
}
void linear_insert(int keys, int values)
{
	int index = hashcode(keys);
	int i = index;
	while (hasharr[i].flag == true)
	{
		if (hasharr[i].data->key == keys)
		{
			hasharr[i].data->value = values; // Ű�� ���� ��� �����͸� ��ü
			return;
		}
		i = (i + 1) % max;	
		if (i == index)
			return; // �� ���Ҵµ� ���� X - ����
	}
	if (hasharr[i].available == true)
	{
		hasharr[i].available = false;
	}
	hasharr[i].flag = true;
	hasharr[i].data->key = keys;
	hasharr[i].data->value = values;
	sz++;
}



int linear_probing(int keys)
{
	int index = hashcode(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available == true) // available�� true ���� ���� �������� ������ �ϹǷ� �̶��� Ž���� �������� ��
	{
		if (hasharr[i].data->key == keys)
		{
			return hasharr[i].data->value;
		}
		i = (i + 1) % max;
		if (i == index)
		{
			return -1;
		}
	}
	if (hasharr[i].flag == false)
		return -1; // ���ʿ� �װ��� �ƹ��͵� ����

	
}

void double_insert(int keys, int values)
{	
	int index = hashcode(keys);
	int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true) // ������ �� ������� ã����� hasharr[i].available == true �̶� ���� �����ϸ��
	{
		if (hasharr[i].data->key == keys)
		{
			hasharr[i].data->value = values; // Ű�� ���� ��� �����͸� ��ü
			return;
		}
		i = i + jump;
		if (i == index)
			return; // �� ���Ҵµ� ���� X - ����
	}
	if (hasharr[i].available == true) // ���� ���� ��� �����̶� available ���� ���� -> �ٽ� �޽��ϰ� ���߿� �����ϸ� �ٽ� Ʈ��
	{
		hasharr[i].available = false;
	}
	hasharr[i].flag = true;
	hasharr[i].data->key = keys;
	hasharr[i].data->value = values;
	sz++;
}

int double_probing(int keys)
{
	int index = hashcode(keys);
	int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available==true) // Ž���ÿ��� ���� ��ġ�� ������ ���̶� flag=false�� �� ���� ���� �� ����
	{
		if (hasharr[i].data->key == keys)
		{
			return hasharr[i].data->value;
		}
		i = i+jump;
		if (i == index)
		{
			return -1;
		}
	}
	if (hasharr[i].flag == false)
		return -1; // ���ʿ� �װ��� �ƹ��͵� ����


}

void double_delete(int keys)
{
	int index = hashcode(keys);
	int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available == true) // Ž���ÿ��� ���� ��ġ�� ������ ���̶� flag=false�� �� ���� ���� �� ����
	{
		if (hasharr[i].data->key == keys)
		{	
			hasharr[i].data->key = NULL;
			hasharr[i].data->value = NULL;
			hasharr[i].available = true;
			hasharr[i].flag = false;
			return;
		}
		i = i + jump;
		if (i == index)
		{
			return;
		}
	}
	if (hasharr[i].flag == false) // ���ʿ� ������ Ű ���� ����
	{
		return;
	}
}

void linear_delete(int keys)
{
	int index = hashcode(keys);
	//int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available == true) // Ž���ÿ��� ���� ��ġ�� ������ ���̶� flag=false�� �� ���� ���� �� ����
	{
		if (hasharr[i].data->key == keys)
		{
			hasharr[i].data->key = NULL;
			hasharr[i].data->value = NULL;
			hasharr[i].available = true;
			hasharr[i].flag = false;
			return;
		}
		i = (i + 1) % max;
		if (i == index)
		{
			return;
		}
	}
	if (hasharr[i].flag == false) // ���ʿ� ������ Ű ���� ����
	{
		return;
	}

}