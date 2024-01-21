/*利用继承性与派生类来管理学生教师档案:由Person（人员）类出发（作为基类），派生出Student（学生）及Teacher（教师）类；
  而后又由Student（学生）类出发（作为基类），派生出GraduateStudent（研究生）类。可假定这几个类各自具有的数据成员为:
  为简化起见，每个类可只设立构造函数以及显示类对象数据的成员函数Print。而后编制简单的主函数，
  说明上述有关的类对象，并对其类成员函数进行简单使用（调用）。
  【输入格式】
  输入多行。每行输入一个对象的相关信息，依次为Person（姓名、年龄、性别）、
  Student（姓名、年龄、性别、学号、系别）、GraduateStudent（姓名、年龄、性别、学号、系别、导师）、
  Teacher信息（姓名、年龄、性别、职称、担任课程）。
  【输出格式】
  输出多行。输出各个对象的相关信息。
  【样例输入】    
sun 42 m
guo 22 f 1001 com
wu 25 m 1021 com wei
fang 38 m eng prof
  【样例输出】
  == per1.Display() => name,age,sex
  sun 42 m
  == stu1.Display() => name,age,sex,Reg_Number,department
  guo 22 f 1001 com
  == gStu1.Display() => name,age,sex,Reg_Number,department,advisor
  wu 25 m 1021 com wei
  == teach1.Display() => name,age,sex,post,course
  fang 38 m eng prof*/
#include <iostream>
#include <string>
using namespace std;
class Person//Person（人员）类: 姓名、性别、年龄；
{
public:
	string name;
	int age;
	char sex;
	Person(string n, int a, char s) : name(n), age(a) ,sex(s){}
	void display()
	{
	    cout << name << " " << age << " " << sex ;	
	}
};
class Student:public Person//Student（学生）类: 姓名、性别、年龄、学号、系别；
{
public:
	int RegNumber;
	string department;
	Student(string n,char s, int a, int RN, string dep) : Person(n, s, a), RegNumber(RN), department(dep) {}
	void display()
	{
		Person::display();
		cout<<" "<<RegNumber<<" "<<department;
	}
};
class Teacher:public Person//Teacher（教师）类: 姓名、性别、年龄、职称、担任课程；
{
public:
	string post;
	string course;
	Teacher(string n,char s,int a,string p,string c):Person(n,s,a),post(p),course(c){}
	void display()
	{
		Person::display();
		cout<<" "<<post<<" "<<course;
	}
};
class GraduateStudent:public Student//GraduateStudent（研究生）类: 姓名、性别、年龄、学号、系别、导师。
{
public:
	string advisor;
	GraduateStudent(string n,char s, int a, int RN, string dep,string ad) : Student(n, s, a,RN,dep), advisor(ad){}
	void display()
	{
		Student::display();
		cout<<" "<<advisor;
	}
};
int main()
{
	string name, department, advisor, post, course;
	int RegNumber;
	int age;
	char sex;
	
	// 输入Person信息
	cin >> name >> age >> sex;
	Person per1(name, age, sex);
	cout << "== per1.Display() => name,age,sex" << endl;
	per1.display();
	cout<<endl;
	
	// 输入Student信息
	cin >> name >> age >> sex >> RegNumber >> department;
	Student stu1(name, age, sex, RegNumber, department);
	cout << "== stu1.Display() => name,age,sex,Reg_Number,department" << endl;
	stu1.display();
	cout<<endl;
	
	// 输入GraduateStudent信息
	cin >> name >> age >> sex >> RegNumber >> department >> advisor;
	GraduateStudent gStu1(name, age, sex, RegNumber, department, advisor);
	cout << "== gStu1.Display() => name,age,sex,Reg_Number,department,advisor" << endl;
	gStu1.display();
	cout<<endl;
	
	// 输入Teacher信息
	cin >> name >> age >> sex >> post >> course;
	Teacher teach1(name, age, sex, post, course);
	cout << "== teach1.Display() => name,age,sex,post,course" << endl;
	teach1.display();
	cout<<endl;
	
	return 0;
}

