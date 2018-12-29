#include <bits/stdc++.h>
using namespace std;
int n,k,t;
map <int,int> res;
queue <int> q;
int main()
{	
	cin>>n>>k;
	if(n&1)
	{
		res[1]++;
	}
	for (int i = 1; i <= 30; ++i)
	{
		if(n&(1<<i))
		{	res[1<<i]++;
			q.push(1<<i);
		}
	}	

	int count = res.size();
	if (count > k)
	 {
	 	puts("NO");
	 	return 0;
	 }
	 if (count < k)
	  {
	  	 while(count<k && !q.empty())
	  	 {	t=q.front();
	  	 	q.pop();
	  	 	res[t]--;
	  	 	if (t/2 > 1)
	  	 	{
	  	 		q.push(t/2);
	  	 		q.push(t/2);
	  	 	}
	  	 	res[t/2]+=2;
	  	 	count++;
	  	 }
	  	 if (count < k)
	  	 {
	  	 	puts("NO");
	  	 	return 0;
	  	 }
	  }
	  puts("YES");
	 for(auto x : res)
		for(int i = 0; i < x.second; i++)
			printf("%d ", x.first);
	puts("");
	    


	return 0;
}