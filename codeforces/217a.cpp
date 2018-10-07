#include <bits/stdc++.h>
using namespace std;
void initiallize_dsu(int arr[],int size[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i]=i;
		size[i]=1;
	}
}
int find_root (int arr[],int i)
{
	while(arr[i] != i)
	{
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	return i;
}
void join_dsu (int arr[], int size[],int i,int j )
{	//cout<<"\n Join of i : "<<i<<" and j: "<<j<<endl;
	int root_i=find_root(arr,i);
	int root_j=find_root(arr,j);
	if (size[root_i] < size[root_j])
	{
		arr[root_i]=root_j;
		size[root_j]+=size[root_i];
	}
	else
	{
		arr[root_j]=root_i;
		size[root_i]+=size[root_j];
	}
}

int main()
{
	int n,x,y,count;
	cin>>n;
	int vx[1005];
	int vy[1005];
	for (int i = 0; i < 1005; ++i)
	{
		vx[i]=vy[i]=-1;
	}
	int arr[n],size[n];
	initiallize_dsu(arr,size,n);
	
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		if(vx[x] != -1 )
	 		join_dsu(arr,size,i,vx[x]);
		if (vy[y] != -1)
			join_dsu(arr,size,i,vy[y]);
		vx[x]=i;
		vy[y]=i;
	}
	count=-1;
	for (int i = 0; i < n; ++i)
	{
		if(find_root(arr,i)== i )
			count++;
	}
	cout<<count;

	
	


		



	return 0;
}