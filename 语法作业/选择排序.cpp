/*#include <iostream>
using namespace std;
int main()
{
	//此次用于书写，选择排序
	int i,j,p,k,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)
	{
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(a[p]>a[j])
			{
				p=j;
			}
			if (p!=i)
			{
				k=a[i];
				a[i]=a[p];
				a[p]=k;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}*/
#include <iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	int a[n];
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)
	{
		for (j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int k;
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
