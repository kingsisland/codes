class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (!k)
        {
        	for (int i = 1; i < n; ++i)
	        {
	        	if(nums[i] == nums[i-1] && nums[i]==0)
	        		return true;

	        }
	        return false;
        }

        
        vector<int> prefix_sum_mod(n);
        unordered_multiset <int> mod_vals_set;

        prefix_sum_mod[0] = nums[0]%k;
        mod_vals_set.insert(prefix_sum_mod[0]);
        for (int i = 1; i < n; ++i)
        {
        	prefix_sum_mod[i] = (prefix_sum_mod[i-1] + nums[i]%k)%k;
        	mod_vals_set.insert(prefix_sum_mod[i]);

        }
        bool found = false;		// True if answer is found
        for(int i=0; i<n-1; i++)
    	{	int key;
    		int calc = (nums[i]%k - prefix_sum_mod[i] + k)%k;
    		k = abs(k);
    		key = ( k - calc)%k;

    		auto it = mod_vals_set.find(prefix_sum_mod[i]);
			mod_vals_set.erase(it);

    		if( mod_vals_set.find(key) != mod_vals_set.end()) //found when including this val
    		{
    			found = true;
    			break;
    		}	

    	}

	  	return found;
    }
};
