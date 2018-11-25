include <bits/stdc++.h>
using namespace std;

int main()
{	long n,edge;
	cin>>n;
	long sub[n+1]={0}
	set <long> adj[n+1];
	for (long i = 2; i <= n-1; ++i)
	{	cin>>edge;
		adj[edge].insert(i);
		//adj[i].insert(edge);
		
	}
	for (long i = 1; i <=n; ++i)
	{
		if(adj[i].size()==1)
		{
			sub[i]+=1;

		}
	}



	return 0;
}