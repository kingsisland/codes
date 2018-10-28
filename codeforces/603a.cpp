#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,len,ctr,boxes,ind;
	cin>>n;
	char a[n+1];
	cin>>a;
	if(a[n-1]== '0')
	{
		a[n]='1';
	}
	else
	{
		a[n]='0';
	}
	//cout<<endl<<a<<endl;
	boxes=0;
	ctr=0;
	len=0;
	for (int i = 0; i <n; ++i)
	{	if(a[i]==a[i+1])
		{	ctr++;
		}
		else
		{	ctr++;
			boxes++;
			if(ctr>1)
			{
				//cout<<endl<<"i: "<<i<<endl;
				len++;
				if(len==1)
				{	//cout<<"\n ctr here is: "<<ctr<<endl;
					ind=ctr;
				}
				
			}
			
			ctr=0;
			
		}
	}
	//cout<<boxes<<" "<<len<<" "<<ind<<endl;
	{	
		if(len==1)
		{	if(ind>=3)
			{
				boxes=boxes+2;
			}
			else
			{
				boxes=boxes+1;
			}
			
		}
		else if(len>=2)
		{
			boxes=boxes+2;
		}
		//else
		{
			cout<<boxes<<endl;
		}
	}
	
	
	return 0;
}
