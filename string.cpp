#include <bits/stdc++.h>
using namespace std;
int main()
{	int i,t,l,vc,ac,flag;
	char s[100001];
	cin>>t;
	while(t--)
	{	//i=0;
		flag=0;
		vc=0;
		ac=0;
		cin>>l;
		cin>>s;
		for (i = 0; i < l; ++i)
		{	if (s[i]=='v')
			{	ac=0;
				vc+=1;
				if(l==1)
				{	flag=1;
					//cout<<"Yes\n";
					//break;
				}
				else if (vc==2)
				{	flag=0;
					cout<<"No\n";
					break;
				}
			}
			else if(s[i]=='a')
			{	vc=0;
				ac+=1;
				if(i==1 && ac==2)
				{	flag=1;
					//cout<<"Yes\n";
					//break;
				}
				else if(i==l-1 && ac==2)
				{	flag=1;
					//cout<<"Yes\n";
					//break;
				}
				else if (ac==3)
				{	flag=1;
					//cout<<"Yes\n";
					//break;
					
				}
			}

		}
		if (flag==0 && i==l)
		{	cout<<"No\n";
			
		}
		if (flag==1 && i==l)
		{
			cout<<"Yes\n";
		}
	}
	
	return 0;
}