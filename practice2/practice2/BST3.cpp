
#include <iostream>
using namespace std;
class Node {
public:
	Node() { parent = left = right = NULL; }
	Node(int x) { parent = left = right = NULL; data = x; }
	Node * parent;
	Node* left;
	Node* right;
	int data;
};
class BST {
public:
	BST() { root = NULL; cnt = -1; }
	void insert(int x, Node* node) {
		cnt++;
		if (node == NULL) {
			Node* newNode = new Node(x);
			newNode->parent = NULL;
			root = newNode;
		}
		else {
			if (x > node->data) {
				if (node->right == NULL) {
					Node* newNode = new Node(x);
					newNode->parent = node;
					node->right = newNode;
				}
				else
					insert(x, node->right);
			}
			else {
				if (node->left == NULL) {
					Node* newNode = new Node(x);
					newNode->parent = node;
					node->left = newNode;
				}
				else insert(x, node->left);
			}
		}
	}
	void delNode(int num) {
		Node* n = search(root, num);

		if (n != NULL) {
			if (n->left == NULL)
				transplant(n, n->right);
			else if (n->right == NULL)
				transplant(n, n->left);
			else {
				Node* y = n->right;
				while (y->left != NULL) { p++; y = y->left; }

				if (y->parent != n) {
					transplant(y, y->right);
					y->right = n->right;
					y->right->parent = y;
				}
				transplant(n, y);
				y->left = n->left;
				y->left->parent = y;
			}

		}
	}
	void transplant(Node* par, Node* chi) {
		if (par != NULL) {
			if (par->parent == NULL)
				root = chi;
			else if (par == par->parent->left)
				par->parent->left = chi;

			else par->parent->right = chi;

			if (chi != NULL)
				chi->parent = par->parent;
		}
	}
	Node* search(Node* node, int num) {
		if (node == NULL || node->data == num)
			return node;
		if (node->data < num)
			return search(node->right, num);
		else
			return search(node->left, num);

	}
	void inOrder(Node* node) {
		if (node->left != NULL) inOrder(node->left);
		if (node->data != NULL) cout << node->data << " ";
		if (node->right != NULL) inOrder(node->right);
	}
	int p = 0;
	int cnt;
	Node* root;
};
int main()
{
	int t, m;
	cin >> t >> m;
	BST T;
	while (t--) {
		int num;
		cin >> num;
		T.insert(num, T.root);
	}
	while (m--) {
		int num;
		cin >> num;
		T.delNode(num);
		cout << T.p << endl;
	}
}
