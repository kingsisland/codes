#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,maxa,maxb,val;
	cin>>t;
	while(t--)
	{	maxa=0;
		maxb=0;

		cin>>n;

		for(int i=0; i<n; i++)
		{
			cin>>val;
			maxa = max(maxa, val);
		}



		for(int i=0; i<n; i++)
		{
			cin>>val;
			maxb = max(maxb, val);
		}

		if(maxa != maxb ) cout<<"YES\n";
		else cout<<"NO\n";

	}
	return 0;
}