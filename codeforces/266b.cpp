#include <bits/stdc++.h>
using namespace std;
string a;
void swapChar ( int i)
{
	//string temp= a[i];
	a[i] = 'G';
	a[i+1] = 'B';
	return ;
}
int main()
{	int n,t;
	cin>>n>>t;
	
	cin>>a;
	while(t--)
	{
		for (int i = 0; i <=n-2; )
		{	if( a[i] == 'B' && a[i+1] == 'G')
			{
				swapChar( i );
				i+=2;

			}else
			{	i++;

			}
		
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i];
	}



	return 0;
}