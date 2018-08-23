#include <bits/stdc++.h>
using namespace std;
class Tree {
public:
	// hint node;
	map<long, int > nf;
}; 
void findfrq (Tree& tree,long a[],int node,int start,int end)
  { 
	for (int i = start; i <= end; ++i)
	{	tree[node].nf[a[i]]++;
	}
	
  }

void build (Tree& tree,int node,long a[],int start,int end){
	if (start==end)
	{
		if (a[start]==1)
		{
			tree[node].nf[a[start]] = 1;
		}
	}
	else{
		int mid= (start+end)/2;
		
		build(tree,a,2*node,start,mid);
		build(tree,a,2*node+1,mid+1,end);
	
		findfrq(tree,node,a,start,end);
	}
}

Tree query (Tree& tree,long a[],int node,int start,int end,int l,int r)
{	if (end < l || start > r)
	{	Tree dummy;
		return dummy;

	}
	if (start>= l && end<= r)
	{	return tree[node];
	}
	
    int mid=(start+end)/2;
    Tree b,c,result;
    b=query(tree,a,2*node,start,mid,l,r);
    c=query(tree,a,2*node+1,mid+1,end,l,r);
    map <long, int > :: iterator i=b.nf.begin();
    map <long, int > :: iterator j=c.nf.begin();
    if (b.nf.size() <= c.nf.size())
    {	for (;j != c.nf.end();++j)
    	{
    	   b.nf[j->first]+=j->second;
    	}
    	return b;
    	
    }
    else{
    	for (;i != b.nf.end();++i)
    	{
    	   c.nf[i->first]+=i->second;
    	}
    	return c;
    }

}

int main(int argc, char const *argv[])
{
	int n,m,l,r;
	
	cin>>n>>m;
	long a[n+1];
	Tree tree[2*n];
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
		// cout<<query(tree,a,1,1,n,l,r)<<"\n";
		Tree result=query(tree,a,1,1,n,l,r);
		map<long,int> :: iterator itr;
		cout<<"\n key: \t value:\n";	
		for (itr=result.nf.begin();itr != result.nf.end(); itr++)
		{
			cout<<itr->first<<"\t"<<itr->second<<endl;
		}

	}
	return 0;
}