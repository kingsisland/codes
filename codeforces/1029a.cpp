#include <bits/stdc++.h>
using namespace std;
void computeLPS(string &pat,int n,int lps[] )
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i < n)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len !=0 )
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
int main()
{	int n,k,prefix;
	cin>>n>>k;
	string pat;
	int lps[n+1];
	cin>>pat;
	computeLPS(pat, n, lps);
	prefix=lps[n-1];
	cout<<pat;
	for(int i=2; i<=k; i++)
	{
		for(int j=prefix; j<=n-1; j++)
		{
			cout<<pat[j];
		}
	}


	return 0;
}