/*【问题描述】要求定义一个基类Person，它有3个私有数据成员：姓名name(char *类型)、性别 sex(char类型)、年龄age(int类型)；一个构造函数用于对数据成员初始化；有一个成员函数show()用于输出数据成员的信息。
  创建Person类的公有派生类Employee，增加两个私有数据成员：基本工资 basicSalary（int类型）和请假天数leaveDays（int型）；为它定义初始化成员信息的构造函数，和显示数据成员信息的成员函数show()。
  【输入形式】共5个数据，分别代表姓名、性别、年龄、基本工资、请假天数。
  【输出形式】如示例数据所示，共5行，分别代表姓名、年龄、性别、基本工资、请假天数
  【样例输入】zhangsan m 30 4000 2
  【样例输出】
  name:zhangsan
  age:30
  sex:m
  basicSalary:4000
  leavedays:2*/
#include <iostream>
#include <cstring>
using namespace std;
class Person
{
private:
	char *name;
	char sex;
	int age;
public:
	Person(char *n,char s,int a)
	{
		name=n;
		sex=s;
		age=a;
	}
	void show()
	{
		cout<<"name:"<<name<<endl;
		cout<<"age:"<<age<<endl;
		cout<<"sex:"<<sex<<endl;
	}
	~Person() 
	{
		delete[] name;
	}
	
};
class Employee:public Person
{
private:
	int basicSalary;
	int leaveDays;
public:
	Employee(char *n,char s,int a,int b,int l)
	:Person(n,s,a)
	{
		basicSalary=b;
		leaveDays=l;
	}
	void show()
	{
		Person::show();
		cout<<"basicSalary:"<<basicSalary<<endl;
		cout<<"leavedays:"<<leaveDays<<endl;
	}
};
int main()
{
	char name[20];
	char sex;
	int age, basicSalary, leaveDays;
	cin >> name >> sex >> age >> basicSalary >> leaveDays;
	Employee employee(name, sex, age, basicSalary, leaveDays);
	employee.show();
	return 0;
}
