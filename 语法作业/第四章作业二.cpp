#include<iostream>
using namespace std;
int main()
{
	int qinmi(int n);
	int n;
	cin>>n;
	qinmi(n);
	return 0;
}
bool b;
int qinmi(int n)
{
	
	for(int i=2;i<=n;i++)   //不包括数字本身，故去除1
	{
		int asum=1,bsum=1;    //所有数字的因子都含有1
		for(int j=2;j<=(i/2);j++)  //求A除本身外的因子和asum
		{
			if(i%j==0)
				asum=j+asum;
		}
		for(int m=2;m<=(asum/2);m++)  //求asum除去本身外的因子和bsum
		{
			if(asum%m==0)
				bsum=bsum+m;
		}
		if(bsum==i&&i<asum)//判断i与bsum是否相等，并去除重复值
		{
			cout<<bsum<<" "<<asum<<endl;
			b=1;
		}
	}
	if(b==0)
		cout<<"No"<<endl;
	return 0;
}
