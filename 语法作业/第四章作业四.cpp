#include<iostream>
using namespace std;
double digit(long n,int k); 
int main()
{
	long n;
	int k;
	cin>>n>>k;
	cout<<digit(n,k);
} 
double digit(long n,int k)
{
	int c;
	for(int i=1;i<=k;i++)
	{
		if (n==0)
			return -1;
		c=n%10;
		n/=10;
	}
	return c;
}
