class node
{
public:
	int data;
	node* parent;
	node* LeftChild;
	node* RightChild;
	node (void);
};

node::node (void)
{
	data = 0;
	parent = NULL;
	LeftChild = NULL;
	RightChild = NULL;
}