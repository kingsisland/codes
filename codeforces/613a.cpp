#include <bits/stdc++.h>
using namespace std;
int main()
{	int n;
	long long a,suma=0;
	long long b,sumb=0;
	for (int i = 0; i < n; ++i)
		{	cin>>a;
			suma=suma|a;
		}

		for (int i = 0; i < n; ++i)
		{	cin>>b;
			sumb=sumb|b;
		}		
		cout<<suma+sumb;




	return 0;
}