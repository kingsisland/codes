#include <bits/stdc++.h>
using namespace std
void swap(int *a,int *b)
{	int temp=*a;
	*a=*b;
	*b=temp;
}
int sort_partition (int a[],int start,int end)
{	int pi= a[start];
	int i=start+1;
	for (int j=start+1;j<=end;j++)
	{	if (a[j]<pi)
		{	swap(a[i],a[j]);
			i+=1;
		}
	}
	i-=1;
	swap(a[start],a[i]);
	return i;

}
void q_sort(int a[],int start,int end)
{	if (start<end)
	{	int pi=sort_partition(a,start,end);
		q_sort(a,start,pi-1);
		q_sort(a,pi+1,end);
	
	}

}
int main(int argc, char const *argv[])
{	int n;
	cout<<"\n Enter the number of elements: ";
	cin>>n;
	int a[n];
	cout<<"\n Enter the elements : \n";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}


	
	return 0;
}