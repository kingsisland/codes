#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,x,n,m;
	int pass[100005], test_array[100005];
	cin>>t;
	while(t--)
	{
		cin>>x;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>pass[i];
		cin>>m;
		for(int i=0; i<m; i++)
			cin>>test_array[i];

		int pass_count=0;
		for (int i = 0; i < m-n+1; ++i)
		{	
			int val = test_array[i] - pass[0];
			
			// cout<<i<<"	val : "<<val<<endl;
			if(abs(val) > x)  continue;
			bool flag = false;
			int temp;
			for(int k=i+1; k < i+n; k++)
			{	temp = test_array[k] - pass[k-i];
				
				if(val != temp)
				{
					flag=true;
					break;
				}
			}
			if(!flag) pass_count++;
		}
		cout<<pass_count<<"\n";

	}
	return 0;
}