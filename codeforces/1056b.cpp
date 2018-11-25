#include <bits/stdc++.h>
using namespace std;
bool extra[1005]={false};
int main()
{	long long n,m,t1,t2,count=0,rows,tempi,tempj;
	cin>>n>>m;
	rows=n/m;
	
	for (long long i = (rows*m)+1; i <= n; ++i)
	{
		extra[i%m]=true;
	}
	for (long long i = 0; i < m; ++i)
	{	for (long long j = i; j < m; ++j)
		{	t1=i%m;
			t2=j%m;
			if( ((t1*t1)%m + (t2*t2)%m)%m == 0)
			{	
					tempi=rows;
					tempj=rows;
				if(extra[i]==true)
				{
					tempi+=1;
				}	
				if (extra[j]==true)
				{
					tempj+=1;
				}
				
				if(i!=j)
				{	
					count+=(2*tempi*tempj);
				}
				else
					count+=tempi*tempj;
			}	
		
		}
			
	}
	


	cout<<count;	

	return 0;
}