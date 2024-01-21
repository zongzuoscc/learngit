/*
#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
	
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	
	friend istream& operator>>(istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
	
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << "," << p.y << ")" << endl;
		return out;
	}
};

class Circle {
private:
	Point center;
	int radius;
	
public:
	Circle(int x = 0, int y = 0, int radius = 0) : center(x, y), radius(radius) {}
	
	friend istream& operator>>(istream& in, Circle& c) {
		in >> c.center >> c.radius;
		return in;
	}
	
	friend ostream& operator<<(ostream& out, const Circle& c) {
		out << c.center << c.radius << endl;
		return out;
	}
};

int main() {
	Point p(0, 0);
	cin >> p;
	cout << p;
	
	Circle c(0, 0, 0);
	cin >> c;
	cout << c;
	
	return 0;
}
*/


/*设计一个Point(点)类，数据信息包含x轴和y轴的坐标。设计一个Circle(圆)类，数据信息包含圆心和半径。 
  要求：（1）数据部分都采用整型； 
  （2）圆心作为Circle类中的子对象； 
  （3）每个类都包含带有参数的构造函数； 
  （4）重载运算符“<<”和“>>”，用于输入输出每个类对象的数据信息； 
  （5）主函数内验证各个功能。 
  主函数参考代码： 
  int main() 
  {  Point p(0,0); 
  cin>>p; 
  cout<<p; 
  Circle c(0,0,0); 
  cin>>c; 
  cout<<c; 
  return 0; 
  } 
  输入有两行，第一行两个整数，分别代表x轴和y轴的坐标值；第二行三个整数，分别代表x轴坐标值、y轴坐标值和半径值。
  输出三行，第一行是点的坐标，形式为（x，y）；第二行是圆心坐标，形式仍为（x，y）；第三行是半径值，最后有换行。注意：输出可以和输入交叉出现。
  【样例输入】
  1 2
  3 4 5
  【样例输出】
  (1,2)
  (3,4)
  5  
*/
#include <iostream>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	Point(int x,int y){}
	friend istream& operator>>(istream& in, Point& p)
	{
		in >> p.x >> p.y;
		return in;
	}
	friend ostream& operator<<(ostream& out, Point& p)
	{
		out<<"("<< p.x<<","<<p.y<<")";
		return out;
	}
};
class Circle
{
private:
	Point o;
	int r;
public:
	Circle(int x,int y,int r):o(x,y),r(r){}
	friend istream& operator>>(istream& in, Circle& c) 
	{
		in >> c.o >> c.r;
		return in;
	}
	friend ostream& operator<<(ostream& out, Circle& c)
	{
		out<<c.o<<endl;
		out<<c.r<<endl;
		return out;
	}
	
};
int main()
{
	Point p(0,0);
	cin >> p;
	Circle c(0,0,0);
	cin >> c;
	cout << p<<endl;
	cout << c;
	return 0;
}
