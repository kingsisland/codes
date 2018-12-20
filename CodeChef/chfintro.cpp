#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,r,R;
	cin>>n>>r;
	while(n--)
	{	cin>>R;
		if(R<r)
			cout<<"Bad boi\n";
		else
			cout<<"Good boi\n";
	}


	return 0;
}