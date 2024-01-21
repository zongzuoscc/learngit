/*【问题描述】定义一个包括年、月、日的结构体变量，读入年、月、日，计算该日在当年中是第几天。注意闰年问题。

请写一个函数days实现计算，将读入的结构体变量传递给days函数，计算后将答案返回给main函数进行输出。

【输入形式】三个整数，分别表示年、月、日。保证输入是实际存在的日期，且年份在1000至3000之间（包含1000和3000）。

【输出形式】输出该日期是一年中的第几天。请注意行尾输出换行。

【样例输入】2012 12 21

【样例输出】356*/
#include <iostream>
using namespace std;
struct date
{
	int year;
	int month;
	int day;
};
int days(date x);
int isleapyear(int year);
int main()
{
	date x;
	cout<<days(x)<<endl;
	return 0;
}
int days(date x)
{
	int sumdays=0,i;
	cin>>x.year>>x.month>>x.day;
	int monthdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if ((x.year%4==0&&x.year%100!=0)||x.year%400==0)
	{
		monthdays[2]=29;
	}
	else
	{
		monthdays[2]=28;
	}
	for (i=1;i<x.month;i++)
		sumdays+=monthdays[i];
	sumdays+=x.day;
	return sumdays;
}
