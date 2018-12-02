#include<bits/stdc++.h>
using namespace std;
void build(map<long,long> tree[],long freq[],long a[],long node,long start,long end)
{	//cout<<"\n entered build with node : "<<node<<" and start : "<<start<<" end : "<<end<<"\n";
	if (start==end)
	{	if (a[start] <= 100000 && freq[a[start]] >= a[start])
		{
			map<long,long>& m=tree[node];
			m[a[start]]++;
		}
	//cout<<"\n START == END and node is : "<<node<<"  a[start] is  "<<a[start]<<" and m[a[start]] --> "<<m[a[start]]<<endl;
	}
	else{
		long mid=(start+end)/2;
		build(tree,freq,a,2*node,start,mid);
		build(tree,freq,a,2*node+1,mid+1,end);
		map<long,long> am=tree[2*node];
		map<long,long> bm=tree[2*node+1];
		map<long,long> &rm=tree[node];
		map<long,long> :: iterator itr;
		//cout<<"\n start is "<<start<<" and end is : "<<end<<endl;
		for (itr=am.begin();itr!= am.end();++itr)
		{
			rm[itr->first]=itr->second;
		}
		for (itr=bm.begin();itr!= bm.end();++itr)
		{	rm[itr->first]+=itr->second;
 		// 	if (rm[itr->first]>0)
			// {
			// 	rm[itr->first]+=itr->second;
 
			// }
			// else{
			// 	rm[itr->first]=itr->second;
			// }
		}
		//erasing the map entries with freq more than value
		for (itr=rm.begin();itr!=rm.end();++itr)
		{
			if (itr->second > itr->first)
			{
				rm.erase(itr->first);
			}
		}
		// cout<<"\t Element \t Frequency\n";
		// for (itr=rm.begin();itr!= rm.end();++itr)
		// {	cout<<itr->first<<"\t"<<itr->second<<endl;
			
		// }
		//return rm;	
	}
}
//query function that returns a map
map<long,long> query (map<long,long> tree[],long a[],long node,long start,long end,long l,long r)
{	//cout<<"\nEntered Query\n";
	if (start > r || end < l)
	{	//cout<<"\n Returned the dummy node : "<<node<<" with start :"<<start<<" and end : "<<end<<"\n";
		map<long,long> dummy;
		return dummy;
	}
	if (start>=l && end<=r)
	{	//cout<<"\n Returned the node : "<<node<<" with start :"<<start<<" and end : "<<end<<"\n";
		return tree[node];
	}
	long mid=(start+end)/2;
	map<long,long> am=query(tree,a,2*node,start,mid,l,r);
	map<long,long> bm=query(tree,a,2*node+1,mid+1,end,l,r);
	map<long,long> rm;
	map<long,long> :: iterator itr;
	for (itr=am.begin();itr!= am.end();++itr)
		{
			rm[itr->first]=itr->second;
		}
		for (itr=bm.begin();itr!= bm.end();++itr)
		{
			 rm[itr->first]+=itr->second;
			// if (rm[itr->first]!=0)
			// {
			// 	rm[itr->first]+=itr->second;
 
			// }
			// else{
			// 	rm[itr->first]=itr->second;
			// }
		}
		 return rm;	
		 //cout<<"\n Returned the sum of two nodes and node  : "<<node<<" with start :"<<start<<" and end : "<<end<<"\n";
}
 
int main()
{	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long n,m,l,r,ans;
	cin>>n>>m;
	long a[n+1];
	//bool flag[n+1];
	long freq[100002]={0};
 
	map <long,long> tree[4*100000];
	for (long i = 1; i <= n; ++i)
	{
		cin>>a[i];
		if (a[i] <= 100000)
		{
			freq[a[i]]+=1;;
		}
	}


	build(tree,freq,a,1,1,n);
	while(m--)
	{	cin>>l>>r;
		ans=0;
		map<long,long> result=query(tree,a,1,1,n,l,r);
		map<long,long> :: iterator itr;
		for (itr=result.begin();itr!=result.end();++itr)
		{
			if (itr->first == itr->second)
			{  
				 ++ans;
			}
		}
		cout<<ans<<"\n";
 
	}
 
 
 
	return 0;
}