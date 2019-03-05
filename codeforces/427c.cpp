#include <bits/stdc++.h>
#define N 100005
using namespace std;
vector<long> adj[N],adjR[N];

long n,m,a,b;
long c[N];
bool visited[N];
long long ways=1;
long long minCost=0;

void fillOrder(long v,stack<long> &Stack)
{	visited[v]=true;

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
	{	if(visited[*i]==false)
			fillOrder(*i,Stack);

	}
	Stack.push(v);

}

void DFSutill(long v,multiset<long> &comp)
{		
	visited[v]=true;
	comp.insert(c[v]);
	
	for (auto i = adjR[v].begin(); i != adjR[v].end(); ++i)
	{	if(!visited[*i])
			DFSutill(*i,comp);

	}
}




int main()
{	cin>>n;

	for (int i = 1; i <= n ; ++i)
	{
		scanf("%ld",&c[i]);
		visited[i]=false;
	}
	cin>>m;
	while(m--)
	{	scanf("%ld %ld",&a,&b);
		adj[a].push_back(b);
		adjR[b].push_back(a);
	}

	stack<long> Stack;
	for (int i = 1; i <= n; ++i)
	{
		if(visited[i]==false)
			fillOrder(i,Stack);
	}

	for (int i = 1; i <= n; ++i)
	{
		visited[i]=false;
	}

	
	while(!Stack.empty())
	{
		long v=Stack.top();
		Stack.pop();

		if(visited[v]==false)
		{
			multiset<long> comp;
			DFSutill( v,comp);
			
			multiset<long> ::iterator itr=comp.begin();
			//minCost=((minCost%1000000007 )+ ((*itr)%1000000007))%1000000007;
			minCost=minCost+(long long)(*itr);
			long compMin=*itr,count=1;
			itr++;

			for (; itr != comp.end(); ++itr)
			{	
				if(*itr>compMin)
					break;

				count++;
			}

			//cout<<"    count: "<<count<<endl;
			ways=((ways%1000000007)*(count%1000000007))%1000000007;
			

			
		}

	}

	cout<<minCost<<" "<<ways;
	


}