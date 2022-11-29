#include <iostream>
#include <fstream>

using namespace std;

struct treeNode
{
	int  id, inv;
	treeNode* left, * right;

	treeNode(int, int, treeNode*, treeNode*);
};

treeNode::treeNode(int tempId, int tempInv, treeNode* tempLeft, treeNode* tempRight)
	: id(tempId), inv(tempInv), left(tempLeft), right(tempRight)
{
	// all values initialized using initializer list
}

typedef treeNode* treePtr;

void readData(treePtr& root);
treePtr insert(treePtr root, int id, int inv);
treePtr search(treePtr root, int id);
treePtr deleteNode(treePtr root, int id);
int countNodes(treePtr root);
void printInOrder(treePtr root);

int main() {
	treePtr root = NULL;
	int inputNum = -1;
	
	while (inputNum != 0) {
		cout << "\n\n\n(1)   Read a file from disk, build the binary tree" << endl;
		cout << "(2)   Print the tree in order" << endl;
		cout << "(3)   Search the tree" << endl;
		cout << "(4)   Delete from the tree" << endl;
		cout << "(5)   Count the nodes in the tree" << endl;
		cout << "(0)   To Quit" << endl << endl << ">> ";

		cin >> inputNum;

		int auxIn = 0;
		treePtr sea;

		switch (inputNum) {
		case 0:
			return 1;
		case 1:
			readData(root);
			cout << "File Read";
			break;
		case 2:
			printInOrder(root);
			break;
		case 3:
			cout << "\n\nInput the ID to search >> ";
			cin >> auxIn;
			sea = search(root, auxIn);
			if (sea == NULL)
				cout << "\nID not found!";
			else
				cout << "\nID found! ID: " << sea->id << " INV: " << sea->inv;
			break;
		case 4:
			cout << "\n\nInput the ID to delete >> ";
			cin >> auxIn;
			sea = deleteNode(root, auxIn);
			if (sea == NULL)
				cout << "\nID not found!";
			else
				cout << "\nID deleted! ID: " << sea->id << " INV: " << sea->inv;
			break;
		case 5:
			countNodes(root);
			break;
		default:
			cout << "Invalid Input!";
			break;
		}
	}
}

void readData(treePtr& root) {
	ifstream fr("C:\\Users\\gener\\Desktop\\Volume 3\\numbers\\file20.txt");

	for (int i = 0; i < 20; i++) {
		int id, inv;
		fr >> id >> inv;
		root = insert(root, id, inv);
	}

	fr.close();
}

treePtr insert(treePtr root, int id, int inv) {
	
	if (root == NULL)
		return new treeNode(id, inv, NULL, NULL);
	else
	{
		treePtr cur;

		if (id <= root->id) {
			cur = insert(root->left, id, inv);
			root->left = cur;
		}
		else {
			cur = insert(root->right, id, inv);
			root->right = cur;
		}
		return root;
	}
}

treePtr search(treePtr root, int id) {
	if (root == NULL || root->id == id)
		return root;
	if (root->id < id)
		return search(root->right, id);
	return search(root->left, id);
}

treePtr deleteNode(treePtr root, int id) {
	if (root == NULL)
		return root;

	if (root->id < id) {
		root->right = deleteNode(root->right, id);
		return root;
	}
	else if (root->id > id) {
		root->left = deleteNode(root->left, id);
		return root;
	}

	if (root->right == NULL) {
		treePtr temp = root->left;
		delete root;
		return temp;
	} 
	else if (root->left == NULL) {
		treePtr temp = root->right;
		delete root;
		return temp;
	}
	else {
		treePtr parent = root;
		treePtr child = root->right;

		while (child->left != NULL) {
			parent = child;
			child = child->left;
		}

		if (parent != root)
			parent->left = child->right;
		else
			parent->right = child->right;

		root->id = child->id;

		delete child;
		return root;
	}
}

int countNodes(treePtr root) {
	int count = 0;

	if (root != NULL) 
		count += countNodes(root->left) + countNodes(root->right) + 1;

	return count;
}

/*
* for preorder swap print and left 
*/
void printInOrder(treePtr root) {
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->id << " ";
		printInOrder(root->right);
	}
}