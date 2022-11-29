#include <iostream>

using namespace std;

struct listNode
{
	int  data;
	listNode* next;

	listNode(int, listNode*);	
};

listNode::listNode(int tempData, listNode* tempNext)
{
	data = tempData;
	next = tempNext;
}

typedef  listNode* listPtr;

struct  listType
{
	listPtr  first;
	listPtr  last;
};


typedef listNode* nodePtr;

void printList(listType&);
void insert(listType& temp, int value);

int main()
{
	listType L = listType();

	for (int k = 1; k <= 20; k++)
		insert(L, k);

	printList(L);
}

void insert(listType& temp, int value)
{
	nodePtr node = new listNode(value, NULL);

	if (temp.first == NULL) {
		temp.first = temp.last = node;
	}
	else {
		temp.last->next = node;
		temp.last = node;
	}

}

void printList(listType& temp)
{
	listPtr current = temp.first;
	while (current != NULL)
	{
		cout << current->data << "   ";
		current = current->next;
	}
}