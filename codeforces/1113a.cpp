#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,v,x;
	cin>>n>>v;
	if(v>= n-1)
		cout<<n-1;
	else
	{	x=n-v;
		//cout<<x<<endl;
		x=(x*(x+1))/2 -1;

		cout<<v+x;


	}
	return 0;
}