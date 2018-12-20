#include <bits/stdc++.h>
using namespace std;
vector< pair <long,long> > beacon;
long n,a,b,minimum=1000000,res; 
long dp[100005];

long bSearch(long l,long r,long pos,long range )
{	//cout<<"\n IN bSearch l: "<<l<<"   r:  "<<r<<endl; 
	if(l<r)
	{
		long mid= l+(r-l+1)/2;
		if(pos - beacon[mid].first == range)
		{
			return mid-1;
		}
		else if( (pos - beacon[mid].first) <range && (mid-1 >= l))
		{
			return bSearch(l,mid-1,pos,range);
		}
		else if (pos - beacon[mid].first > range)
		{
			return bSearch(mid,r,pos,range);
		}
	}
	else if(l==r && l!=0)
	{
		if(pos - beacon[l].first > range)
		{
			return l;
		}
		else if(pos - beacon[l].first == range)
		{
			return l-1;
		}
	}
	else if(l==r && l==0)
	{
		if(pos - beacon[0].first > range)
		{
			return l;
		}
		else if(pos - beacon[0].first <= range)
		{
			return -1;
		}
	}

}


long minBeacons(long pos)
{	if(pos==0)
	{
		return 0;
	}
	if(pos>0)
	{	//cout<<"\n in minBeacons pos: "<<pos<<endl;
		if(dp[pos]!= -1 )
		{
			return dp[pos];
		}
		else
		{	long index = bSearch(0,pos-1,beacon[pos].first,beacon[pos].second);
			//cout<<"\nIndex: "<<index<<endl;
			if(index==-1)
			{
				dp[pos]= pos;
				return dp[pos];
			}
			else
			{
				dp[pos]= (pos-index-1) + minBeacons(index);
				return dp[pos];
			}

		}
	}


}

int main()
{	for (long i = 1; i < 100005; ++i)
	{
		dp[i]=-1;
	}
	dp[0]=0; 

	cin>>n;
	for (int i = 0; i < n; ++i)
	{	cin>>a>>b;
		beacon.push_back(make_pair(a,b));
		
	}
	//sort the elements in asc order acc to the first pair
	sort(beacon.begin(), beacon.end());
	for (int i = n-1; i >=0; --i)
	{
		res=minBeacons(i)+(n-1-i);
		//cout<<endl<<beacon[i].first<<"  "<<res;
		if(res<minimum)
		{
			minimum=res;
		}
	}

	cout<<minimum;



	return 0;
}