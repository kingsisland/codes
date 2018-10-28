#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,count=0;

	cin>>n;
	int vis [n+1]={0};
	long ptr=1;
	long a[n+1],b[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 1; i <=n; ++i)
	{
		cin>>b[i];
	}
	int j;
	for (int i = 1; i <=n; ++i)
	{	//cout<<"\nb[i]: "<<b[i]<<endl;
		if(vis[b[i]] == 0)
		{	count=0;

			for ( j = ptr; j <= n; ++j)
			{	vis[a[j]]=1;
				count++;
				if(a[j]==b[i])
				{
					cout<<count<<" ";
					break;
				}

			
			}
			ptr=j+1;

		}
		else
		{
			cout<<"0 ";
		}
	}





	return 0;
}