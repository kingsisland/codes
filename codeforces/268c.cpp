#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,m,tot,i,j;
	cin>>n>>m;
	if (n<=m)
	{
		tot=n+1;
		cout<<tot<<"\n";
		i=n;
		j=0;
		while(i>=0)
		{
			cout<<i<<" "<<j<<"\n";
			i--;
			j++;
		}
	}
	else
	{	tot=m+1;
		cout<<tot<<"\n";
		i=n;
		j=0;
		while(j<=m)
		{
			cout<<i<<" "<<j<<"\n";
			i--;
			j++;
		}


	}
	

	return 0;
}