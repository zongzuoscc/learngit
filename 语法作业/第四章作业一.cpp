#include <iostream>
using namespace std;
int main()
{     
	int toOcr(int n);
	int n;
	cin>>n;
	toOcr(n);
	return 0;	
}
int toOcr(int n)
{
	int i,j;
	if(n==0)	
	{
		return 0;	
	}
	else	
	{
		j=n%8;
		i=n/8;
		toOcr(i);
		printf("%d",j);	
	}
	return j;
}
