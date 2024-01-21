#include<iostream>

#include<string>
#include <iomanip>
using namespace std;
class Fruit
{
private:
	double priceSum;//总价格
public:
	double price;//定义某个水果的单价
	double kilo;//定义某个水果买了多少千克
	Fruit (double p,double k)
	{
		price=p;
		kilo=k;
		priceSum=0;
	}
	virtual double getSum()//用于计算，价格
	{
		return 0;
	}
	void operator + (double k)//重载加法运算
	{
		priceSum+=k;
	}
	void show() //输出最后的价格
	{
		cout << fixed << setprecision(2) << priceSum;
	}
};


class Apple:public Fruit
{
public:
	Apple(double p,double k):Fruit(p,k){}
	double getSum()
	{
		return price*kilo;
	}
};

class Banana:public Fruit
{
public:
	Banana(double p,double k):Fruit(p,k){}
	double getSum()
	{
		return price*kilo/2.0;
	}
};

class Orange:public Fruit
{
public:
	Orange(double p,double k):Fruit(p,k){}
	double getSum()
	{
		if (kilo>10) return price*kilo/2.0;
		else if (kilo>5) return price*kilo*0.8;
		else return price*kilo;
	}
};

int main()
{
	char c;
	double p,k;
	Fruit f(0,0);
	cin>>c;
	while (c!='q')
	{
		cin>>k>>p;
		if (c=='a')
		{
			Apple a(p,k);
			f+a.getSum();
		}
		if (c=='b')
		{
			Banana b(p,k);
			f+b.getSum();
		}
		if (c=='o')
		{
			Orange o(p,k);
			f+o.getSum();
		}
		cin>>c;
	}
	f.show();
}

