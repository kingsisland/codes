#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> nums, vector<int> quantity)
{
	unordered_map<int, int> mp;
	map<int,int> secs;
	for(auto val: nums)
		mp[val]++;	// maintaining a freq of numbers
	for(auto it: mp)
	{
		secs[it.second]++;
	}
	for(auto q : quantity)
	{
		if(secs.find(q) != secs.end() && secs[q] > 0)
			secs[q]--;
		else
		{
			auto it = secs.upper_bound(q);

			if(it != secs.end())
			{
				int val = it->first;
				secs[val]--;
				secs[val-q]++;
			}
			else
			{
				return false;
			}
		}
	}
	return true;

}
int main()
{
	
	int n;
	int q;
	cin>>n;
	cin>>q;
	vector<int> nums(n);
	vector<int> quantity(q);
	cin>>n;
	for(int i =0; i<n; i++)
	{
		cin>>nums[i];
	}
	for(int i=0; i<q; i++)
	{
		cin>>quantity[i];
	}
	cout<<solve(nums, quantity);
}