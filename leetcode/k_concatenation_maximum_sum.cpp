#include <bits/stdc++.h>
using namespace std;

 	
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
    	long long MOD = 1000000007;
        int n = arr.size();
        long long subarray_sum[n];
        long long net_sum, max_sum =0, max_sum_0 = 0, l, r, r_end;
    
        // Filling the prefix sum aray
        subarray_sum[0] = arr[0];
        for(int i = 1; i<n ; i++)
	        subarray_sum[i] = subarray_sum[i-1]+arr[i];

	    // Finding the maximum sub array
	    for(int i =0; i < n; i++)
	    {
	    	for(int j= i; j<n; j++)
	    	{
	    		if(max_sum <= (subarray_sum[j] - subarray_sum[i] + arr[i]))
	    		{
	    			max_sum = subarray_sum[j] - subarray_sum[i] + arr[i];
	    			l = i;
	    			r = j;
	    		}
	    	}
	    }
        
        //cout<<"l : "<<l<<"  r: "<<r<<endl;
        if(max_sum == 0) return 0;

        net_sum = subarray_sum[n-1];


        for(int i =0; i < n; i++)
       	{
       		if(max_sum_0 < subarray_sum[i] - subarray_sum[0] + arr[0])
       		{
       			max_sum_0 = subarray_sum[i] - subarray_sum[0] + arr[0];
       			//r_end = i;
       		}
       	}

       	// net sum will be <= 0, so no need to bother
       	if (max_sum_0 == 0) return (int)(max_sum%MOD);


       	long long max_include_next_array = max_sum + max_sum_0;
       	if (r+1 < n)
       		max_include_next_array += (subarray_sum[n-1] - subarray_sum[r+1] + arr[r+1]);

       	if(max_include_next_array < max_sum)
       	{
       		if(net_sum > 0)
       		{
       			max_include_next_array = (max_include_next_array%MOD + ((net_sum)*(k-2))%MOD)%MOD;
       			if(max_include_next_array >= max_sum)
       				return (int)max_include_next_array;
       		}
       		return (int)max_sum%MOD; 
       	}

       	// max_include >= max_sum
       	if(net_sum > 0)
   		{
   			max_include_next_array = (max_include_next_array%MOD + ((net_sum)*(k-2))%MOD)%MOD;
   			return (int)max_include_next_array;      		
   		}
   		return (int)(max_include_next_array%MOD);


    }
};

int main()
{

}