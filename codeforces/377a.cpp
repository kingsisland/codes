#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[550][550];
bool visitedDFS [550][550];


class node{
	public:

		node *parent;
		pair <int, int> pos;
		vector < node* > child;
	};

void display ()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	return;
}


void dfsFindLeaf(int &k, node* root  )
{	//cout<<endl<<"Entered dfsFindLeaf with k  "<<k<<"  root[x][y] wit x "<<root->pos.first<<" and y  "<<root->pos.second<<" and k "<<k<<endl;
	//cout<<" The childCount is "<<root->child.size()<<endl;
	if(k==0)
	{
		return;
	}
	int childCount = root->child.size();
	if( childCount == 0)
	{	//cout<<endl<<"Inside the LEAFNODE \n";
		a[root->pos.first][root->pos.second]='X';
		node* parent=root->parent;
		vector <node* > :: iterator itr= parent->child.begin();
		while(itr != parent->child.end() )
		{
			if(*itr == root)
			{
				parent->child.erase(itr);
				break;
			}
			itr++;
		}

		
		k--;
		//cout<<endl<<"Entered dfsFindLeaf with k  "<<k<<"  LEAFNODE[x][y] wit x "<<root->pos.first<<" y  "<<root->pos.second<<" and k "<<k<<endl;
		delete root;
		return;
	}
	for(int i=0; i< root->child.size(); i++ )
	{	dfsFindLeaf(k, root->child[i]);
	}
	if(k != 0)
	{
		dfsFindLeaf(k, root);
	}
	return;
}







int main()
{	
	for(int i=0 ; i<550 ; i++)
	{
		for(int j=0; j<550; j++)
		{
			visitedDFS[i][j] = false;
		}
	}


	cin>>n>>m>>k;
	node* root= new node;
	int first=0;
	int x[] = {1, -1, 0, 0 };
	int y[] = {0, 0, 1, -1};
	queue <node* > q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j] == '.' && first==0)
			{
				root->parent = NULL;
				root->pos.first = i;
				root->pos.second = j;
				first=1;
			}
			
		}
	}
	//cout<<endl<<"input finished"<<endl;

	//BFS to find the parents and child
	q.push(root);
	visitedDFS[root->pos.first][root->pos.second] = true;
	int posx, posy;
	while(!q.empty())
	{
		node* current=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			posx = current->pos.first + x[i];
			posy = current->pos.second + y[i];


			
			if( posx>=0 && posx < n && posy >= 0 && posy < m && a[posx][posy] == '.' && visitedDFS[posx][posy] == false )
			{	
				//cout<<"\n  current->pos.first is "<< current->pos.first<<"   current->pos.first + x[i] is "<<current->pos.first + x[i]<<endl;
				//cout<<"\n  current->pos.second is "<< current->pos.second<<"   current->pos.second + x[i] is "<<current->pos.second + y[i]<<endl;


				node* child = new node;
				child->parent = current;
				current->child.push_back(child);
				child->pos.first= posx;
				child->pos.second= posy;
				q.push(child);
				visitedDFS[posx][posy] = true;

			}
		}
	}

	dfsFindLeaf(k, root);
	display();
















	

	return 0;
}