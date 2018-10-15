#include <bits/stdc++.h>
using namespace std;
int main()	
{	long long n,time,a,slots=0,div;
	cin>>n>>time>>a;
	long long t[n+1],l[n+1],breaks[n+1];
	t[0]=0;
	l[0]=0;
	long long j=0;

	if(n>0)
	{
		cin>>t[1];
	cin>>l[1];
	breaks[j]=t[1]-0;
	j++;
	}
	for (long long i = 2; i <= n; ++i)
	{	cin>>t[i];
		cin>>l[i];
		if(t[i]>t[i-1]+l[i-1])
		{	breaks[j]=t[i]-(t[i-1]+l[i-1]);
			//cout<<"\n breaks: "<<breaks[j]<<" i: "<<i<<endl; 
			j++;
		}

	}

	time=time-(t[n]+l[n]);
	//cout<<"\n rem time: "<<time<<endl;

	//cout<<"\nBreaks \n";
	for (long long i = 0; i < j; ++i)
	{	//cout<<" "<<breaks[i];
		div=breaks[i]/a;
		slots+=div;
		
	}
	//cout<<endl;

	slots+=time/a;
	cout<<slots;






	return 0;
}