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

		v = new vertex*[sz + 1]; //배열 생성 (정점 배열)
		for (int i = 0; i <= sz; i++)
		{
			v[i] = NULL; //배열 내부 초기값 NULL; 
		}
		matrix = new edge**[sz + 1]; // 행렬 생성 (2차원 배열)
		for (int i = 0; i <= sz; i++)
		{
			matrix[i] = new edge*[sz + 1]; // 2차원 배열의 두번째 항목 생성(x,y축)
			for (int j = 0; j <= sz; j++)
			{
				matrix[i][j] = NULL; // 행렬 내부 초기값 NULL;
			}
		}
		//int a = 50;
		//int* b = &a;
		//b = new int[sz];
	}

	void insert_vertex(int n) // n이라는 index에 값을 넣겠다.
	{
		if (v_sz + 1 > max_sz) return; // 배열 상으로 이미 꽉찼음
		if (v[n] == NULL) // 빈경우
		{
			vertex* newV = new vertex();
			v[n] = newV;
			v_sz++;
		}
		else // 이미 v[n]에 값이 존재
			return;

	}

	void insert_edge(int src, int dis)
	{
		if (v[src] == NULL || v[dis] == NULL) {// 두 개의 index중 하나라도 존재하지 않는다면 엣지를 넣을 수 없음 -> 리턴
			cout << 0 << endl;
			return;
		}

		if (matrix[src][dis] != NULL || matrix[dis][src] != NULL) {
			cout << 0 << endl;
			return;
		}
		// 둘 중의 하나라도 무언가 값이 존재한다는 이유는 이미 연결되어 있다는 소리 종료

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
		if (v[src] == NULL || v[dis] == NULL) {// 두 개의 index중 하나라도 존재하지 않는다면 엣지를 넣을 수 없음 -> 리턴
			cout << 0 << endl;
			return;
		}

		if (matrix[src][dis] != NULL || matrix[dis][src] != NULL) {
			cout << 0 << endl;
			return;
		}
		// 둘 중의 하나라도 무언가 값이 존재한다는 이유는 이미 연결되어 있다는 소리 종료

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
		for (int i = 0; i < e.size(); i++) //벡터 e의 edge 정보 삭제
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


		matrix[src][dis] = NULL; // 둘을 초기화 한것처럼( 없는 것처럼) 만들면 됨
		matrix[dis][src] = NULL;

	}

	void delete_vertex(int V)
	{
		if (v[V] == NULL) // 해당 vertex 애초에 존재 X
		{
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < max_sz; i++) // V의 간선 노드 수 만큼 탐색 v[V]->get()
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
	graph G(1000); //G(N)은 아닌가?
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