#include <bits/stdc++.h>
#define N 100005
using namespace std;
long long  n,k;
long long  a[N],b[N];

long long  BsFind(long long  l,long long  r)
{
	if(r>l)
	{	
		long long  cur=l+(r-l+1)/2;
		long long  cnt=0;
		int flag=0;

		
	

		for (int i = 0; i < n; ++i)
		{	if(a[i]*cur > b[i])
			{
				cnt=cnt+(a[i]*cur - b[i]);
			}
			
			
			if(cnt>k)
			{	
				flag=1;
				break;
			}
		}
	
		if(flag==1)
		{
			return BsFind(l,cur-1);
		}

		return BsFind(cur,r);
	}
	else if(l==r)
	{
		return l;
	}
}


int main()
{	scanf("%lld %lld",&n,&k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&b[i]);
	}

	cout<<BsFind(0,2000000000);


	return 0;
}