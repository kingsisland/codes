class Solution {
   
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        vector<vector <int> > ans;
        if(n <= 2)
            return ans;
        sort(nums.begin(), nums.end());
    
        
        for(int a =0 ; a < n-2; )
        {   
            if(nums[a] > 0 ) break;
            //cout<<"A : "<<a<<"  ";
            // int A = -nums[a];
            for(int b = n-1; b > a+1; )
            {   //cout<<"B : "<<b<<endl;
                int c = -nums[a]-nums[b];
                //cout<<"c val : "<<c<<endl;
                //bool hasC = hasVal(a+1, b-1, c, nums);
                int l = a+1, r = b-1;
                while(l< r)
                {      
                        int mid = (l+r)/2;
                        if(nums[mid] == c)
                        {
                            l = mid;
                            r = mid;
                        }
                        if(nums[mid] < c)
                            l = mid+1;
                        if(nums[mid] > c)
                            r = mid-1;                    
                }
                if(nums[l] == c)
                        ans.push_back({ nums[a], c, nums[b]});
               

                b--;
                for( ; b > a+1; )
                {
                    if(nums[b] == nums[b+1])
                        b--;
                    else
                        break;
                }

                // decrement b and avoid duplicates
            }
            a++;
            for( ; a< n-2; )
            {
                if(nums[a] == nums[a-1])
                    a++;
                else
                    break;
            }
            // increment a nad avoid duplicates
        }
        
        
        return ans;
    }
};