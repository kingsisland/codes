#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	int t,n,trace,val;
	cin>>t;
	for(int test_case=1; test_case<= t; test_case++)
	{
		cin>>n;
		trace =0;
		vector<unordered_set<int> > rows(n), cols(n);
		for(int i=0; i<n; i++)
		{	
			for(int j=0; j<n; j++)
			{
				cin>>val;
				if(i==j) trace+= val;
				rows[i].insert(val);
				cols[j].insert(val);
			}
		}

		int row_count=0, col_count=0;
		for(int i=0; i<n; i++)
		{
			if(rows[i].size() != n) row_count++;
			if(cols[i].size() != n) col_count++;
		}

		printf("Case #%d: %d %d %d\n", test_case,trace, row_count, col_count);



	}
}