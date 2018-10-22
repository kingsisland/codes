#include <bits/stdc++.h>
using namespace std;
long long a[200005],asc[200005],des[200005],ans[200005];
long long t[200005],r[200005];
long long ft[200005],fr[200005],ptr=0;

int main()
{	long long n,m,count=0,pta,ptd;
	cin>>n>>m;
	for (long long i = 0; i < n; ++i)
	{
		cin>>a[i];
		asc[i]=a[i];
		des[i]=a[i];
	}
	//sorting asc and des
	sort(asc,asc+n);
	sort(des,des+n);
	for (long long i = 0; i < m; ++i)
	{
		cin>>t[i];
		cin>>r[i];
	}
	ft[ptr]=t[m-1];
	fr[ptr]=r[m-1];
	count++;
	//ptr++;
	//long long j;
	for (long long i = m-1; i>0; )
	{	for (long long j = i-1; j>=0; )
		{	
			if(r[j]> r[i])
			{	
				count++;
				if (t[j]!=t[i])
				{	ptr++;
					ft[ptr]=t[j];
					fr[ptr]=r[j];
					
					i=j;
				}
				else     //same sort
				{	ft[ptr]=t[j];
					fr[ptr]=r[j];
					ptr++;
					i=j;

				}
			}
			j--;
		}
		break;	
		
	}

	cout<<"\n count: "<<count<<endl;
	for (long long i = 0; i <count; ++i)
	{
		cout<<"\nt[i]: "<<ft[i]<<"  fr[i]: "<<fr[i];
	}
	cout<<endl;


	if(ft[0]==1)    //ascending
	{
		for (long long i = 0; i <count; ++i)
		{	
			if (i%2==0)
			{	for (ptr=fr[i] ; ptr < fr[i+1] ; ++ptr)
				{
					ans[ptr]=asc[ptr];
					cout<<"\n ans[ "<<ptr<<"] : "<<ans[ptr]<<endl;
				}
			}
			else
			{	for (ptr=fr[i] ; ptr < fr[i+1] ; ++ptr)
				{
					ans[ptr]=des[ptr];
					cout<<"\n ans[ "<<ptr<<"] : "<<ans[ptr];
				}

			}

		
		}
	}
	else   //descending
	{
		for (long long i = 0; i < count-1; ++i)
		{	
			if (i%2==0)
			{	for (ptr=fr[i+1] ; ptr < fr[i] ; ++pta)
				{
					ans[ptr]=des[ptr];
					cout<<"\n ans[ "<<ptr<<"] : "<<ans[ptr];
				}
			}
			else
			{	for (ptr=fr[i+1] ; ptr < fr[i] ; ++pta)
				{
					ans[ptr]=asc[ptr];
					cout<<"\n ans[ "<<ptr<<"] : "<<ans[ptr];
				}

			}

		
		}
	}

	for (long long i = fr[count-1]; i < n ; ++i)
	{
		ans[i]=a[i];
	}

	if(ft[count-1]==1)
	{
		sort(ans,ans+fr[count-1]);
	}
	else
	{
		sort(ans,ans+fr[count-1],greater<long long>());
	}




	// cout<<endl;
	// for (long long i = ptr-1; i >-1; --i)
	// {
	// 	cout<<"\nt[i]: "<<ft[i]<<"  fr[i]: "<<fr[i];
	// }
	// cout<<endl;








	//cout<<endl;
	for (long long i = 0; i < n; ++i)
	{
		cout<<ans[i]<<" ";
	}






	return 0;
}