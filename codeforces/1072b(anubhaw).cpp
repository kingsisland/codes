#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	long n;
	cin>>n;
	int flag=0;
	int a[n],b[n],al[n],ar[n],bl[n],br[n],ansl[n],ansr[n];
	f(i,0,n-1)
	{
		cin>>a[i];
		al[i]=(a[i]>>1)&1;
		ar[i]=a[i]&1;

	}
	// f(i,0,n-1)
	// 	cout<<al[i]<<" ";
	// f(i,0,n-1)
	// 	cout<<ar[i]<<" ";
	f(i,0,n-1)
	{
		cin>>b[i];
		bl[i]=(b[i]>>1)&1;
		br[i]=b[i]&1;
	}
	if(al[0]==bl[0] || bl[0]==1)
	{
		flag=0;
		ansl[0]=bl[0];
		ansl[1]=bl[0];
		f(i,1,n)
		{	
			if(al[i]==bl[i])
			{
				if(ansl[i]==al[i])
					ansl[i+1]=al[i];
				else
				{
					flag++;
					break;
				}
			}
			else
			{
				if(al[i]==0 && ansl[i]==0)
				{
					flag++;
					break;
				}
				else if(al[i]==0 && ansl[i]==1)
				{
					flag++;
					break;
				}
				else if(al[i]==1 && ansl[i]==0)
					ansl[i+1]=1;
				else 
					ansl[i+1]=0;
			}
		}
		if(flag)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else
	{
		flag=0;
		ansl[0]=1;
		ansl[1]=0;
		f(i,1,n)
		{	
			if(al[i]==bl[i])
			{
				if(ansl[i]==al[i])
					ansl[i+1]=al[i];
				else
				{
					flag++;
					break;
				}
			}
			else
			{
				if(al[i]==0 && ansl[i]==0)
				{
					flag++;
					break;
				}
				else if(al[i]==0 && ansl[i]==1)
				{
					flag++;
					break;
					//ansl[i+1]=1;
				}
				else if(al[i]==1 && ansl[i]==0)
					ansl[i+1]=1;
				else 
					ansl[i+1]=0;
			}
		}
		if(flag)
		{
			ansl[0]=0;
			ansl[1]=1;
			f(i,1,n)
			{	
				if(al[i]==bl[i])
				{
					if(ansl[i]==al[i])
						ansl[i+1]=al[i];
					else
					{
						flag++;
						break;
					}
				}
				else
				{
					if(al[i]==0 && ansl[i]==0)
					{
						flag++;
						break;
					}
					else if(al[i]==0 && ansl[i]==1)
					{
						flag++;
						break;
						//ansl[i+1]=1;
					}	
					else if(al[i]==1 && ansl[i]==0)
						ansl[i+1]=1;
					else 
						ansl[i+1]=0;
				}
			}
		}
		if(flag==2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	// f(i,0,n)
	// 	cout<<ansl[i]<<" ";
	// cout<<endl;
	if(ar[0]==br[0] || br[0]==1)
	{
		flag=0;
		ansr[0]=br[0];
		ansr[1]=br[0];
		f(i,1,n)
		{	
			if(ar[i]==br[i])
			{
				if(ansr[i]==ar[i])
					ansr[i+1]=ar[i];
				else
				{
					flag++;
					break;
				}
			}
			else
			{
				if(ar[i]==0 && ansr[i]==0)
				{
					flag++;
					break;
				}
				else if(ar[i]==0 && ansr[i]==1)
					{
						flag++;
						break;
						//ansl[i+1]=1;
					}	
				else if(ar[i]==1 && ansr[i]==0)
					ansr[i+1]=1;
				else 
					ansr[i+1]=0;
			}
		}
		if(flag)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else
	{
		flag=0;
		ansr[0]=1;
		ansr[1]=0;
		f(i,1,n)
		{	
			if(ar[i]==br[i])
			{
				if(ansr[i]==ar[i])
					ansr[i+1]=ar[i];
				else
				{
					flag++;
					break;
				}
			}
			else
			{
				if(ar[i]==0 && ansr[i]==0)
				{
					flag++;
					break;
				}
				else if(ar[i]==0 && ansr[i]==1)
					{
						flag++;
						break;
						//ansl[i+1]=1;
					}	
				else if(ar[i]==1 && ansr[i]==0)
					ansr[i+1]=1;
				else 
					ansr[i+1]=0;
			}
		}
		if(flag)
		{
			ansr[0]=0;
			ansr[1]=1;
			f(i,1,n)
			{	
				if(ar[i]==br[i])
				{
					if(ansr[i]==ar[i])
						ansr[i+1]=ar[i];
					else
					{
						flag++;
						break;
					}
				}
				else
				{
					if(ar[i]==0 && ansr[i]==0)
					{
						flag++;
						break;
					}
					else if(ar[i]==0 && ansr[i]==1)
					{
						flag++;
						break;
						//ansl[i+1]=1;
					}	
					else if(ar[i]==1 && ansr[i]==0)
						ansr[i+1]=1;
					else 
						ansr[i+1]=0;
				}
			}
		}
		if(flag==2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	f(i,0,n)
	{
		cout<<(ansl[i]*2)+ansr[i];
		if(i!=n-1)
			cout<<" ";
	}
}