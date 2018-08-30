#include<bits/stdc++.h>
using namespace std;
long n;

// long partition_qselect (int a[],long low,long high)
// {	//randomizing to reduce complexity to linear
// 	//long piv=rand()%(high-low+1);
// 	long piv= (low+high)/2;
// 	//piv=low+piv;
// 	int temp;
// 	temp=a[low];
// 	a[low]=a[piv];
// 	a[piv]=temp;

// 	//going onto select the new pivot
// 	piv=low;
// 	long i=low;
	
// 	for (long j = low+1; j<=high; ++j)
// 	{	
// 		if (a[j]<=a[piv])
// 		{	++i;
// 			//cout<<"\n\t swapping at i : "<<i<<" j: "<<j<<endl; 
// 			temp=a[i];
// 			a[i]=a[j];
// 			a[j]=temp;
// 		}
// 	}
// 		temp=a[low];
// 		a[low]=a[i];
// 		a[i]=temp;
// 	// 	cout<<"In partion, low: "<<low<<" high : "<<high<<endl;
// 	// for (int m=1;m<=n;m++)
// 	// {	cout<<a[m]<<"\t";
			
// 	// }
// 	// cout<<endl;
// 		return i;

// }
// void q_select (int a[],long low,long high,long k)
// {	//cout<<"In q-sort, low: "<<low<<" high : "<<high<<endl;
// 	long pivot=partition_qselect(a,low,high);
// 	if (pivot==k)
// 	{
// 		return;
// 	}
// 	if (pivot<k)
// 	{	//cout<<"\npivot : "<<pivot<<"  < median "<<" low: "<<pivot+1<<" high is: "<<high<<endl;
// 		q_select(a,pivot+1,high,k);
// 	}
// 	else{
// 		//cout<<"\npivot : "<<pivot<<"  > median "<<" low: "<<low<<" high is: "<<pivot-1<<endl;
// 		q_select(a,low,pivot-1,k);
// 	}
// 	return;
// }
int main()
{	//for faster input 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long k,l,r,i,median;
    cin>>n>>k;
    median=(1+n)/2;
    int a[n+1]={0};
    while(k--)
    {	cin>>l>>r;
    	// if (min>l)
    	// {
    	// 	min=l;
    	// }
    	// if (max<r)
    	// {
    	// 	max=r;
    	// }
    	
    	a[l]+=1;
    	if (r<n)
    	{
    		a[r+1]-=1;
    	}
    }
  
 	for(i=2;i<=n;i++)
 	{	a[i]=a[i-1]+a[i];
	}
	// cout<<endl;
	// for (i=1;i<=n;i++)
	// {	cout<<a[i]<<"\t";
			
	// }
	// cout<<endl;
	
	sort(a+1,a+n+1);
	cout<<a[median]<<"\n";
	// cout<<endl;
	// for (i=1;i<=n;i++)
	// {	cout<<a[i]<<"\t";
			
	// }
	// cout<<endl;


	return 0;

}