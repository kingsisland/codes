#include <bits/stdc++.h>
using namespace std;
int bfs_level(vector <int> edges[],int n,int x,int u)
{	if(n==1 && x==1)
	{	
		return 1;
	}
	bool visited[n+1]={false};
	int level[n+1]={0},res=0;
	queue <int> Q;
	Q.push(u);
	level[u]=1;
	visited[u]=true;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for (int i = 0; i < edges[u].size(); ++i)
		{
			if (visited[edges[u][i]]==true)
			continue;

			Q.push(edges[u][i]);
			visited[edges[u][i]]=true;
			level[edges[u][i]]=level[u]+1;
			if (level[edges[u][i]]==x)
			{
				++res;
			}
		}
	}
	return res;
}
int main()
{	int n,u,v,x;
	cin>>n;
	//count=n;
	vector<int> edges[n+1];
	for (int i = 1; i <= (n-1); ++i)
	{	cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	cin>>x;
	cout<<bfs_level(edges,n,x,1);




	return 0;
}