#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Beeline
{
private:
	int x1, y1;
	int x2, y2;
	
public:
	Beeline(int x1 = 0, int y1 = 0, int x2 = 1, int y2 = 0) // 构造函数，定义形参默认值
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	
	double Length() // 计算线段长度
	{
		double length;
		length = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		return length;
	}
	
	void show() // 显示线段两个端点坐标
	{
		cout << "(" << x1 << "," << y1 << "),(" << x2 << "," << y2 << ")" << endl;
	}
};

class Triangle
{
private:
	Beeline line1;
	Beeline line2;
	Beeline line3;
	
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	: line1(x1, y1, x2, y2), line2(x2, y2, x3, y3), line3(x3, y3, x1, y1) // 对象成员初始化
	{
	}
	
	double Area() // 计算三角形面积，使用海伦公式
	{
		double a = line1.Length();
		double b = line2.Length();
		double c = line3.Length();
		double p = (a + b + c) / 2;
		double area = sqrt(p * (p - a) * (p - b) * (p - c));
		return area;
	}
	
	void Print() // 显示三条边端点坐标及面积
	{
		cout << "Three edges' points are listed as follows:" << endl;
		line1.show();
		cout << endl;
		line2.show();
		cout << endl;
		line3.show();
		cout << endl;
		cout << "The area of this triangle is:" << fixed << setprecision(2) << Area() << endl;
	}
};

int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	Triangle tri(x1, y1, x2, y2, x3, y3);
	tri.Print();
	
	return 0;
}
