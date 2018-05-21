#include <bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;
Node* insert_bst (Node *root,int item)
{	if (root==NULL)  //if its an empty BST
	{	root=new Node;
		root->data=item;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{	if (item<=root->data)
		{	root->left=insert_bst(root->left,item);
		}
		if (item>root->data)
		{
			root->right=insert_bst(root->right,item);
		}
		return root;
	}
}
void pre_order (Node* root)
{	if (root!=NULL)
	{	cout<<" "<<root->data;
		pre_order(root->left);
		pre_order(root->right);
	}
}

int main()
{	Node* root=NULL;
	root=insert_bst(root,10);
	insert_bst(root,19);
	insert_bst(root,5);
	insert_bst(root,1);
	insert_bst(root,6);
	insert_bst(root,17); 
	cout<<"\n pre_order Traversal : \n";
	pre_order(root);

	
	return 0;
} 