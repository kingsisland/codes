#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> sums(n);
        sums[n-1] = piles[n-1];
        for(int i = n-2; i>=0; i--)
        	sums[i] = sums[i+1]+piles[i];
        vector<vector <int> > dp(n, vector<int>(n, 0));

        for(int i = n-1; i>= 0; i--)	// ith pile
        {
        	for(int m = n-1; m >= 1; m--)
        	{	
        		if(i+2*m >= n)
        		{
        			dp[i][m] = sums[i];
        			continue;
        		}

        		for(int x = 1; x <= 2*m && i+x < n; x++)
        		{
        			dp[i][m] = max(dp[i][m], sums[i] - dp[i+x][max(x,m)]) ;
        		}
        	}
        }
        return dp[0][1];
    }
};

int main()
{
	Solution solution = Solution();
	vector<int> piles {2,7,9,4,4};
	cout<<solution.stoneGameII(piles);
	
}
        
