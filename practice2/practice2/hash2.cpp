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

int hashcode(int key) // 기본 hash code
{
	return key % max;
}

int hashcode2(int key2) // double hashing 때 필요한 부분
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
			hasharr[i].data->value = values; // 키가 같은 경우 데이터만 교체
			return;
		}
		i = (i + 1) % max;	
		if (i == index)
			return; // 다 돌았는데 공간 X - 꽉참
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
	while (hasharr[i].flag == true || hasharr[i].available == true) // available이 true 였던 곳도 지나가게 만들어야 하므로 이때도 탐색후 지나가게 함
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
		return -1; // 애초에 그곳에 아무것도 없음

	
}

void double_insert(int keys, int values)
{	
	int index = hashcode(keys);
	int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true) // 삽입일 땐 빈공간만 찾으면됨 hasharr[i].available == true 이라도 삽입 실행하면됨
	{
		if (hasharr[i].data->key == keys)
		{
			hasharr[i].data->value = values; // 키가 같은 경우 데이터만 교체
			return;
		}
		i = i + jump;
		if (i == index)
			return; // 다 돌았는데 공간 X - 꽉참
	}
	if (hasharr[i].available == true) // 전에 삭제 됬던 공간이라서 available 열린 상태 -> 다시 펄스하고 나중에 삭제하면 다시 트루
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
	while (hasharr[i].flag == true || hasharr[i].available==true) // 탐색시에는 다음 위치가 삭제된 곳이라 flag=false가 된 곳이 있을 수 있음
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
		return -1; // 애초에 그곳에 아무것도 없음


}

void double_delete(int keys)
{
	int index = hashcode(keys);
	int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available == true) // 탐색시에는 다음 위치가 삭제된 곳이라 flag=false가 된 곳이 있을 수 있음
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
	if (hasharr[i].flag == false) // 애초에 삭제할 키 값이 없음
	{
		return;
	}
}

void linear_delete(int keys)
{
	int index = hashcode(keys);
	//int jump = hashcode2(keys);
	int i = index;
	while (hasharr[i].flag == true || hasharr[i].available == true) // 탐색시에는 다음 위치가 삭제된 곳이라 flag=false가 된 곳이 있을 수 있음
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
	if (hasharr[i].flag == false) // 애초에 삭제할 키 값이 없음
	{
		return;
	}

}