#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,m,k,res,count,bit,ans=0;
	cin>>n>>m>>k;
	int player[m+2];
	for (int i = 1; i <= m+1 ; ++i)
	{
		cin>>player[i];
	}
	for (int i = 1; i <= m; ++i)
	{	//cout<<"\n Started checking for numbers are : "<<player[i]<<" and "<<player[m+1]<<endl;
		res=player[i]^player[m+1];
		count=0;
		for (int p = 0; p < n; ++p)
		{	
			bit=(int)(pow(2,p)+0.5);
			if((res&bit) == bit)
			{	
				++count;

				//cout<<"\n res&bit is : "<< (res&bit) <<" bit is "<<bit<<"  and count is : "<<count<<endl;
			}

		}
		if(count <= k)
		{	//cout<<"\n Selected numbers are : "<<player[i]<<" and "<<player[m+1]<<endl;
			ans++;

		}
	}
	cout<<ans;



	return 0;
}