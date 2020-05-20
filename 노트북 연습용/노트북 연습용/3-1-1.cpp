#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Card {
public:
	int x;
	int y;
	bool invalid;
	Card(int _x, int _y) {
		x = _x;
		y = _y;
		invalid = false;
	}
};

class CardPair {
public:
	Card* c1;
	Card* c2;
	int dist;
	void setPair(Card* _c1, Card* _c2) {
		if ((_c1->y < _c2->y) || ((_c1->y == _c2->y) && (_c1->x < _c2->x))) {
			c1 = _c1;
			c2 = _c2;
		}
		else {
			c1 = _c2;
			c2 = _c1;
		}
		dist = calc_dist();
	}
	int calc_dist() {
		return pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2);
	}
	bool isInvalid() {
		if (c1->invalid || c2->invalid) {
			return true;
		}
		return false;
	}

	void printPairs() {
		cout << c1->x << " " << c1->y << " " << c2->x << " " << c2->y << endl;
	}
	bool operator<(const CardPair& c)const {
		if (dist != c.dist)
			return dist > c.dist;
		if ((c1->y + c2->y) != (c.c1->y + c.c2->y))
			return (c1->y + c2->y) > (c.c1->y + c.c2->y);
		return (c1->x + c2->x) > (c.c1->x + c.c2->x);
	}
};

vector<Card*> cards[26];
vector<CardPair> pairs[26];

int main() {
	int T, n, m, x, y;
	char shape;
	CardPair p;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 26; i++) {
			cards[i].clear();
			pairs[i].clear();
		}

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> shape >> x >> y;
			cards[shape - 'A'].push_back(new Card(x, y));
			for (int j = 0; j < cards[shape - 'A'].size() - 1; j++) {
				p.setPair(cards[shape - 'A'][j], cards[shape - 'A'].back());
				pairs[shape - 'A'].push_back(p);
			}
		}
		for (int i = 0; i < 26; i++) {
			sort(pairs[i].begin(), pairs[i].end());

			while (!pairs[i].empty()) {
				if (!pairs[i].back().isInvalid()) {
					p = pairs[i].back();
					p.c1->invalid = true;
					p.c2->invalid = true;
					cout << char(i + 'A') << " ";
					p.printPairs();
				}
				pairs[i].pop_back();
			}
		}
	}

}