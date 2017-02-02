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

//####################################################################
//#																   #
//#		/*Definition the Node*/                                    #
//#																   #
//####################################################################

node::node (void)
{
	data = 0;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}

//####################################################################
//#																   #
//#		/*The interface of the Binary Search Tree class*/          #
//#																   #
//####################################################################

class bst
{
public:
	node* root;
	void insert (int);
	void deleter (node*);
	void display (node*, int);
	node* search (int);
	int level (node*);
	void spacetab (int);
	void space (int);
	void display2 ();
	void interchange (node*, node*);
	node* successor (node*);
	void inorder(node*);
	void display3 (node*);
};

//####################################################################
//#																   #
//#		/*A function that gonna use in display functions*/         #
//#																   #
//####################################################################

void bst::spacetab (int count)
{
	for (int i=0; i < count; i++)
		cout << "    ";
}

//####################################################################
//#																   #
//#		/*Another function that gonna use in display functions*/   #
//#																   #
//####################################################################

void bst::space (int count)
{
	for (int i=0; i < count; i++)
		cout << " ";
}

//####################################################################
//#																   #
//#		/*Implemetation of the insert function*/ 	    	       #
//#																   #
//####################################################################

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
			if (newNode->data <= tempNode1->data)
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

//####################################################################
//#																   #
//#		/*Afunction for calculate the tree's height*/ 	    	   #
//#																   #
//####################################################################

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

//####################################################################
//#																   #
//#		/*The search function of the tree*/ 	   				   #
//#																   #
//####################################################################

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

//####################################################################
//#																   #
//#		/*This is a function that used in delete function*/ 	   #
//#																   #
//####################################################################

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

//####################################################################
//#																   #
//#		/*This is a function that used in delete function*/ 	   #
//#																   #
//####################################################################

node* bst::successor(node* currentNode)
{
	node* tempNode = new node();
	node* backTempNode = new node();
	tempNode = currentNode;

	if (tempNode->rightChild != NULL)
	{
		tempNode = tempNode->rightChild;
		while (tempNode != NULL)
		{
			backTempNode = tempNode;
			tempNode = tempNode->leftChild;
		}
		return backTempNode;
	}
	else
	{
		backTempNode = tempNode;
		tempNode = tempNode->parent;
		while (tempNode != NULL && tempNode->rightChild == backTempNode)
		{
			backTempNode = tempNode;
			tempNode = tempNode->parent;
		}
		return tempNode;
	}
}
//####################################################################
//#																   #
//#		/*The delete function of the Binary Search Tree*/ 		   #
//#																   #
//####################################################################

void bst::deleter (node* number)
{
	if (number->rightChild == NULL || number->leftChild == NULL)
	{
		node* p = number->parent;
		if (p == NULL)
		{
			if (number->rightChild != NULL)
				root = number->rightChild;
			else
				root = number->leftChild;
		}
		else if (p->rightChild == number)
		{
			if (number->rightChild != NULL)
				p->rightChild = number->rightChild;
			else
				p->rightChild = number->leftChild;
		}
		else
		{
			if (number->rightChild != NULL)
				p->leftChild = number->rightChild;
			else
				p->leftChild = number->leftChild;
		}
	}
	else
	{
		node* succesor = new node();
			succesor = successor(number);
			if (succesor->parent != number)
			{
				interchange(succesor, succesor->rightChild);
				succesor->rightChild = number->rightChild;
				succesor->rightChild->parent = succesor;
			}
			interchange(number, succesor);
			succesor->leftChild = number->leftChild;
			succesor->leftChild->parent = succesor;
	}

}

//####################################################################
//#																   #
//#		/*Try for display the Binary Search Tree*/ 		   		   #
//#																   #
//####################################################################

void bst::display2 ()
{
	display(root, level(root));
}

//####################################################################
void bst::display(node *Node,int level)
{
	if (root == NULL)
	{
		cout << "Tree is empty." << endl;
	}
	else
	{
		if (Node->rightChild != NULL)
		{
			display(Node->rightChild, level + 1);
		}
		
		if (Node != root)
		{
			for (int i = 0; i < level + 1; i++)
			{
				cout << "      ";
			}
		}
		else
		{
			cout << "->";
		}

		cout << Node->data << endl;

		if (Node->leftChild != NULL)
		{
			display(Node->leftChild, level + 1);
		}
	}

}
//########################################################
void bst::inorder(node* temp)
	{
		if (temp != NULL)
		{

			if (temp->leftChild != NULL)
				display3(temp->leftChild);
			cout << temp->data ;
					spacetab(1) ;
					cout << " ";
			if (temp->rightChild != NULL)
				display3(temp->rightChild);
			
		}
		else 
			cout << "\t\nTree is empty\n" << endl;
	}

//#########################################################
void bst::display3(node* temp)
{
	if (temp != NULL)
	{

		if (temp->leftChild != NULL)
			display3(temp->leftChild);
		cout << temp->data ;
				spacetab(1) ;
				cout << " ";
		if (temp->rightChild != NULL)
			display3(temp->rightChild);
		
	}
	else 
		cout << "\t\nTree is empty\n" << endl;
}

//####################################################################
//#																   #
//#		/*The main function of the Tree*/ 		 	    		   #
//#																   #
//####################################################################

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
					break;
				}

			}
			case 2 :
			{
				int choice;
				cout << "\n\tEnter one of these options :\n\t\t1. Visual display\n\t\t2. Inorder display\n" ;
				cin >> choice;
				if (choice == 1)
				{
					if (tempTree->root != NULL)
					{
						tempTree->display2();
		 				cout << endl;
		 				break;
	 				}
	 				else
	 					cout << "\n\tTree is empty.\n\tPlease insert some integers!\n" << endl;
	 				break;
	 			}
	 			else
	 			{
	 				if (tempTree->root != NULL)
					{
						tempTree->inorder(tempTree->root);
		 				cout << endl;
		 				break;
	 				}
	 				else
	 					cout << "\n\tTree is empty.\n\tPlease insert some integers!\n" << endl;
	 				break;
	 			}
			}

		}
	}
	while (select != 5);
	cout << "\n\tThanks for use me :-)\n" << endl;

	return 0;
}
