#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,k,diff,a,rating=0,count=0;
	cin>>n>>k;
	vector <pair<long,long> > v;
	for (long i = 0; i < n; ++i)
	{
		cin>>a;
		diff=((a/10)+1)*10 - a;
		v.push_back( make_pair(diff,a));
	}
	
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<"\ndiff: "<<v[i].first<<"  a["<<i+1<<"] : "<<v[i].second;
	// }
	// cout<<endl;
	while(k>0 && count<n)
	{	sort(v.begin(),v.end());
		count=0;
		for (int i = 0; i < n; ++i)
		{	
			if(v[i].second!=100 && k>0 )
			{	
				if(k-v[i].first>=0)
				{	//cout<<"\n v[i].second: "<<v[i].second<<"  v[i].first: "<<v[i].first<<endl;
					k=k-v[i].first;
					v[i].second+=v[i].first;
					v[i].first=((v[i].second/10)+1)*10 - v[i].second;

					//cout<<"\n k : "<<k<<endl;
					//cout<<"\nAfter, v[i].second: "<<v[i].second<<"  v[i].first: "<<v[i].first<<endl;
				}
				else
				{	k=0;
					break;
				}
				
				
			}
			if(v[i].second==100)
			{
				count++;
			}
		}

	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<"\ndiff: "<<v[i].first<<"  a["<<i+1<<"] : "<<v[i].second;
	// }
	// cout<<endl;

	for (int i = 0; i < n; ++i)
	{	rating+=v[i].second/10;
		
	}
	cout<<rating;
	




	return 0;
}