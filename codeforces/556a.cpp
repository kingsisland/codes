#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,nzero=0,none=0;;
	char a[200005];
	
	cin>>n;
	cin>>a;
	
	for (int i = 0; i < n ; ++i)
	{
		if (a[i]=='0')
		{	nzero++;
		
		}else
		{
			none++;
		}
	}
	if(nzero<=none)
	{
		cout<<n-(2*nzero);
	}
	else
	{	cout<<n-(2*none);

	}


	return 0;
}