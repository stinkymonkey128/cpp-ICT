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
	nodePtr last;
};

void insertInOrder(listType& list, nodePtr node);
void printList(listType&);
nodePtr search(listType& list, int id);
void removeNode(listType& list, int id);
void clearList(listType& list);
int countNodes(listType& list);

int main() {
	listType L = listType();

	ifstream fr("C:\\Users\\gener\\Desktop\\Volume 3\\numbers\\file20.txt");

	for (int i = 0; i < 20; i++) {
		int id, inv;
		fr >> id >> inv;
		nodePtr node = new listNode(id, inv, NULL);
		insertInOrder(L, node);
	}

	fr.close();

	printList(L);
	removeNode(L, 100);
	printList(L);
	cout << countNodes(L) << endl;
	clearList(L);
	cout << countNodes(L) << endl;
}

void insertInOrder(listType& list, nodePtr node) {
	if (list.first == NULL) 
		list.first = list.last = node;
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

			if (cur == NULL)
				list.last = cur;
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

				if (pre->next == NULL)
					list.last = pre;

				delete cur;
			}
		}
	}
}

void clearList(listType& list) {
	nodePtr cur = list.first, pre = NULL;
	list.first = list.last = NULL;

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