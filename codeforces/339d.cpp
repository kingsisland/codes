#include <bits/stdc++.h>
using namespace std;
int build (long tree[],long a[],long node, long start,long end)
{	if (start==end)
	{
		tree[node]=a[start];
		return 1;
	}
	else{
		long mid=(start+end)/2,r1,r2;
		r1=build(tree,a,2*node,start,mid);
		r2=build(tree,a,2*node+1,mid+1,end);
		if(r1==r2 && r1==1) // 1 for OR
		{	tree[node] = tree[2*node] | tree[2*node+1];
			return 0;
		}
		if(r1==r2 && r1==0)  // 0 for X or
		{	tree[node] = tree[2*node] ^ tree[2*node+1];
			return 1;
		}

	}

}
int update (long tree[],long a[],long node, long start,long end,long index,long value)
{	if (start==end)
	{	tree[node] = value;
		return 1;
	}
	else{
		long mid=(start+end)/2;
		long r;
		if (start<=index && index <= mid)
		{
			r=update(tree,a,2*node,start,mid,index,value);
		}else{
			r=update(tree,a,2*node+1,mid+1,end,index,value);
		}

		if (r==1)
		{
			tree[node]= tree[2*node] | tree[2*node + 1];
			return 0;
		}
		if (r==0)
		{
			tree[node]= tree[2*node] ^ tree[2*node + 1];
			return 1;
		}
	}

}


int main(int argc, char const *argv[])
{
	long n,m,i,p,b;
	cin>>n>>m;
	 n=long(pow(2.0,n));
	long a[n+1],tree[2*n];
	//getting the array
	for ( i = 1; i <= n; ++i)
		{	cin>>a[i];
		}
	// building the segment tree
	build(tree,a,1,1,n);

	while(m--)
	{	cin>>p>>b;
		update(tree,a,1,1,n,p,b);
		cout<<tree[1]<<"\n";
	


	}
	return 0;
}