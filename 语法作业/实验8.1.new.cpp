#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	fstream f1out("f1.dat",ios::out);
	int t;
	for (int i=1;i<10;i++)
	{
		cin>>t;
		f1out<<t<<" ";
	}
	f1out.close();
	fstream f2out("f2.dat",ios::out);
	for(int i=1;i<10;++i)
	{
		cin>>t;
		f2out<<t<<" ";
	}
	f2out.close();
	fstream f1in("f1.dat",ios::in);
	f2out.open("f2.dat",ios::app);
	for(int i=1;i<=10;++i)
	{
		f1in>>t;
		f2out<<t<<" ";
	}
	f2out.close();
	f1in.close();
	fstream f2in("f2.dat",ios::in);
	int a[100];
	for(int i=1;i<=20;++i)
	{
		f2in>>a[i];
	}
	f2in.close();
	sort(a+1,a+21,cmp);
	f2out.open("f2.dat",ios::out);
	for(int i=1;i<=20;++i)
	{
		f2out<<a[i]<<" ";
	}
	return 0;
}
