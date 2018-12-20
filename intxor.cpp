#include <bits/stdc++.h>
using namespace std;
long long res[60000],ans[60000];
long long t,n,i,ctr,flag=0,a,b,c,temp,place;

void evenN()
{
		ctr=1;
		flag=0;
		a=1;
		b=2;
		c=3;
		while(ctr<=n)
		{
			if(flag==2)
			{   flag=0;

				a=(a+2);
				b=(b+2);
				// if(a>n)
				// 	a=1;
				if(b>n)
					b=1;
			}
			cout<<"1 "<<a<<" "<<b<<" "<<c<<" \n"<<flush;
			cin>>res[ctr]; 	
			
			c=(c+1);
			if(c>n)
				c=1;


			flag++;
			ctr++;
		}
		i=1;	
		place=5;
		while(i<n)
		{
			temp=(res[i]^res[i+1]);
			if(i+2<=n)
			{	//cout<<"I: "<<i<<endl;
				ans[place]=(temp^res[i+2]);
				//cout<<"\n ans["<<place<<"] : "<<ans[place]<<endl;
				place=(place+1);
				if(place>n)
					place=1;
			}
			if(i+3<=n)
			{	//cout<<"I: "<<i<<endl;
				ans[place]=(temp^res[i+3]);
				//cout<<"\n ans["<<place<<"] : "<<ans[place]<<endl;
				place=(place+1);
				if(place>n)
					place=1;
			}

			i=i+2;

		}

		temp=(ans[1]^ans[2]);
		ans[3]=(res[1]^temp);
		ans[4]=(res[2]^temp);
		cout<<"2 ";
		for (int j = 1; j <=n; ++j)
		{
			cout<<ans[j]<<" ";
		}
		cout<<"\n"<<flush;
		cin>>temp;

		return;

}



void oddN()
{		ctr=1;
		flag=0;
		a=1;
		b=2;
		c=3;
		while(ctr<=n-3)
		{
			if(flag==2)
			{   flag=0;

				a=(a+2);
				b=(b+2);
			}
			cout<<"1 "<<a<<" "<<b<<" "<<c<<" \n"<<flush;
			cin>>res[ctr]; 	
			
			c=(c+1);
			
			flag++;
			ctr++;
		}

		a=a+2;
		b=b+2;
		cout<<"1 "<<a<<" "<<b<<" "<<c<<" \n"<<flush;
		cin>>res[ctr]; 
		ctr++;
		
		cout<<"1 "<<n<<" "<<n-2<<" "<<"1 \n"<<flush;
		cin>>res[ctr];
		ctr++;

		cout<<"1 "<<n<<" "<<n-1<<" "<<"2 \n"<<flush;
		cin>>res[ctr];

		//calculating ans	
		i=1;	
		place=5;
		while(i<= n-4)
		{
			temp=(res[i]^res[i+1]);
			if(i+2<=n-2)
			{	
				ans[place]=(temp^res[i+2]);
	
				place=(place+1);
				
				if(i+3 <= n-3)
				{

				ans[place]=(temp^res[i+3]);
				place=(place+1);
				}
				
			}
			

			i=i+2;

		}

		ans[1]= res[n-1]^ans[n]^ans[n-2];
		ans[2]= res[n]^ans[n]^ans[n-1];

		temp=(ans[1]^ans[2]);
		ans[3]=(res[1]^temp);
		ans[4]=(res[2]^temp);
		cout<<"2 ";
		for (int j = 1; j <=n; ++j)
		{
			cout<<ans[j]<<" ";
		}
		cout<<"\n"<<flush;
		cin>>temp;

		return;









}
int main(int argc, char const *argv[])
{
	
	cin>>t;
	while(t--)
	{
		cin>>n;

		if(n%2 == 0)
			evenN();

		if (n%2==1)
			oddN();
		
		


	}	


	return 0;
}
