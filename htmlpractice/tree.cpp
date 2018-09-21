#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node;
node *root=NULL;
node* insert_node (node* root,int item)
{	//cout<<"yea\n";
	if (root==NULL)
	{	root=new node;
		root->data=item;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if (item<=root->data)
	{	root->left=insert_node(root->left,item);	
	}
	if (item>root->data)
	{
		root->right=insert_node(root->right,item);
	}
	return root;


}
void inorder(node* root)
{	if (root==NULL)
	{	//cout<<"NULL\n";
		return;
	}
	 inorder(root->left);
	cout<<root->data<<"  ";
	 inorder(root->right);
}
void post_order(node* root)
{	if (root!=NULL)
	{	post_order(root->left);
		post_order(root->right);
		cout<<root->data<<" ";
	
	}

}
node* findmin(node* root)
{	while(root->left!=NULL)
	{	root=root->left;
	}
	return root;

}

node* deletenode(node* root,int item)
{	if (root==NULL)
	{	cout<<"\nitem not found\n";
		return root;
	}
	else
	{	if (item<root->data)
		{	root->left=deletenode(root->left,item);
			
			
		}
		else if (item>root->data)
		{
			root->right=deletenode(root->right,item);
			
		}
		else
		{	if (root->left==NULL)
			{	node *temp=root->right;
				delete(root);
				return temp;
			}
			else if (root->right==NULL)
			{	node* temp=root->left;
				delete(root);
				return temp;
			}
			
				node *temp=findmin(root->right);
				cout<<"\nmin root is: "<<temp->data<<endl;
				root->data=temp->data;
				root->right=deletenode(root->right,temp->data);
				
		}return root;

		}
	

}
int main(int argc, char const *argv[])
{	root=insert_node(root,11);
	insert_node(root,85);insert_node(root,20);insert_node(root,5);
	deletenode(root,11);
	inorder(root);
	return 0;
}