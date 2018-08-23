#include <bits/stdc++.h>
using namespace std;
void merge_sort(int  a[],int start,int  mid,int end)
{	int p=start;
	int q=mid+1;
	int arr[end-start+1];
	int k=0;
	for (int i = start; i <= end; ++i)
	{	if (p>mid)
		{	arr[k]=a[q];
			k++;
			q++;
		}
		else if (q>end)
		{
			arr[k]=a[p];
			p++;
			k++;
		}
		else if(a[p]<=a[q])
		{
			arr[k]=a[p];
			k++;
			p++;
		}
		else if (a[q]<a[p])
		{
			arr[k]=a[q];
			k++;
			q++;
		}
	}
	for (int i = 0; i < k; ++i)
	{	a[i+start]=arr[i];
	}
	cout<<"\n partially sorted array with start : "<<start<<" and end : "<<end<<endl;
	for (int i = 0; i < k; ++i)
	{
		cout<<" "<<a[i+start];
	}
	cout<<endl;

}
void merge_partition (int a[],int start,int end)
{	if (start<end)
	{	int  mid=start+(end-start)/2;
		cout<<"\n mid is : "<<mid<<" start is : "<<start<<" end is : "<<end<<endl;
		merge_partition(a,start,mid);
		merge_partition(a,mid+1,end);
		merge_sort(a,start,mid,end);
	}


}
int main(int argc, char const *argv[])
{	int n;
	cout<<"\t Enter the number of elements : "; 
	cin>>n;
	int a[n];
	cout<<"\n Enter the elements : ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//merge sort
	merge_partition(a,0,n-1);
	cout<<"\n The sorted array is : \n";

	for (int i = 0; i < n; ++i)
		{
			cout<<"\t"<<a[i];
		}	
		cout<<endl;
	return 0;
}