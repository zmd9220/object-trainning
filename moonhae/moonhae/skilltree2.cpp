#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>


using namespace std;

struct skill {
	int parent;
	bool exist_parent = false;
};


vector<int> a_parent;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	bool exist = false;
	int t, n, m, first, second;
	int a, b;

	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n >> m;
		skill arr[10001];

		for (int i = 0; i < n - 1; i++) {
			cin >> first >> second;

			arr[second].parent = first;
			arr[second].exist_parent = true;
		}

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			exist = false;
			while (arr[a].exist_parent) {
				a_parent.push_back(a);
				a = arr[a].parent;
			}

			while (arr[b].exist_parent) {
				for (int j = 0; j < a_parent.size(); j++) {
					if (b == a_parent[j]) {
						exist = true;
						break;
					}
				}

				if (exist) {
					break;
				}

				b = arr[b].parent;


			}

			cout << b << '\n';
			a_parent.clear();
		}
	}

}