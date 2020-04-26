#include <bits/stdc++.h>
using namespace std;

 	
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
    	long long MOD = 1000000007;
        
      
        long long net_sum=0, max_subarray = 0, suffix = 0, prefix = 0;
      

        long long maxSoFar=0, maxUntilHere = 0;

        long long temp_sum=0;
        for(auto i: arr)
        { 
          net_sum+=i;
          prefix = max(prefix, net_sum);

          maxUntilHere += i;
          if(maxUntilHere < 0)
            maxUntilHere = 0;
          if(maxUntilHere > maxSoFar)
            maxSoFar = maxUntilHere;

        }

        max_subarray = maxSoFar;
        if (k==1) return max_subarray;

        temp_sum=0;
        for(int i = arr.size()-1; i >= 0; i--)
        {
          temp_sum+=arr[i];
          suffix = max(suffix, temp_sum);
        }

        long long suffix_netsum_prefix = 0;
        if(k>= 3)
          suffix_netsum_prefix = suffix + prefix + (net_sum)*(k-2);

       	

       	long long netsum_k = net_sum*k;

        
        long long suffix_and_prefix = 0;
        if(k>1)
          suffix_and_prefix =suffix + prefix;

        long long ans = max(max_subarray, suffix_and_prefix);
        ans = max(suffix_netsum_prefix, ans);
        ans = max(netsum_k, ans);
        return ans%MOD;


    }
};

int main()
{

}