#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
using namespace std;
#define _max(x,y) ((x > y) ? x : y)

// class Node ����
class Node
{
public:
	int height;
	int key;
	string value;
	Node *parent, *left, *right;
	Node() {					// ������1
		key = height = 0;
		value = "";
		parent = left = right = NULL;
	};
	Node(int key, string value) {	// ������2
		this->key = key;
		this->value = value;
		parent = left = right = NULL;
	};
};

// class AVLTree (AVL Ʈ��) ����
class AVLTree
{
public:
	Node *root;
	int n;
	AVLTree() {		// ������
		this->root = NULL;
		n = 0;
	};
	Node* find(int key, Node* v);
	Node* insert(int key, string value);

	int height(Node* v);
	void setHeight(Node* v);
	bool isBalanced(Node *v);
	Node* tallGrandChild(Node* v);
	Node* restructure(Node* v);
	void rebalance(Node* v);
	bool isExternal(Node* v);

	int size();
	bool empty();
};

// AVL Ʈ���� size ��ȯ
int AVLTree::size() {
	return n;
}

// AVL Ʈ���� empty ���� ��ȯ
bool AVLTree::empty() {
	return (n == 0);
}

// ���v�� leaf ������� Ȯ��
bool AVLTree::isExternal(Node* v) {
	return (v->left == NULL && v->right == NULL);
}

// ��� v�� ���� ��ȯ
int AVLTree::height(Node* v) {
	if (v == NULL)
		return -1;
	else
		return (isExternal(v)) ? 0 : v->height;
}

// ��� v�� ���� ���
void AVLTree::setHeight(Node* v) {
	int hl = height(v->left);	// height of left child
	int hr = height(v->right);	// height of right child
	v->height = 1 + _max(hl, hr);
}

//  ��� v�� ���� ���� ���� Ȯ��
bool AVLTree::isBalanced(Node *v) {
	int bal = height(v->left) - height(v->right);
	return ((-1 <= bal) && (bal <= 1));
}

// ������ �ұ��� ��� z�� ����, height�� �� ū, z�� grandchld Ž��
Node* AVLTree::tallGrandChild(Node* z) {
	Node* zl = z->left;
	Node* zr = z->right;
	if (height(zl) >= height(zr)) {
		if (height(zl->left) >= height(zl->right))	// �ڽİ� ���� ������ ���ڸ� �켱������ ����
			return zl->left;
		else
			return zl->right;
	}
	else {
		if (height(zr->right) >= height(zr->left))	// �ڽİ� ���� ������ ���ڸ� �켱������ ����
			return zr->right;
		else
			return zr->left;
	}
}



/****************************************************************************************************************************************///�л��� ����. 

Node* AVLTree::restructure(Node* x) {
	// ���� �����ϼ���.
	Node* y = x->parent;
	Node* z = y->parent;
	Node* zpa = z->parent;
	// LL RR LR RL 4���� ���̽�
	if ()
}

/*****************************************************************************************************************************************///�л��� ����





																																		   // ��� v���� root �������� path �� ����� height�� �缳���ϰ� �������� Ȯ��
																																		   // �ұ��� ��尡 ������, restructuring
void AVLTree::rebalance(Node* v) {
	Node *z = v;
	while (z->parent != NULL) {
		z = z->parent;
		setHeight(z);
		if (!isBalanced(z)) {
			Node* x = tallGrandChild(z);
			z = restructure(x);		// -------------------> restructure() �� ���� �����ؾ��մϴ�.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			setHeight(z->left);
			setHeight(z->right);
			setHeight(z);
		}
	}
	root = z;
}



//key�� ���Ե� ��ġ ��ȯ
Node* AVLTree::find(int key, Node* v) {
	Node* leafNode;
	leafNode = NULL;

	while (v != NULL) {
		leafNode = v;
		if (key < v->key)
			v = v->left;
		else if (key > v->key)
			v = v->right;
		else
			return v;
	}

	// leaf���� ������ ���, leaf��带 ��ȯ�Ѵ�. 
	return leafNode;
}


//��� ����
Node* AVLTree::insert(int key, string value) {
	Node *curLeafNode = find(key, root);
	Node *newNode = new Node(key, value);
	Node *insertNode = new Node();

	if (key < curLeafNode->key)	// �����Ϸ��� key�� ���� leaf����� key���� ���� ���
	{
		curLeafNode->left = newNode;
	}
	else 	// �����Ϸ��� key��  ���� leaf����� key���� ū ���
	{
		curLeafNode->right = newNode;
	}
	newNode->parent = curLeafNode;
	n++;

	// restructure �� height ����
	setHeight(newNode);
	rebalance(newNode);


	// ���Ե� AVL tree�� ����� height ���
	insertNode = find(key, root);
	cout << insertNode->value << " " << insertNode->height << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	int t, key;
	string instruct;
	AVLTree T;

	cin >> t;
	while (t--) {
		Node* tempNode;
		cin >> instruct;
		if (instruct == "find") {

			cin >> key;
			Node* fnode = T.find(key, T.root);
			///�л��� ����.
			// �ش� �Է¿� ���� ������ ����ó��  ��µǵ��� �����ϼ���. 
			///�л��� ����.
			cout << fnode->value << " " << fnode->height << endl;

		}

		else if (instruct == "insert") {
			cin >> key >> instruct;
			if (T.empty()) {
				T.root = new Node(key, instruct);
				T.n++;
				cout << T.root->value << " " << T.root->height << endl;
			}
			else
				T.insert(key, instruct);
		}
	}
	return 0;
}