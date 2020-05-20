#include <iostream>
#include <vector>
#include <string>
using namespace std;

class vertex
{
private:
	int degree;
public:
	vertex()
	{
		degree = 0;
	}
	void increase_deg()
	{
		degree++;
	}
	void decrease_deg()
	{
		if (degree == NULL)
			return;
		degree--;
	}
	int get()
	{
		return degree;
	}
};

class edge
{
public:
	vertex* sta;
	vertex* des;
	string mass;
	edge(vertex* a, vertex* b)
	{
		sta = a;
		des = b;
	}
	edge(vertex* a, vertex* b, string m)
	{
		sta = a;
		des = b;
		mass = m;
	}


};

class graph
{
private:
	vertex** v;
	edge*** matrix;
	
	
public:
	vector<edge*> e;
	int v_sz;
	int max_sz;
	int e_sz;
	graph(int sz)
	{
		max_sz = sz;
		v_sz = 0;

		v = new vertex*[sz + 1]; //�迭 ���� (���� �迭)
		for (int i = 0; i <= sz; i++)
		{
			v[i] = NULL; //�迭 ���� �ʱⰪ NULL; 
		}
		matrix = new edge**[sz + 1]; // ��� ���� (2���� �迭)
		for (int i = 0; i <= sz; i++)
		{
			matrix[i] = new edge*[sz + 1]; // 2���� �迭�� �ι�° �׸� ����(x,y��)
			for (int j = 0; j <= sz; j++)
			{
				matrix[i][j] = NULL; // ��� ���� �ʱⰪ NULL;
			}
		}
		//int a = 50;
		//int* b = &a;
		//b = new int[sz];
	}

	void insert_vertex(int n) // n�̶�� index�� ���� �ְڴ�.
	{
		if (v_sz + 1 > max_sz) return; // �迭 ������ �̹� ��á��
		if (v[n] == NULL) // ����
		{
			vertex* newV = new vertex();
			v[n] = newV;
			v_sz++;
		}
		else // �̹� v[n]�� ���� ����
			return;

	}

	void insert_edge(int src, int dis)
	{
		if (v[src] == NULL || v[dis] == NULL) {// �� ���� index�� �ϳ��� �������� �ʴ´ٸ� ������ ���� �� ���� -> ����
			cout << 0 << endl;
			return;
		}

		if (matrix[src][dis] != NULL || matrix[dis][src] != NULL) {
			cout << 0 << endl;
			return;
		}
		// �� ���� �ϳ��� ���� ���� �����Ѵٴ� ������ �̹� ����Ǿ� �ִٴ� �Ҹ� ����

		edge* new_e = new edge(v[src], v[dis]);
		matrix[src][dis] = new_e;
		matrix[dis][src] = new_e;

		v[src]->increase_deg();
		v[dis]->increase_deg();

		e.push_back(new_e);
		e_sz++;
	}
	void insert_edge2(int src, int dis, string ma)
	{
		if (v[src] == NULL || v[dis] == NULL) {// �� ���� index�� �ϳ��� �������� �ʴ´ٸ� ������ ���� �� ���� -> ����
			cout << 0 << endl;
			return;
		}

		if (matrix[src][dis] != NULL || matrix[dis][src] != NULL) {
			cout << 0 << endl;
			return;
		}
		// �� ���� �ϳ��� ���� ���� �����Ѵٴ� ������ �̹� ����Ǿ� �ִٴ� �Ҹ� ����

		edge* new_e = new edge(v[src], v[dis], ma);
		matrix[src][dis] = new_e;
		matrix[dis][src] = new_e;

		v[src]->increase_deg();
		v[dis]->increase_deg();

		e.push_back(new_e);
		e_sz++;
	}


	void getVE()
	{
		cout << v_sz << " " << e.size() << endl;
	}

	void delete_edge(int src, int dis)
	{
		if (matrix[src][dis] == NULL || matrix[dis][src] == NULL)
		{
			//cout << -1 << endl;
			return;
		}
		if (v[src] != NULL)
			v[src]->decrease_deg();
		if (v[dis] != NULL)
			v[dis]->decrease_deg();
		for (int i = 0; i < e.size(); i++) //���� e�� edge ���� ����
		{
			if (e[i] == matrix[src][dis] || e[i] == matrix[dis][src])
			{	
				string out = e[i]->mass;
				e.erase(e.begin() + i);
				//cout << out << " ";
				break;
				e_sz--;
			}
		}


		matrix[src][dis] = NULL; // ���� �ʱ�ȭ �Ѱ�ó��( ���� ��ó��) ����� ��
		matrix[dis][src] = NULL;

	}

	void delete_vertex(int V)
	{
		if (v[V] == NULL) // �ش� vertex ���ʿ� ���� X
		{
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < max_sz; i++) // V�� ���� ��� �� ��ŭ Ž�� v[V]->get()
		{
			if (v[V]->get() == 0)
			{
				break;
			}
			delete_edge(V, i);
			//delete_edge(i, V);
		}

		v[V] = NULL;

		v_sz--;
		//getVE();
	}
};



int main()
{
	int N, M, K;

	cin >> N >> M >> K;
	graph G(1000); //G(N)�� �ƴѰ�?
	for (int i = 0; i < N; i++)
	{
		int I;
		cin >> I;
		G.insert_vertex(I);
	}
	for (int i = 0; i < M; i++)
	{
		int	u, v;
		string ms;
		cin >> u >> v >> ms;
		G.insert_edge2(u, v, ms);
	}
	for (int i = 0; i < K; i++)
	{
		int L;
		cin >> L;
		G.delete_vertex(L);
		for (int i = 0; i < G.e.size(); i++)
		{
			cout << G.e[i]->mass << " ";
		}
		cout << endl;
	}
	//G.getVE();
}