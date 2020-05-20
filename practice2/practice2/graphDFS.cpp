#include <iostream>
#include <vector>
#include <string>

using namespace std;

class vertex
{
public:
	int degree;
	bool visited;
	vertex()
	{
		degree = 0;
		visited = false;
	}

	void setDegree()
	{
		degree++;
	}

	void minusDegree()
	{
		if (degree == NULL)
			return;
		degree--;
	}

	int getDegree()
	{
		return degree;
	}

	bool getVisited()
	{
		return visited;
	}
	void setVisited()
	{
		visited = false;
	}
};

class edge
{
public:

	vertex* src;
	vertex* des;
	bool explore;
	bool discovery;
	bool back;
	edge(vertex* a, vertex* v)
	{
		src = a;
		des = v;
		explore = false;
		discovery = false;
		back = false;
	}

	bool get_explore() {
		return explore;
	}

	bool get_discovery()
	{
		return discovery;
	}
	bool get_back()
	{
		return back;
	}

	bool set_explore()
	{
		explore = true;
	}
	bool set_discovery()
	{
		discovery = true;
	}
	bool set_back()
	{
		back = true;
	}

};

class graph
{	
public:

	vertex** v;
	edge*** matrix;
	int max_sz;
	int v_sz;
	vector<edge*> e_list;
	graph(int sz)
	{
		max_sz = sz;
		//vertex**v[sz];
		v_sz = 0;
		v = new vertex*[sz + 1]; // �迭 ����
		for (int i = 0; i < max_sz; i++)
		{
			v[i] = NULL;
		}
		matrix = new edge**[sz + 1];
		for (int i = 0; i < max_sz; i++)
		{	
			matrix[i] = new edge*[sz + 1];
			for (int j = 0; j < max_sz; j++)
			{
				matrix[i][j] = NULL;
			}
		}
	}

	void insert_edge(int x, int y)
	{
		if (v[x] == NULL || v[y] == NULL) // ���߿� �ϳ��� ��
			return;
		if (matrix[x][y] != NULL || matrix[y][x] != NULL) //�� �� �� �ϳ��� ������� ���� = �̹� ����� �ִ� ���� ����
			return;
		v[x]->setDegree();
		v[y]->setDegree(); // degree �߰�
		edge* newEdge = new edge(v[x], v[y]);
		matrix[x][y] = newEdge;
		matrix[y][x] = newEdge;
		e_list.push_back(newEdge);

	}
	void delete_edge(int x, int y)
	{
		if (v[x] == NULL || v[y] == NULL) // ���߿� �ϳ��� ��
			return;
		if (matrix[x][y] == NULL || matrix[y][x] == NULL)
			return;

		v[x]->minusDegree();
		v[y]->minusDegree();

		for (int i = 0; i < e_list.size(); i++)
		{
			if (e_list[i] == matrix[x][y] || e_list[i] == matrix[y][x])
			{
				e_list.erase(e_list.begin() + i);
				break;
			}
		}

		matrix[x][y] = NULL;
		matrix[y][x] = NULL;
		

	}
	void insert_vertex(int x)
	{	 
		if (v_sz+1 > max_sz) //�迭 ���� �ʰ�
		{
			return;
		}
		if (v[x] != NULL)
		{
			return; // v[x]�� ���� �̹� ������ ��� ���� Ȥ�� ���ٲ�
		}
		vertex* newV = new vertex();
		v[x] = newV;
		v_sz++;
	}

	void delete_vertex(int x)
	{
		if (v[x] == NULL) // ���ʿ� ���� X
			return;
		for (int i = 0; i < max_sz; i++)
		{	
			if (v[x]->degree == 0) //degree == 0�� �̹� edge �������� ����
			{
				break;
			}
			delete_edge(x, i);
		}
		v[x] = NULL;
		v_sz--;
	}

	void DFS(int st) // ������ �������� ����� ���� Ž��
	{
		if (v[st] == NULL)
			return; //���ʿ� �������� ����
		if (v[st]->getVisited() == true)
			return; // �̹� �湮 �� ����
		v[st]->setVisited();
		
		for (int i = 0; i < max_sz; i++) // v[st]�� ���� ��� v[i]�� �����ؾ���(matrix)��
		{ 
			if (matrix[st][i] != NULL || matrix[i][st] != NULL) // �ش� �ϴ°��� edge�� �����ϸ�
			{
				if (v[i]->getVisited() == false)
				{
					matrix[st][i]->set_discovery();
					matrix[st][i]->set_explore();
					//matrix[i][st]->set_discovery();
					//matrix[i][st]->set_explore();
					DFS(i);
				}
				else // �̹� visited
				{
					if (matrix[st][i]->get_discovery() == true) //|| matrix[i][st]->get_discovery()==true)
					{
						continue;
					}
					else
					{

						matrix[st][i]->set_back();
						matrix[st][i]->set_explore();
					}
				}
			}
		}
	}
};

int main()
{
	int N;
	graph G(101);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		G.insert_vertex(i + 1);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		G.insert_edge(a, b);
	}
	G.DFS(1);
}