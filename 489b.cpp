#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],b[100],pairs=0;
void makePairs( int N, int M, int aA[], int bB[] )
{
	int i=0,j=0;
	//while(i<N)
	//{
		while(j<M && i<N)
		{  //cout<<"\ntop";
				//cout<<"\n i is "<<i<<" j is "<<j<<endl;
			if(abs(aA[i]-bB[j]) <= 1)
			{	//cout<<"\nin ABS of a[i]-b[j]) <= 1\n";
				//cout<<"\n a[i] is "<<aA[i]<<" b[j] is "<<bB[j]<<endl;
				pairs++;
				//cout<<"\n current pairs is  "<<pairs<<endl;
				i++;
				j++;

			}

			else if( aA[i]-bB[j] < -1)
			{	//cout<<"\nin a[i]-b[j] > -1\n";
				//cout<<"\n i is "<<i<<" j is "<<j<<endl;
				i++;
			}
			else if(aA[i]-bB[j] > 1)
			{	//cout<<"\nin a[i]-b[j] > 1\n";
				//cout<<"\n i is "<<i<<" j is "<<j<<endl;
				j++;
			}
		}
		return;
	//}
	//return;
}

int main()
{	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}

	sort(a,a+n);
	sort(b,b+m);


	if(m>=n)
	{	//cout<<"\nM>=N\n";
		makePairs(n, m, a, b);
	}else
	{	//cout<<"\nN>M\n";
		makePairs(m, n, b, a);
	}
	cout<<pairs<<"\n";

	

	return 0;
}