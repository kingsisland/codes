#include <bits/stdc++.h>
using namespace std;
long totalways=0;

void DFSutill(long n,long m, vector <long> edges[], long cats[], bool visited[], long count, long v )
{	
	visited[v]=true;
	if(cats[v] == 1 && count > 0)
	{
		
			count++;
			if( m < count )
		{	//cout<<"\n Returning as M is exceeded. The vertex is : "<<v<<" and count currently is : "<<count<<" and adjacent nodes size is : "<<edges[v].size()<<endl;
			return;
		}
	}
	
	else if(cats[v] == 1 && count == 0)
	{	count=1;

	}
	else
	{	
		//consequtive=false;
		count=0;
	}
	//cout<<"\n The vertex is : "<<v<<" and count currently is : "<<count<<" and adjacent nodes size is : "<<edges[v].size()<<endl;

	for (long i = 0; i < edges[v].size(); ++i)
	{
		 if(visited[ edges[v][i] ] == false )
		 {	
		 	DFSutill(n, m, edges, cats, visited, count, edges[v][i] );
		 }
		
	}
	if(edges[v].size() == 1 && v!= 1)
	{	//cout<<"\n in a leaf node "<<v<<endl;
		//if(count <= m)
			{	++totalways;
			  // cout<<" total ways until now is : "<<totalways<<endl;
			}

	}
	return;
}
void DFS (long n,long m, vector <long> edges[], long cats[] )
{	long count=0;
	bool visited[n+1]={false};
	DFSutill(n, m, edges, cats, visited, count, 1 );

}
int main()
{	long n,m,a,b;
	cin>>n>>m;
	long cats[n+1]={0};
	for(long i=1; i<=n; i++)
	{
		cin>>cats[i];
	}
	//make a visited array
	vector <long> edges[n+1];
	for(long i=1 ; i<=n-1; i++)
	{	cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	DFS(n, m, edges, cats);
	 
	cout<<totalways<<"\n";	
	return 0;

}
