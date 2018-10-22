#include <bits/stdc++.h>
using namespace std;
//long a[5005][5005];
long rows[5005]={0};
long cols[5005]={0};
long timr[5005]={0};
long timc[5005]={0}; 
int main()
{	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long n,m,k,ptr=0;
	long q,a;   //query and color
	long rc;
	cin>>n>>m>>k;
	while(k--)
	{	cin>>q>>rc>>a;
		ptr++;
		if(q==1)
		{	timr[rc]=ptr;
			rows[rc]=a;
			//cout<<"\n row: "<<rc<<"  color: "<<a<<endl;

		}
		else
		{
			timc[rc]=ptr;
			cols[rc]=a;
			//cout<<"\n col: "<<rc<<"  color: "<<a<<endl;
		}		

	}
	for (long i = 1; i <=n; ++i)
	{
		for (long j = 1; j <=m; ++j)
		{
			if(timr[i]>timc[j])
			{
				cout<<rows[i]<<" ";
			}
			else if(timr[i]<timc[j])
			{
				cout<<cols[j]<<" ";
			}
			else if( timr[i]==0 && timc[j]==0)
			{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	


	return 0;
}