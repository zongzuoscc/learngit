#include <iostream>
using namespace std;
int main()
{
	int x[50],y[50];
	int k,i,sum=0,n=0,m=0,j;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>x[i];
	}
	for(i=0;i<k;i++)
	{
		sum+=x[i];
	}
	double ave;
	ave=(double)sum/k;
	for(i=0;i<k;i++)
	{
		if(x[i]>ave)
		{
			n++;
		}
	}
	cout<<ave<<" "<<n<<endl;
	for(i=1,y[0]=x[0],m=1;i!=k;i++)
	{
		for(j=0;j<i;j++)
		{ 
			if(x[i]==x[j])
				break;
		}		
		if(j==i)
		{
			y[m]=x[i];
			m++;
		}	
	}
	for(i=0;i<m;i++)
	{
		cout<<y[i]<<" ";
	}
	return 0;
}
