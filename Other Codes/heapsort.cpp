#include <bits/stdc++.h>
using namespace std;
void swap(int* f,int* s)
{
	int temp=*f;
	*f=*s;
	*s=temp;
}
void heapify(int a[],int n,int i)
{
	int root=i;
	int l=2*i+1;
	int r=2*i+2;
	int largest=root;
	if(l<n && a[l]>a[root])
	{	largest=l;
	}
	if (r<n && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest!=root)
	{
		swap(a[largest],a[root]);

		heapify(a,n, largest);
	}
}

void heapsort(int a[],int n)
{	
	for (int i = n/2 -1 ; i>=0 ; --i)
	{
		heapify(a,n,i);
	}

	for (int i = n-1; i >= 0 ; --i)
	{	swap(a[0],a[i]);
		heapify(a,i,0);
		
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

	heapsort(a,n);
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}





	return 0;
}