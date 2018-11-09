#include <bits/stdc++.h>
using namespace std;
long n,m;
long da[200005],b[200005],c[200005],freq[200005]={0},rf[200005];
//vector < pair <long,long> > vec;
//vector < long > maxL;
long bSearch(long l,long r,long key)
{	
	if(l<r)
	{
		long mid=(l+r)/2;
		if(rf[mid]==key)
		{
			return mid;
		}
		else if(rf[mid] > key)
		{
			return bSearch(l, mid-1, key);
		}
		else
		{
			return bSearch(mid+1,r, key);
		}
		
	}
	else if(l==r)
	{
		if(rf[l]==key)
		{
			return l;
		}
		else
			return -1;
	}
	else
	{
		return -1;
	}
	
}

int main()
{	cin>>n;
	for (long i = 0; i <n; ++i)
	{
		cin>>da[i];
		//da[i]=a[i];
	}
	cin>>m;
	for (long i = 0; i < m; ++i)
	{	cin>>b[i];

	}
	for (long i = 0; i < m; ++i)
	{	cin>>c[i];
		
	}


	sort(da,da+n);
	long j=0;
	rf[j]=da[0];
	freq[j]++;
	

	for (long i = 1; i < n; ++i)
	{	if(da[i]!= da[i-1])
		{	j++;
			rf[j]=da[i];
			freq[j]++;
		}
		else
		{
			freq[j]++;
		}
		
	}
	
	
	
	long maxa=-1,s=-1,idx,maxi=-1,ms=-1,msi=-1;
	
	

	for (long i = 0; i < m; ++i)	
	{	idx=bSearch(0, j, b[i]);
		
		
		if(idx!= -1 )
		{	
			if(maxa < freq[idx])
			{	maxa=freq[idx];
				maxi=i;

				
				idx=bSearch(0, j, c[i]);
				
				if(idx == -1)
				{
					s=0;
				}
				else
				{
					s=freq[idx];
				}

			}
			if(maxa == freq[idx])
			{	idx=bSearch(0,j,c[i]);
				
				if(idx != -1)
				{
					if(s < freq[idx])
					{	s=freq[idx];
						maxi=i;
						//cout<<"\n max i: "<<maxi<<" rf[idx]: "<<rf[idx]<<" c[i]: "<<c[i]<<endl;
						
					}
				}

			}
			
		}
		else
		{	idx=bSearch(0,j,c[i]);
			
			if(idx != -1)
			{
				if(ms< freq[idx])
				{
					ms=freq[idx];
					msi=i;
				}
			}

		}
		
		
	}
	//cout<<maxi+1<<endl;
	//sort(vec.begin(),vec.end());
	if(maxi != -1)
	{	cout<<maxi+1<<endl;

	}
	else
	{	if(msi != -1)
		{
			cout<<msi+1<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}

	}
	
	


	


	return 0;
}