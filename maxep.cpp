#include <bits/stdc++.h>
using namespace std;
long coins=1000;
long N,c;
int bSearchx(long l,long r)
{	if(l<r)
	{	
		long res;
		long mid=l+(r-l)/6;
		cout<<"1 "<<mid<<"\n"<<flush;
		coins=coins-1;
		cin>>res;
		if(res==-1 || coins<0)
		{
			//cout<<"Failed constraints\n";
			return 0;
		}
		if(res==1)
		{	cout<<"2\n"<<flush;
			coins=coins-c;
			return bSearchx(l,mid);

		}
		if (res==0)
		{
			return bSearchx(mid+1,r);
		}
		
	}
	if (l==r)
	{
		cout<<"3 "<<l<<"\n"<<flush;
		return l;
	}

}
int main(int argc, char const *argv[])
{	
	
	cin>>N>>c;
	bSearchx(1,N);
	return 0;
}