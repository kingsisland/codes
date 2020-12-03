#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	vector<vector<long long>> vec(n, vector<long long>(n)) ;
	int  i =0;
	int num =1;
	while(num < n*n)
	{
		int row = i;
		for(int j =0; j<n; j++)
		{
			vec[row][j] = num;
			num++;
		}
		if(num > n*n)
			break;
		row = n-1-i;
		for(int j =0; j<n; j++)
		{
			vec[row][j] = num;
			num++;
		}
		i++;
	}
	for(int i =0; i<n; i++)
	{
		for(int j =0; j<n; j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
}