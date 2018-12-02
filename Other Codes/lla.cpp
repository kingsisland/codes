#include <bits/stdc++.h>
using namespace std;
typedef struct node
{	int data;
 	struct node* left;
 	struct node* right;
} node;
node* head;
node* current;
void create_node (node* p,int item)
{	if (p==NULL)
	{
		 head=new node;
		 head->data=item;
		 head->left=NULL;
		 head->right=NULL;
		 current=head;
	}
	else
	{	node* newnode=new node;
		newnode->data=item;
		newnode->left=p;
		newnode->right=NULL;
		p->right=newnode;
		current=newnode;
	}
}
void display_list(node* ptr)
{	cout<<endl;
	while(ptr!=NULL)
	{	cout<<ptr->data<<" ";
		ptr=ptr->right;		
	}
}
int main()
{	current=NULL;
	int data,n;
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	while(n--)
	{	cout<<"\nEnter the node's data: \n";
		cin>>data;
		create_node(current,data);
		
	} 
	cout<<"\nDisplaying node's data: \n";
		display_list(head);


	return 0;
}