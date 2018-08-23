#include<bits/stdc++.h>
using namespace std;
int countnum;
void rangeUpdate_Lazy(int tree[],int lazy[],long node,long start,long end,long l,long r,int val)
{	//cout<<"\n entered buildtree with node :"<<node<<" start : "<<start<<" end : "<<end<<" with poster value : "<<val<<endl;
	if (lazy[node ]!= 0)
	{	if (start != end)
		{
			lazy[2*node]= lazy[node];
			lazy[2*node+1]=lazy[node];  
			lazy[node] = 0;
		}
		
	}

	if (start>end || start >r || end < l)
	{
		return ;
	}
	if (start>=l && end<=r)
	{
		tree[node]=val;
		if (start!=end)
		{
			lazy[2*node]=val;
			lazy[2*node+1]=val;
		}
		//cout<<"\n stored the poster value : "<<val<<" in node : "<<node<<" with start : "<<start<<" and end : "<<end<<endl;
		return ;
	}
	long mid=(start+end)/2;
	rangeUpdate_Lazy(tree,lazy,2*node,start,mid,l,r,val);
	rangeUpdate_Lazy(tree,lazy,2*node+1,mid+1,end,l,r,val);
	return ;

}
void query (bool flag[],int tree[],int lazy[],long node,long start,long end,long  idx)
{	//cout<<"\n entered query func with node :"<<node<<" start : "<<start<<" end : "<<end<<" searching for section : "<<idx<<endl;
	if (lazy[node]!=0)
	{
		if (start!=end)
		{
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
			lazy[node]=0;
		}
		else if(tree[node]==0)
		{	//cout<<"\n LA LIGA\n";
			tree[node]=lazy[node];
			//cout<<"\n LA LIGA   tree[node] is updated with "<<tree[node]<<"\n";
		}
		
	}
	if (start==end )
	{	//cout<<"\n entered the leaf node\n";
		if (tree[node]!=0 && flag[tree[node]]==false)
		{
			//poster=tree[noelse{de];
			//if (flag[tree[node]]==false)
		//	{
				countnum++;
				//cout<<"\ntree[node]  "<<tree[node]<<"  node is: "<<node;
				flag[tree[node]]=true;

		//	}
		 }
		 //else{
		// 	//poster=lazy[node];
		// //	if (flag[lazy[node]]==false)
		// //	{
		// 		countnum++;
		// 		flag[lazy[node]]=true;
		// 			cout<<"\nlazy[node]  "<<lazy[node]<<"  node is: "<<node;
		// //	}
		// }
		return ;
	}
	long mid=(start+end)/2;
	if(start<=idx && mid>=idx)
	{
		query(flag,tree,lazy,2*node,start,mid,idx);
	}else{
		query(flag,tree,lazy,2*node+1,mid+1,end,idx);
	}
	return ;

}
int main()
{	long t,n;
	cin>>t;
	while(t--){	
		countnum=0;
		cin>>n;
		long l[n+1],r[n+1],min=10000005,max=0;
		for (long i = 1; i <= n ; ++i)
		{	cin>>l[i];
			cin>>r[i];
			if (min>l[i])
			{
				min=l[i];
			}
			if (max<r[i])
			{
				max=r[i];
			}
		}
		//cout<<"\n"<<min<<"  "<<max<<endl;

		int tree[4*int(max-min+1)]={0};
		int lazy[4*int(max-min+1)]={0};
		bool flag[n+1]={false};
		// for (int i = 1; i <= n; ++i)
		// {
		// 	flag[i]=false;
		// }
		for (int i = 1; i <= n; ++i)
		{
			rangeUpdate_Lazy(tree,lazy,1,1,max-min+1,l[i]-min+1,r[i]-min+1,i);
		}
		//cout<<"\n completed building the tree, moving on to queries\n";
		for (long i = 1; i <= max-min+1; ++i)
		{
			query (flag,tree,lazy,1,1,max-min+1,i);
		}
		cout<<countnum<<"\n";


	}
	return 0;
}