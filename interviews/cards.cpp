#include<bits/stdc++.h>
using namespace std;
vector<int> hackerCards(vector<int> collection, int d)
{
	unordered_set<int> seen;
	for(int i =0; i< collection.size(); i++ )
	{
		seen.insert(collection[i]);
	}
	int i = 1;
	vector<int> ans;
	while(d > i)
	{
		if(seen.find(i) == seen.end())
		{
			ans.push_back(i);
			d = d-i;
		}
		i++;
	}
	return ans;
}