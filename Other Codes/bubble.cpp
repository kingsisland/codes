#include<bits/stdc++.h>
using namespace std;
void swap (int *a,int* b)
{	int temp=*a;
	*a=*b;
	*b=temp;
}
void selectsort(int a[],int n)
{	int min,j;
	for (int i = 0; i < n-1; ++i)
	{	min=i;
		for ( j = i+1; j < n; ++j)
		{	if (a[min]>a[j])
			{
				min=j;
			}
			
		}
		swap(a[min],a[i]);
	}
	 cout<<endl;
	 for (int l = 0; l < n; ++l)
	 {
	 	cout<<"  "<<a[l];
	 }
	cout<<endl;



}

void insertion_sort(int a[],int n)
{	for (int i = 1; i < n; ++i)
	{	if (a[i]<a[i-1])
		{	for (int j = 0; j < i; ++j)
			{	if (a[j]>a[i])
				{	int temp=a[i];
					for (int k = i;k>j;k--)
					{	a[k]=a[k-1];
					}
					a[j]=temp;
					break;
				}
				
			}

		}
	
	}
	cout<<endl;
	 for (int l = 0; l < n; ++l)
	 {
	 	cout<<"  "<<a[l];
	 }
	cout<<endl;

}
//merge sort
void merge (int A[],int start,int mid,int end)
{	int p=start,q=mid+1;
	int Arr[end-start+1];
	for (int i = 0; i < end-start+1; ++i)
	{	if (p==mid+1)
		{	Arr[i]=A[q];
			q++;
		
		}
		else if (q==end+1)
		{	Arr[i]=A[p];
			p++;
		
		}
		else if (A[p]<=A[q])
		{	Arr[i]=A[p];
			p++;
		}
		else if (A[q]<A[p])
		{
			Arr[i]=A[q];
			q++;
		}
	}
	for (int i = 0; i+start <= end; )
	{	A[i+start]=Arr[i];
		i++;
		
	}

}
void merge_partition(int A[],int start,int end)
{	if (start<end)
	{ int mid=(start+end)/2;
		merge_partition(A,start,mid);
		merge_partition(A,mid+1,end);
		merge(A,start,mid,end);
	
	}

}
int main(int argc, char const *argv[])
{	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//insertion_sort(a,n);
	//selectsort(a,n);
	//bubble sort
	// int i,j;
	// for ( int k=0; k < n; ++k)
	// {	for (i = 0,j=i+1; j<n-k; ++i,++j)
	// 	{	if (a[i]>a[j])
	// 		{
	// 			swap(&a[i],&a[j]);
	// 		}
		
	// 	}
		
	// }
	
	merge_partition(a,0,n-1);
	cout<<endl;
	for (int l = 0; l < n; ++l)
	{
		cout<<"  "<<a[l];
	}
	cout<<endl;
	
	return 0;
}