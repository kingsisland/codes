#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,l,r,MIN=1000000005,MAX=-1,a, b;
	cin>>n;
	vector< pair <long,long> > ends;
	for(long i=1; i<=n; i++)
	{
		cin>>l>>r;
		MIN = min(MIN98,l);
		MAX = max(MAX, r);
		ends.push_back(make_pair(l , r));
	}
	long freq[MAX-MIN+5]={0};
	for (long i = 0; i < n; ++i)
	{
		a=ends[i].first-MIN;
		b=ends[i].second-MIN;
		freq[a]+=1;
		if(b != MAX-MIN)
		{
			freq[b+1]+= (-1);
		}
	}
	long temp=0;
	for (long i = 0; i <= MAX-MIN; ++i)
	{	temp+=freq[i];
		freq[i] = temp;
		
	}
	//testing
	cout<<endl;
	for (long i = 0; i <= MAX-MIN; ++i)
	{	
		cout<<freq[i]<<"  ";
		
	}
	cout<<endl;



	return 0;
}