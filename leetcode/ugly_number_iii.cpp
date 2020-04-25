#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long euclidean_gcd(long long a, long long b)
	{
		if(b==0) return a;
		return euclidean_gcd(b, a%b);
	}
	long long  LCM (long long a, long long b)
	{
		long long gcd = euclidean_gcd(a, b);
		long long lcm = a * (b/gcd);
		return lcm;
	}

	int b_search(long long  l, long long  r, long long key, int a, int b, int c, long long lcm_ab, long long lcm_bc, long long lcm_ac, long long lcm_abc)
	{	//cout<<"\nl : "<<l<<"	r: "<<r<<endl;
		if(l < r)
		{
			long long num = (l+r)/2;
			long long val =  (long long)(num/a) +  (long long)(num/b) +  (long long)(num/c) -  (long long)(num/lcm_ab) -  (long long)(num/lcm_bc) - 
									 (long long)(num/lcm_ac) +  (long long)(num/lcm_abc);
			//cout<<"key :"<<key<<"	val : "<<val<<"  num: "<<num<<endl;
			if (val == key)
				return b_search(l, num, key, a, b, c, lcm_ab, lcm_bc, lcm_ac, lcm_abc);
			if( val < key)
				return b_search(num+1, r, key, a, b, c, lcm_ab, lcm_bc, lcm_ac, lcm_abc);
			if(val > key)
				return b_search(l, num-1, key, a, b, c, lcm_ab, lcm_bc, lcm_ac, lcm_abc);
			

		}
		return l;
	} 
    int nthUglyNumber(int n, int a, int b, int c) {
        long long  lcm_ab = LCM(a, b);
        long long lcm_bc = LCM(b, c);
        long long  lcm_ac = LCM(a, c);
        long long lcm_abc = LCM(lcm_ab, c);

        //cout<<"lcm_abc : "<<lcm_abc<<endl;

        int ans = b_search(1, 2000000000, n, a, b, c, lcm_ab, lcm_bc, lcm_ac, lcm_abc);
        return ans;
    }
};
int main()
{	
	Solution solution = Solution();
	cout<<solution.nthUglyNumber(1000000000, 2, 217983653, 336916467);
	//cout<<solution.nthUglyNumber(6, 2 ,3, 1);
	return 0;
}