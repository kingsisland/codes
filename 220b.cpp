#include <bits/stdc++.h>
using namespace std;
//int freq[1000000001]={0};
int findfrq (long a[],int start,int end)
 {	int result=0;
	map<long,int> hm;
	for (int i = start; i <= end; ++i)
	{	hm[a[i]]++;

	}
	map<long,int> :: iterator itr;
	for (itr = hm.begin(); itr != hm.end(); ++itr)
	{
		if (itr->first==itr->second)
		{
			result++;
		}
	}
	return (result);
	}

void build (long tree[],long a[],int node,int start,int end){
	if (start==end)
	{
		if (a[start]==1)
		{
			tree[node] = 1;
			//cout<<"\n tree["<<node<<"] is 1\n";
		}
		else{
			tree[node]=0;
			//cout<<"\n tree["<<node<<"] is 0\n";
		}
	}
	else{
		int mid= (start+end)/2;
		//cout<<"\n MID for "<<start<<" and "<<end<<" is : "<<mid<<endl;
		build(tree,a,2*node,start,mid);
		build(tree,a,2*node+1,mid+1,end);
		//cout<<"\nthe node is "<<node<<endl;
		tree[node] = findfrq(a,start,end);
	}
}

int query (long tree[],long a[],int node,int start,int end,int l,int r)
{
	if (end < l || start > r)
	{
		return 0;
	}
	if (start>= l && end<= r)
	{
		return tree[node];
	}
	int mid=(start+end)/2;
	int a1,b1;
	a1= query(tree,a,2*node,start,mid,l,r);
	b1= query(tree,a,2*node+1,mid+1,end,l,r);
	// return a1+b1;


  // int result=findfrq(a,l,r);
  // return result; 
}

int main(int argc, char const *argv[])
{
	int n,m,l,r;
	
	cin>>n>>m;
	long a[n+1],tree[2*n];
	for ( int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	//building the tree
	build(tree,a,1,1,n);
	// cout<<endl;
	// for (int i = 1; i < 2*n; ++i)
	// {
	// 	cout<<tree[i]<<"\t";
	// }
	// cout<<endl;

	while(m--)
	{
		cin>>l>>r;
		cout<<query(tree,a,1,1,n,l,r)<<"\n";
	}
	return 0;
}