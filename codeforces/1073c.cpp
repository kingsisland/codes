//incomplete question
#include <bits/stdc++.h>
using namespace std;
long absFun(long n )
{
	if(n>=0)
	{
		return n;
	}	
	else
	{	return n*(-1);

	}

}
int main()
{	long n,x,y,nu=0,nd=0,nl=0,nr=0,cx=0,cy=0,min=2000005,max=-1,len,count;
	int xflag=0,yflag=0;
	cin>>n;
	string a;
	cin>>a;
	cin>>x>>y;
	
	if(abs(x)+abs(y) <= n )
	{

	for (int i = 0; i < n; ++i)
	{
		if(a[i]=="U")
		{	cy++;
			nu++;

		}
		if(a[i]=="D")
		{	cy--;
			nd++;

		}
		if(a[i]=="L")
		{	cx--;
			nl++;

		}
		if(a[i]=="R")
		{	cx++;
			nr++;

		}
	}
	if(cx==x && cy ==y)
	{
		cout<<"0";
	}
	else
	{
		if(abs(cy-y)>0)
		{	len=abs(cy-y);
			
			if(cy < y)
			{	
				if(nd >= (y-cy))
				{	count=0;
					for (int i = 0; i < n && count <= len; ++i)
					{	if(a[i]== 'D')
						{	count++;
							a[i]='i';
							if(i<min)
							{
								min=i;
							}
							if(i>max)
							{
								max=i;
							}

						}
					
					}
					yflag=1;

				}
				else
				{	count=0;
					for (int i = 0; i < n && count <= len; ++i)
					{	if (a[i])
						{
							
						}
					
					}

				}


			}

		}
	}




	








	}
	else    //impossible scene
	{
		cout<<"-1";
	}

	return 0;
}