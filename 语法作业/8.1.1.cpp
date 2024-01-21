#include<iostream>

using namespace std;
class Date
{
public:
	int year,month,day;
	Date();
	void setDate(Date);
	int isLeapYear(int);
	int getSkip(Date,Date);
	int days(Date &);
};
Date::Date()//构造空函数
{
	
}
int Date::days(Date &a)
{
	int sum;
	switch(a.month)
	{
		case 1:sum=0;break;
		case 2:sum=31;break;
		case 3:sum=59;break;
		case 4:sum=90;break;
		case 5:sum=120;break;
		case 6:sum=151;break;
		case 7:sum=181;break;
		case 8:sum=212;break;
		case 9:sum=243;break;
		case 10:sum=273;break;
		case 11:sum=304;break;
		case 12:sum=334;break;
	}
	sum=sum+a.day;
	if((a.year%400==0||(a.year%100!=0&&a.year%4==0))&&a.month>2)
		sum++;
	return sum;
}
void Date::setDate(Date o)
{
	cin>>o.year;
	cin>>o.month;
	cin>>o.day;
}
int Date::isLeapYear(int y)
{
	int flag=0;
	if(y%400==0||(y%4==0&&y%100!=0))
		flag=1;
	return flag;
}
int Date::getSkip(Date o1,Date o2)
{
	int Y,sum=0,i;
	Date tem;
	if(o1.year>o2.year)
	{
		tem=o1;
		o1=o2;
		o2=tem;
	}
	Y=o2.year-o1.year;
	sum=365*(Y-1);
	for(i=1;i<Y;i++)
		if(isLeapYear(o1.year+i))
			sum++;
	sum=sum+days(o2);
	if(isLeapYear(o1.year))
		sum=sum+366-days(o1);
	else sum=sum+365-days(o1);
	return sum;
}
int main()
{
	Date a1,a2;
	a1.setDate(a1);
	a2.setDate(a2);
	if(a1.isLeapYear(a1.year))
		cout<<a1.year<<" is leap year."<<endl;
	else cout<<a1.year<<" is not leap year."<<endl;
	if(a2.isLeapYear(a2.year))
		cout<<a2.year<<" is leap year."<<endl;
	else 
		cout<<a2.year<<" is not leap year."<<endl;
	cout<<"The skip of two date is "<<a1.getSkip(a1,a2)<<".";
}
