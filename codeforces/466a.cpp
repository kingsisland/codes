#include <bits/stdc++.h>
using namespace std;
int main()
{	float n,m,a,b;
	float cost;
	int tot=0;
	cin>>n>>m>>a>>b;
	cost=b/m;
	if(a<=cost)
	{

		cout<<int(a*n);
	}
	else
	{	int par=int(n/m);
		tot+=par*b;
		if((n-(par*m))*a < b)
		{
			tot+=(n-(par*m))*a;

		}
		else
			tot+=b;

		cout<<tot;
		


	}

	return 0;
}