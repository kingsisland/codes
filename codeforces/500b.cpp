#include <bits/stdc++.h>
using namespace std;
void ConnectedComponents(int v,bool visited[],vector <int> adj[], int a[], set <int> &nodes,set <int> &values)
{	visited[v]=true;
	nodes.insert(v);
	values.insert(a[v]);

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])
			ConnectedComponents(*i, visited, adj,a, nodes, values);
	}

}
int main()
{	int n,a[305];
	
	vector <int> adj[305];

	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}

	for (int i = 1; i <= n; ++i)
	{	string e;
		cin>>e;
		for (int j = 1; j <= n; ++j)
		{	
			if(e[j-1]== '1')
			{
				adj[i].push_back(j);

			}
		}
	}

	bool *visited=new bool[305];
	for (int i = 0; i < 305; ++i)
	{
		visited[i]=false;
	}

	for(int i=1;i<=n;i++)
	{	
		if(!visited[i])
		{
			set <int> nodes;
			set <int> values;
			ConnectedComponents(i,visited,adj,a,nodes,values);
			for (auto j = nodes.begin(), k=values.begin() ; j != nodes.end() && k != values.end(); ++j, ++k)
			{
				a[*j]=*k;
			}
		}



	}



	for (int i = 1; i <= n; ++i)
	{
		printf("%d ",a[i]);
	}




	return 0;
}