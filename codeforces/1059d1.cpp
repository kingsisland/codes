#include <bits/stdc++.h>
using namespace std;
int main()
{	
	long n;
	int flag=0;
	cin>>n;
	
	double x[n],y[n],r,xa,xb,temp,xmin,xmax,ru,rl;

	for (long i = 0; i < n; ++i)
	{	
		cin>>x[i];
		
		cin>>y[i];
		
		
		if(i>0)
		{	if (y[i]*y[i-1] < 0)    //checking for input validity
			{  	cout<<"-1";
				flag=1;
				break;
			}
		}
	}

	if (flag==0)
	{	
		ru=1000000;
		rl=0;

		// xmax=x[0]-sqrt( (y[0])*(2*r-y[0]) );
		// xmin=x[0]+sqrt( (y[0])*(2*r-y[0]) );
		//r=(ru+rl)/2;
		while(ru>=rl)
		{	r=rl+(ru-rl)/2;
			xmax=x[0]-sqrt( (y[0])*(2*r-y[0]) );
			xmin=x[0]+sqrt( (y[0])*(2*r-y[0]) );
			//cout<<"\nAt the top, R: "<<r<<endl;
			for (int i = 0; i < n; ++i)
			{	//cout<<"\n r: "<<r<<" and x[i]: "<<x[i]<<"  y[i]: "<<y[i]<<endl;
				temp=abs(sqrt( (y[i])*(2*r-y[i]) ));
				//cout<<"\n temp is : "<<temp<<endl;
				if(isnan(temp)==true)
				{	
					break;
				}
				
				xb=x[i]+temp;
				xa=x[i]-temp;
				if (xmin > xb)
				{
					xmin=xb;
				}
				if (xmax < xa)
				{	xmax=xa;
				
				}
			
			}
			//cout<<"\n xmin-xmax : "<<xmin-xmax<<endl;
			if(isnan(temp)==true || xmin-xmax<0)
			{	//cout<<"\n isnan(temp) == TRUE \n ";
					rl=r-0.000001;
					
			}
			else if(xmin-xmax <=0.000001 && xmin-xmax>=0)
			{	cout<<r;
				//cout<<"\nFinal R is : "<<r<<endl;
				break;
			}
			else if(xmin-xmax > 0.000001)
			{
				ru=r+0.000001;

				
				//cout<<"\nNew R is : "<<r<<endl;
			}

			if(ru==rl)
			{
				rl=ru/2;
			}
			//cout<<"\n ru: "<<ru<<"  rl: "<<rl<<endl;
						
		}
		
		
	}






	return 0;
}