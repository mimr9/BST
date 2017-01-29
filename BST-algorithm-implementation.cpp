#include <iostream>
#include <cstddef>
using namespace std;


class node
{
public:
	int data;
	node* parent;
	node* leftChild;
	node* rightChild;
	node (void);
};

node::node (void)
{
	data = 0;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}

class bst
{
public:
	node* root;
	void insert (int);
	void deletion (int);
	void display ();
	node* search (int);
	int level (node*);
	void spacetab (int);
	void space (int);
	void display2 (node *Node,int level);
};

void bst::spacetab (int count)
{
	for (int i=0; i < count; i++)
		cout << "    ";
}

void bst::space (int count)
{
	for (int i=0; i < count; i++)
		cout << " ";
}

void bst::insert (int number)
{
	node* newNode = new node();
	newNode->data = number;
	if (root == NULL)
		root = newNode;
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

int bst::level(node* aNode) {
    if (aNode == NULL)
        return -1;

    int lefth = level(aNode->leftChild);
    int righth = level(aNode->rightChild);

    if (lefth > righth) {
        return lefth + 1;
    } else {
        return righth + 1;
    }
}

node* bst::search(int element)
{
	node* tempNode = new node();
	node* tempRoot = new node();
	tempRoot = root;
	while (tempRoot != NULL)
	{
		if (element == tempRoot->data)
		{
			return tempRoot;
		}
		if (element <= tempRoot->data)
			tempRoot = tempRoot->leftChild;
		else
			tempRoot = tempRoot->rightChild;

	}
	return NULL;
}

void bst::display2 (node *Node,int level)
{
	if (Node == NULL);
}

void bst::display()
{
	int height = level(root);
	int counter = height;
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	if (level(root) == 0)
	{
		spacetab (1);
		cout << root->data << endl;
	}
	else
	{
		spacetab(counter);
		space(counter);
		cout << root << endl;
		counter--;
		node* tempNode = new node();
		node* tempLeft = new node();
		node* tempRight = new node();
		tempNode = root;
		tempRight = tempNode->rightChild; 
		tempLeft = tempNode->leftChild;
		while (tempRight != NULL || tempLeft != NULL)
		{
			if ( tempLeft != NULL )
			{
				cout << tempLeft->data ;
				spacetab(1) ;
				cout << " ";
				tempLeft = tempLeft->leftChild;
			}
			else
				cout << " " ;
				spacetab(1);
				cout << " ";
		}

	}
}

int main()
{
	bst * tempTree = new bst();
	int select;
	do
	{
		
		cout << "The menu list of the program : \n  Choose your option number\n";
		cout << "\t1. Insert\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit" << endl;
		cin >> select;
		switch (select)
		{
			case 1 :
			{
				int temp = 0;
				cout << "Enter your number (if you wanna quite enter -1)" << endl;
				while (temp != -1)
				{
					cin >> temp;
					tempTree->insert(temp);
				}
				break;
			}
			case 4 : 
			{
				int temp;
				cout << "Enter your number for search, here :" << endl;
				cin >> temp;
				if ( tempTree->search(temp) != NULL )
					cout << "Found!" << endl;
				else
					cout << "Not found!" << endl;
				break;
			}

		}
	}
	while (select != 5);
	cout << "Thanks for use me :-)\n";

	return 0;
}
