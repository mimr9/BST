#include "node.h"

class bst
{
	node* root;
	bst (void);
	void insert (int);
	void deletion (int);
	void display (void);
	node* search(int);
};

void bst::insert (int number)
{
	node* newNode = new node();
	newNode->data = number;
	if (root == NULL)
		root = newNode->data;
	else
	{
		node* tempNode1 = new node();
		node* tempNode2 = new node();
		tempNode1 = root;
		while (tempNode1 != NULL)
		{
			tempNode2 = tempNode1;
			if (newNode->data <= root->data)
				tempNode1 = tempNode1->leftChild;
			else
				tempNode1 = tempNode1->rightChild;
		}
		newNode->parent = tempNode2;
		if (tempNode2->data <= newNode->data)
			tempNode2->rightChild = newNode;
		else
			tempNode2->leftChild = newNode;

	}
}