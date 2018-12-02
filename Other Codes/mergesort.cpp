#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m, int r)
{	int n1=m-l+1,n2=r-m;
	int left[m-l+1],right[r-m];
	
	for (int i = 0; i < m-l+1; ++i)
	{
		left[i]=a[i+l];
	}
	for (int i = 0; i < r-m; ++i)
	{
		right[i]=a[m+1+i];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{	if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
			k++;
		}
		else
		{
			a[k]=right[j];
			j++;
			k++;
		}	

	}
	if(i==n1)   //left array is empty
	{	while(j<n2)
		{
			a[k]=right[j];
			j++;
			k++;
		}

	}
	else{
		while(i<n1)
		{
			a[k]=left[i];
			i++;
			k++;
		}
	}
}
void mergesort(int a[],int l ,int r)
{
	if(l<r)
	{	int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}

}
int main()
{	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";

	}
	cout<<endl;

	return 0;
}