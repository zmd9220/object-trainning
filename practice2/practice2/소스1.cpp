#include <iostream>
#include <vector>
using namespace std;
int* tree;
int node_s;
class Node {
public:
	Node() {
		parent = NULL;
		data = NULL;
	}
	Node(int d) {
		data = d;
	}
	Node(int d, int s) {
		data = d;
		size = s;
	}
	void setParent(Node* par) {
		parent = par;
	}
	void insertChild(Node* chi) {
		child.push_back(chi);
	}
	void delChild(Node* chi) {
		for (int i = 0; i < child.size(); i++) {
			if (child[i] == chi) {
				child.erase(child.begin() + i);
			}
		}
	}


	int size;
	vector<Node*> child;
	int data;
	Node* parent;
};
class Tree {
public:
	Tree() {
		root = NULL;
	}
	Tree(int d) {
		root = new Node(d);
		node_list.push_back(root);
		tree_size++;
	}
	void insertNode(int parent_data, int d) {
		Node* par;
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == parent_data) {
				par = node_list[i];
				Node* newNode = new Node(d);

				par->insertChild(newNode);
				newNode->setParent(par);
				node_list.push_back(newNode);
			}
		}
		tree_size++;

	}
	void delNode(int d) {
		Node* nowNode;
		Node* par;
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == d) {

				nowNode = node_list[i];
				par = node_list[i]->parent;

				for (int j = 0; j < node_list[i]->child.size(); j++) {
					node_list[i]->insertChild(nowNode->child[j]);
					nowNode->child[j]->setParent(par);
				}
				par->delChild(nowNode);
				node_list.erase(node_list.begin() + i);
				delete nowNode;
			}
		}
		tree_size--;
	}
	void printChild(int d) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == d) {
				if (node_list[i]->child.size() == 0) cout << 0 << endl;
				else {
					for (int j = 0; j < node_list[i]->child.size(); j++) {
						cout << node_list[i]->child[j]->data << " ";
					}
					cout << endl;
				}
			}
		}
	}
	void preOrder(Node* node) {

		cout << node->data << " ";
		for (int i = 0; i < node->child.size(); i++) {
			preOrder(node->child[i]);
		}
	}

	int postOrder(Node* node) {
		for (int i = 0; i < node->child.size(); i++) {
			postOrder(node->child[i]);
		}
		node_s += tree[node->data - 1];
		return node_s;
	}
	void postOrder1(Node* node) {
		for (int i = 0; i < node->child.size(); i++) {
			postOrder(node->child[i]);
		}
		cout << node->data << " ";
	}

	void calcSize(Node* node) {

		for (int i = 0; i < node->child.size(); i++) {
			calcSize(node->child[i]);
		}
		node_s = node_s + node->size;
		cout << node_s << endl;
	}

	Node* find(int q) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == q) {

				return node_list[i];
			}
		}
		return NULL;
	}


	Node* root;
	int tree_size = 0;
	vector<Node*> node_list;
};

int main()
{
	int n, m;
	cin >> n >> m;
	Tree Tr;
	int tmp = n;

	tree = new int[n];

	while (tmp--) {
		int idx, node_size;
		cin >> idx >> node_size;

		tree[idx - 1] = node_size;
	}
	while (n--) {
		int node;
		cin >> node;
		Node* newNode = new Node(node);
		Tr.node_list.push_back(newNode);
		Tr.tree_size++;

		if (node == 1) {
			Tr.root = newNode;
		}
		int child = -1;

		while (child != 0) {
			cin >> child;

			if (child == 0) break;
			Tr.insertNode(node, child);
		}

	}

	while (m--) {
		node_s = 0;
		int q;
		cin >> q;

		cout << Tr.postOrder(Tr.find(q)) << endl;
	}

}