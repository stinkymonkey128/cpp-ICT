#include <iostream>
#include <fstream>

using namespace std;

struct listNode
{
	int  id, inv;
	listNode* next;

	listNode(int, int, listNode*);
};

listNode::listNode(int tempId, int tempInv, listNode* nxt)
	: id(tempId), inv(tempInv), next(nxt)
{
}

typedef listNode* nodePtr;

struct listType
{
	nodePtr first;
};

void insert(listType& list, int id, int inv);
void insertInOrder(listType& list, nodePtr node);
void printList(listType&);
nodePtr search(listType& list, int id);
void removeNode(listType& list, int id);
void clearList(listType& list);
int countNodes(listType& list);
nodePtr merge(nodePtr A, nodePtr B);
void split(nodePtr og, nodePtr* A, nodePtr* B);
void mergeSort(nodePtr* list);
void reverseList(nodePtr& root);

int main() {
	listType L = listType();

	ifstream fr("C:\\Users\\gener\\Desktop\\Volume 3\\numbers\\file20.txt");

	for (int i = 0; i < 20; i++) {
		int id, inv;
		fr >> id >> inv;
		nodePtr node = new listNode(id, inv, NULL);
		insert(L, id, inv);
	}

	fr.close();

	printList(L);
	removeNode(L, 100);
	printList(L);
	cout << countNodes(L) << endl;
	mergeSort(&L.first);
	cout << countNodes(L) << endl;
	printList(L);
}

void insert(listType& temp, int id, int inv)
{
	nodePtr node = new listNode(id, inv, NULL);

	if (temp.first == NULL) {
		temp.first = node;
	}
	else {
		node->next = temp.first;
		temp.first = node;
	}

}

void insertInOrder(listType& list, nodePtr node) {
	if (list.first == NULL)
		list.first = node;
	else {
		nodePtr pre = NULL, cur = list.first;

		while (cur != NULL && cur->id < node->id) {
			pre = cur;
			cur = cur->next;
		}

		if (pre == NULL) {
			list.first = node;
			node->next = cur;
		}
		else {
			pre->next = node;
			node->next = cur;
		}
	}
}

void printList(listType& temp) {
	nodePtr current = temp.first;
	while (current != NULL)
	{
		cout << current->id << "   ";
		current = current->next;
	}
	cout << endl;
}

nodePtr search(listType& list, int id) {
	if (list.first != NULL) {
		nodePtr cur = list.first;

		while (cur != NULL)
			if (cur->id == id)
				return cur;
			else
				cur = cur->next;
	}

	return NULL;
}

void removeNode(listType& list, int id) {
	if (list.first != NULL) {
		nodePtr cur = list.first, pre = NULL;

		if (cur->id == id) {
			list.first = cur->next;
			delete cur;
		}
		else {
			while (cur != NULL && cur->id != id) {
				pre = cur;
				cur = cur->next;
			}

			if (cur != NULL) {
				pre->next = cur->next;

				delete cur;
			}
		}
	}
}

void clearList(listType& list) {
	nodePtr cur = list.first, pre = NULL;
	list.first = NULL;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
		delete pre;
	}
}

int countNodes(listType& list) {
	int count = 0;
	nodePtr cur = list.first;

	while (cur != NULL) {
		cur = cur->next;
		count++;
	}

	return count;
}

nodePtr merge(nodePtr A, nodePtr B) {
	nodePtr root = NULL;

	if (A == NULL)
		return B;
	if (B == NULL)
		return A;

	if (A->id <= B->id) {
		root = A;
		root->next = merge(A->next, B);
	}
	else {
		root = B;
		root->next = merge(A, B->next);
	}

	return root;
}

void split(nodePtr og, nodePtr* A, nodePtr* B) {
	nodePtr a = og, b = og->next; // a is continous main line

	while (b != NULL) {
		b = b->next;
		
		if (b != NULL) {
			a = a->next;
			b = b->next;
		}
	}

	*A = og;
	*B = a->next;

	a->next = NULL;
}

void mergeSort(nodePtr* list) {
	nodePtr root = *list, A = NULL, B = NULL;

	if (root != NULL && root->next != NULL) {
		split(root, &A, &B);
		mergeSort(&A);
		mergeSort(&B);
		*list = merge(A, B);
	}
}

void reverseList(nodePtr& root) {
	nodePtr current = root, prev = NULL, next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	root = prev;
}
