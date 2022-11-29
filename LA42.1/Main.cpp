#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct treeNode
{
	char value;
	treeNode* left, * right;

	treeNode(char, treeNode*, treeNode*);
};

treeNode::treeNode(char v, treeNode* tempLeft, treeNode* tempRight)
	: value(v), left(tempLeft), right(tempRight)
{
	// all values initialized using initializer list
}

typedef treeNode* treePtr;

void readData(treePtr& root);
treePtr insert(treePtr root, char v);
void preorder(treePtr root);
void inorder(treePtr root);
void postorder(treePtr root);
int countNodes(treePtr root);
int countLeaves(treePtr root);
int treeHeight(treePtr root);
int treeWidth(treePtr root);
void clear(treePtr root);

void qlevelprint(treePtr root);


int main() {
	treePtr root = NULL;
	int inputNum = -1;

	while (inputNum != 0) {
		cout << "\n\n\n(1)	Fill the tree from a file" << endl;
		cout << "(2)	Preorder ouput" << endl;
		cout << "(3)	Inorder output" << endl;
		cout << "(4)	Postorder output" << endl;
		cout << "(5)	Count the nodes in the tree" << endl;
		cout << "(6)	Count the leaves in the tree" << endl;
		cout << "(7)	Find the height of the tree" << endl;
		cout << "(8)	Find the width of the tree" << endl;
		cout << "(9)	Clear the tree" << endl;
		cout << "(10)   Print by level" << endl;
		cout << "(0)    To Quit" << endl << endl << ">> ";

		cin >> inputNum;

		switch (inputNum) {
		case 0:
			return 1;
		case 1:
			readData(root);
			cout << "Read Data";
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			cout << "\n\nNumber of Nodes: " << countNodes(root);
			break;
		case 6:
			cout << "\n\nNumber of Leaves: " << countLeaves(root);
			break;
		case 7:
			cout << "\n\nTree Height: " << treeHeight(root);
			break;
		case 8:
			cout << "\n\nMaximum Width: " << treeWidth(root);
			break;
		case 9:
			clear(root);
			root = NULL;
			cout << "Tree Cleared!";
			break;
		case 10:
			qlevelprint(root);
			break;
		default:
			cout << "Invalid Input!";
			break;
		}
	}
}

void readData(treePtr& root) {
	ifstream fr("C:\\Users\\gener\\Desktop\\Volume 3\\numbers\\20randomassletters.txt");

	for (int i = 0; i < 20; i++) {
		char v;
		fr >> v;
		root = insert(root, v);
	}

	fr.close();
}

treePtr insert(treePtr root, char v) {

	if (root == NULL)
		return new treeNode(v, NULL, NULL);
	else
	{
		treePtr cur;

		if (v <= root->value) {
			cur = insert(root->left, v);
			root->left = cur;
		}
		else {
			cur = insert(root->right, v);
			root->right = cur;
		}
		return root;
	}
}

void preorder(treePtr root) {
	if (root != NULL) {
		cout << root->value << " ";
		inorder(root->left);
		inorder(root->right);
	}
}

void inorder(treePtr root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}
}

void postorder(treePtr root) {
	if (root != NULL) {
		inorder(root->left);
		inorder(root->right);
		cout << root->value << " ";
	}
}

int countNodes(treePtr root) {
	/*int count = 0;

	if (root != NULL)
		count += countNodes(root->left) + countNodes(root->right) + 1;

	return count;*/

	return root == NULL ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
}

int countLeaves(treePtr root) {
	/*if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeaves(root->left) + countLeaves(root->right);*/

	return root == NULL ? 0 : (root->left == NULL && root->right == NULL) ? 1 : countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(treePtr root) {
	return root == NULL ? 0 : max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

int width(treePtr root, int level) {
	return root == NULL ? 0 : level == 1 ? 1 : width(root->left, level - 1) + width(root->left, level - 1);
}

int treeWidth(treePtr root) {
	int height = treeHeight(root), currentMax = 0;

	for (int i = 0; i < height; i++) {
		int cw = width(root, i);
		if (currentMax < cw) {
			currentMax = cw;
		}
	}

	return currentMax;
}

void clear(treePtr root) {
	if (root != NULL) {
		clear(root->right);
		clear(root->left);
		delete root;
	}
}

void qlevelprint(treePtr root) {
	if (root != NULL) {
		queue<treePtr> que;
		treePtr cur;

		que.push(root);
		que.push(NULL);

		while (que.size() > 1) {
			cur = que.front();
			que.pop();

			if (cur != NULL) {
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
				cout << cur->value << " ";
			}
		}
	}
}