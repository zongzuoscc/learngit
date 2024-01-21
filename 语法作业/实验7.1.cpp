/*矿大1818美食广场新开的水吧推出一个饮料促销活动，制定了如下促销策略：
  （1）咖啡（Coffee）：每杯P元，买G杯，需支付G*P元。
  （2）果茶（Tea）：八折，每杯P元，买G杯，需支付G*P*0.8元。
  （3）总购买杯数为GTotal，如果GTotal>6，打八折，即需支付P*GTotal*0.8元；如果GTotal>4，打九折，即需支付P*GTotal*0.9元；其他情况不打折。
  请编写一个程序计算某个同学购买饮品的总价，每类饮品只购买一次。
  要求该程序至少应有：
  （1）Drink类：包括属性如下：饮品类别（DName），饮品数量(DQuantity)，饮品单价(DPrice)。
  （2）Coffee类增加温度（CTem，冷：cool; 热：hot ）和糖度（CSug,半糖:half -sug,全糖:full-sug）属性；
  Tea类增加温度（TTem）和口味（TTas,柠檬：lemon，绿茶：green-tea）。
  【输入格式】
  输入的第一行是一个整数N（1<=N<=10），表示饮料的类别总数。接下来的N行，
  每行是一类饮料的数据，从左向右依次是，饮品类别、饮品数量、饮品单价。饮品类别用大写字母字符表示：C（咖啡）、T（果茶）。
  Coffee类对象后面为温度和糖度，Tea类对象后面为温度和口味。
  【输出格式】
  输出多行。输出各类别饮品的信息与该类饮品的总价。输出购买饮品的总价。格式见样例输出。
  【样例输入】
2
C 2 15 hot half-sug
T 1 10 cool green-tea
  【样例输出】
C 2 15 hot half-sug 30
T 1 10 cool green-tea 8
总价:38
3
C 2 15 hot half-sug
C 3 15 hot half-sug
T 2 10 cool green-tea 
 */
#include <iostream>
#include <string>

using namespace std;
int sum;//sum代表总杯数
double total;//total代表总价格
class Drink
{
public:
	string DName;
	int DQuantity;
	double DPrice;
};
class Coffee:public Drink
{
public:
	string CTem;
	string CSug;
	void get()
	{
		cin>>DQuantity>>DPrice>>CTem>>CSug;
		sum+=DQuantity;
	}
	void print()
	{
		double k=DQuantity*DPrice;
		cout<<DQuantity<<" "<<DPrice<<" "<<CTem<<" "<<CSug<<" ";
		cout<<k<<endl;
		total+=k;
	}
};
class Tea:public Drink
{
	string TTem;
	string TTas;
public:
	void get()
	{
		cin>>DQuantity>>DPrice>>TTem>>TTas;
		sum+=DQuantity;
	}
	void print()
	{
		double k=DQuantity*DPrice*0.8;
		cout<<DQuantity<<" "<<DPrice<<" "<<TTem<<" "<<TTas<<" ";
		cout<<k<<endl;
		total+=k;
	}
};
int main()
{
	int n;
	cin>>n;
	char c;
	Coffee a;
	Tea b;
	for (int i=1;i<=n;++i)
	{
		cin>>c;
		cout<<c<<" ";
		if(c=='C')
		{
			a.get();
			a.print();
		}
		else
		{
			b.get();
			b.print();
		}
	}
	if (sum>6)
	{
		total*=0.8;
	}
	else if (sum>4)
	{
		total*=0.9;
	}
	cout<<"总价:"<<total;
	return 0;
}
