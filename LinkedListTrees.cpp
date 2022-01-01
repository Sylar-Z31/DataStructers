#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node* left;
	Node* right;

}Node;

// Main node
Node* root = nullptr;

// Instertion
Node* Insertion(Node* _root, int _data)
{
	// the tree is empty
	if (_root == nullptr)
	{
		_root = new Node;
		_root->left = nullptr;
		_root->right = nullptr;
		_root->data = _data;

		return _root;
	}
	if (_root->data < _data)
	{
		_root->right = Insertion(_root->right, _data);
		return _root;
	}
	_root->left = Insertion(_root->left, _data);

	return _root;
}

// Infýx = left,root,right || right, root, left ! 
// Prefix = root, left, right || root, right, left
// Postfix = left, right, root || right, left, root
void Traverse(Node* _root)
{
	if (_root == nullptr) { return; }
	Traverse(_root->left);
	cout << _root->data << " ";
	Traverse(_root->right);
}

// Search
int Search(Node* _root, int Sdata)
{
	if (_root == nullptr) { return -1; }
	if (_root->data == Sdata) { return 1; }
	if (Search(_root->right, Sdata) == 1) { return 1; }
	if (Search(_root->left, Sdata) == 1) { return 1; }

	return -1;
}

// Max
int Max(Node* _root)
{
	while (_root->right != nullptr)
		_root = _root->right;

	return _root->data;
}
// Min
int Min(Node* _root)
{
	while (_root->left != nullptr)
		_root = _root->left;
	return _root->data;
}

// Main
int main()
{
	root = Insertion(root, 12);
	root = Insertion(root, 200);
	root = Insertion(root, 190);
	root = Insertion(root, 213);
	root = Insertion(root, 56);
	root = Insertion(root, 24);
	root = Insertion(root, 18);
	root = Insertion(root, 27);
	root = Insertion(root, 28);
	Traverse(root);
	cout << endl << Search(root, 28) << endl;
	cout << endl << "MIN: " << Min(root) << ", MAX: " << Max(root) << endl;


	return 0;
}