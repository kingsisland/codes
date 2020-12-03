#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pat, vector<int> &lps)
{
	int m = pat.length();
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i<m)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void solve(string &a, string &b, string c, int idx)
{
    //cout<<a<<" \n"<<b<<" "<<c;
	int n = a.length(), m = b.length();
	vector<int> lps(m);
	computeLPS(b, lps);
	int i = idx, j =0;
	while(i<=n)
	{
		if(j == m)
		{
			if(c == "N")
			{
				cout<<i-m<<endl;
				return;
			}
			else
			{
				if(( i==n  || (i < n && a[i] == ' ') ) 
					&& ( i-m-1 <0 ||(i-m-1>=0 && a[i-m-1]==' ')))
				{
					cout<<i-m<<endl;
					return;
				}
			}

		}
		if(i==n) break;
		if(a[i] == b[j])
		{
			i++;
			j++;
            
		}
		else if(i<n && a[i] != b[j]){
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	cout<<"Goodbye Watson\n";
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		string a, b;
		string c;
		int idx;
		getline(cin, a);
        getline(cin, a);
		getline(cin, b);
		getline(cin, c);
		cin>>idx;
		solve(a, b, c, idx);

	}
}