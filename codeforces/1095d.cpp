#include <bits/stdc++.h>
using namespace std;
long n;
int visited[200006]={0};
long a[200006],b[200006];
long ans[200006];

bool backtrack(long p, long level)
{	//cout<<p<<"  "<<level<<endl;
	if (visited[p]== 0)
	{	//cout<<p<<"  "<<level<<endl;
		
		if (level == n)
		{
			if(a[p] == 1 || b[p] == 1)
			{	visited[p] = 1;
				ans[level]=p;
				return true;
			
			}
			else
			{
				return false;
			}
		}


		long n,nn,m,mm;
		n=a[a[p]];
		nn= b[a[p]];

		m=a[b[p]];
		mm=b[b[p]];
		
		ans[level]=p;
		if(b[p] == n || b[p] == nn)
		{	visited[p]=1;
			if(backtrack(a[p], level+1 ))
			{	return true;

			}
			else
			{
				return backtrack(b[p], level+1);
			}

		}
		else if(a[p] == m || a[p] == mm)
		{	visited[p]=1;
			if(backtrack(b[p], level+1))
			{
				return true;
			}
			else
			{
				return backtrack(a[p], level+1);
			}

		}
		else
		{	ans[level]=0;
			return false;

		}

	}
	else 
		return false;
}

int main()
{	
	cin>>n;
	for (long i = 1; i <= n; ++i)
	{
		cin>>a[i]>>b[i];
	}

	backtrack(1,1);
	for (long i = 1; i <= n; ++i)
	{
		cout<<ans[i]<<" ";
	}
	



	return 0;
}