/*【问题描述】定义如下形式的point 类，其对象表示平面上的一个点(x,y)，
  设计一个友元函数dis()求出两个对象（平面点）间的距离。并编制主函数，通过类对象验证相关函数的正确性。
  class point 
  {
  double x,y;
  public:
  point (double x0=0, double y0=0) {x=x0; y=y0;}
  void display();
  };
  两点间的距离公式，开根号函数为sqrt()。
  【输入形式】四个实数，前两个实数是一个点的坐标，后两个实数是另一个点的坐标。坐标中前一个数是横坐标，后一个数是纵坐标。
  【输出形式】输出三行数据，第一行是第一个点坐标，第二行是第二个点坐标，坐标输出形式为(x,y)，第三行是一个实数，代表两个点之间的距离。
  【样例输入】1.2 -3.5 -1.5 6
  【样例输出】
  (1.2,-3.5)
  (-1.5,6)
  9.87623*/
#include <iostream>
#include <cmath>
using namespace std;
class point
{
	double x,y;
public:
	point (double x0=0,double y0=0)
	{
		x=x0;
		y=y0;
	}
	void display()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	friend void dis(const point &p1,const point &p2);
};
void dis(const point &p1,const point &p2)
{
	double distance = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	cout << distance << endl;
}
int main()
{
	double x1,y1;
	double x2,y2;
	cin>>x1>>y1>>x2>>y2;
	point p1(x1,y1);
	point p2(x2,y2);
	p1.display();
	p2.display();
	dis(p1,p2);
	return 0;
}
