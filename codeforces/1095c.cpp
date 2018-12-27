//incomplete

#include <bits/stdc++.h>
using namespace std;
vector <long> v,a,ans;

long tem;

void printvec(vector <long> a)
{	cout<<"YES\n";
	for (long i = 0; i < a.size(); ++i)
	{
		cout<<a[i]<<" ";
	}
}
long block(long x)
{
	while(x>0)
	{	
		v.push_back(x%2);
		x=x/2;
	}
	for (long i = 0; i < v.size(); ++i)
	{
		if (v[i]== 1)
		{	tem=(long)pow(2,i);
			a.push_back(tem);
			
		}
	}
	return a.size();

}
int main()
{	long n,k;
	cin>>n>>k;
	long count=block(n);
	if (n < k)
	{
		cout<<"NO";
	}
	else if(count == k)
	{	
		printvec(a);
	}
	else if(count < k)
	{
		//basically divide an element of vector 'a' by 2, so that one element is split into two
		//equal elements and the count increses by 2;
		//Will have to find a easier way to do the splitting.	
	}

	



	return 0;
}