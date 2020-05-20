#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct card
{
	int x;
	int y;
	int target = 0;
};
struct dist
{
	card c1;
	card c2;
	int distance = 0;
};

vector<dist> DistVec[26];
void distMake(vector<card> &cardVec[26], int cardShape)
{
	for (int i = 0; i < cardVec[i].size()-1; i++)
	{
		for (int j = i+1; j < cardVec[i].size()-1; j++)
		{
			dist D;
			if ((cardVec[j].y < cardVec[i].y) || (cardVec[j].y == cardVec[i].y && cardVec[j].x < cardVec[i].x))
			{
				D.c1 = cardVec[j];
				D.c2 = cardVec[i];
			}
			else
			{
				D.c1 = cardVec[i];
				D.c2 = cardVec[j];
			}
			D.distance = pow((D.c1.x - D.c2.x), 2) + pow((D.c1.y - D.c2.y), 2);
			DistVec.push_back(D);

		}
		sort(DistVec.begin(), DistVec.end(), comparerule);
		for (int i = 0; i < DistVec.size(); i++)
		{
			if (DistVec[i].distance != -1)
			{
				cout << DistVec[i].c1.x << " " << DistVec[i].c2.x << " " << DistVec[i].c1.y
					<< " " << DistVec[i].c2.y << endl;
				for (int j = i+1; j < DistVec.size(); j++)
				{
					if (DistVec[i].c1 == DistVec[j].c1 || DistVec[i].c2 == DistVec[j].c2)
					{

					}
				}
			}
		}
	}
}


void comparerule(dist a, dist b)
{
	return (a.distance < b.distance) ||
		(a.distance == b.distance && a.c1.y + a.c2.y < b.c1.y + b.c2.y) ||
		(a.distance == b.distance && a.c1.y + a.c2.y < b.c1.y + b.c2.y && a.c1.x + a.c2.x < b.c1.x + b.c2.x);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N, T, M;
	cin >> T;
	vector<pair<int, int> > cardVec;
	vector<card> cardVector[26];
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		char c;
		for (int j = 0; j < M; j++)
		{	

			
			int x, y;
			cin >> c >> x >> y;

			card Card;
			Card.x = x;
			Card.y = y;
			
			cardVector[c-'A'].push_back(Card);
			//cardVec.push_back(Card);
			
		}
		int cardShape = c - 'A';
		for (int j = 0; j < 26; j++) // 0 = 'A' 25 = 'Z'
		{
			if (cardVector[cardShape].empty() != true)
			{
				distMake(cardVector[j], cardShape);
			}
		}
	}
	return 0;
}