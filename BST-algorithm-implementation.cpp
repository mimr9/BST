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
	void deleter (node*);
	void display (node*);
	node* search (int);
	int level (node*);
	void spacetab (int);
	void space (int);
	void display2 ();
	void interchange (node*, node*);
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
        return lefth;
    } else {
        return righth;
    }
}

node* bst::search(int element)
{
	node* tempRoot = new node();
	tempRoot = root;
	while (tempRoot != NULL)
	{
		if (element == tempRoot->data)
		{
			return tempRoot;
		}
		else
		{
			if (element <= tempRoot->data)
				tempRoot = tempRoot->leftChild;
			else
				tempRoot = tempRoot->rightChild;
		}

	}
	return NULL;
}

void bst::interchange (node* first, node* second)
{
	if (first->parent == NULL)
		root = second;
	else
	{
		if (first->parent->leftChild !=NULL)
			first->parent->leftChild = second;
		else
			first->parent->rightChild = second;

	}
	if (second != NULL)
		second->parent = first->parent;
}

void bst::deleter (node* number)
{
	if (number->leftChild == NULL)
		interchange (number, number->rightChild);
	else
	{
		if (number->rightChild == NULL)
			interchange (number, number->leftChild);
		else
		{
			
		}
	}

}

void bst::display2 ()
{
	display(root);
}

void bst::display(node* temp)
{
	if (temp != NULL)
	{
		if (temp->leftChild != NULL)
			display(temp->leftChild);
		if (temp->rightChild != NULL)
			display(temp->rightChild);
		cout << temp->data ;
				spacetab(1) ;
				cout << " ";
	}
	else 
		cout << "\t\nTree is empty\n" << endl;
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
				do
				{
					cin >> temp;
					if (temp != -1)
						tempTree->insert(temp);
				}
				while (temp != -1);
				cout << endl;
				break;
			}
			case 4 : 
			{
				int temp;
				cout << "\nEnter your number for search, here :" << endl;
				cin >> temp;
				if ( tempTree->search(temp) != NULL )
					cout << "\n\tFound!\n" << endl;
				else
					cout << "\n\tNot found!\n" << endl;
				cout << endl;
				break;
			}
			case 3 :
			{
				int temp;
				cout << "\nEnter your number for deletion, here :" << endl;
				cin >> temp;
				if ( tempTree->search(temp) == NULL )
					cout << "\n\tThere is no such thing !\n" << endl;
				else
				{
					node* tempNode = new node();
					tempNode = tempTree->search(temp);
					tempTree->deleter(tempNode);
					cout << "\n\tThe node is deleted!\n" << endl;
				}

			}
			case 2 :
			{
				//int level = tempTree->level(tempTree->root);
				//cout << "\n\t" << "The Height of the tree is :" << level << endl << endl;
				tempTree->display2();
				cout << endl;
				break;
			}

		}
	}
	while (select != 5);
	cout << "\n\tThanks for use me :-)\n" << endl;

	return 0;
}
