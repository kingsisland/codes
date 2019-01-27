#include <bits/stdc++.h>
using namespace std;

int main()
{	int t,m[8],k,temp,a,b,c;
	cin>>t;
	while(t--)
	{	cin>>k;
		cin>>a>>b>>c;

		m[0]=a+b+c;
		m[1]=a+b-c;
		m[2]=a-b+c;
		m[3]=-a+b+c;
		m[4]=a-b-c;
		m[5]=-a+b-c;	
		m[6]=-a-b+c;
		m[7]=-a-b-c;

		int i=0;
		for (; i < 8; ++i)
		{
			if(k==m[i])
			{
				printf("WIN\n");
				break;
			}
		}
		if (i==8)
		{
			printf("LOSE\n");
		}
	

	}




	return 0;
}