/*设计一个学生类（CStudent），其私有数据成员：注册号、姓名、数学、外语、计算机课程的成绩。公有成员函数是：
  求三门课总成绩的函数 Sum；求三门课平均成绩的函数 Average；显示学生数据信息的函数 Display；设置学生数据信息的函数 SetData。
  1．可按如下样式设计 CStudent类的各数据成员以及成员函数
  class CStudent { //学生类 CStudent
  unsigned long reg_num; //数据成员：注册号
  char name[30]; //数据成员：姓名
  float math, eng, comp; //数据成员：数学、英语、计算机成绩
  public: //公有成员函数
  float Sum(); //求三门课总成绩的函数 Sum
  float Average(); //求三门课平均成绩的函数 Average
  Display(); //显示学生数据信息的函数 Display
  SetData (unsigned long r, char* n, float m, float e, float c) ;
  //设置学生数据信息的函数 SetData
  };
  在主函数，通过使用“CStudent stu[150];”的语句，来说明一个CStudent类对象的数组stu，而后通过各对象stu[i]来处理并求取每一学生的总成绩、平均成绩等。
  （1）输入本次欲处理的学生人数 TOTAL（小于等于 150 的正整数）；
  （2）输入全班 TOTAL 个学生的有关信息，依次放入对象数组的各元素 stu[i]中（通过使用“stu[i].SetData(...);”形式的语句来实现）；
  （3）对全班TOTAL个学生，依次通过对象stu[i]来求出其总成绩、平均成绩等（其中要使用形如“stu[i].Sum()”以及“stu[i].Average()”式样的对成员函数进行调用的语句），
  并同时求出全班学生总成绩最高者处于 stu 数组的下标位置idx_max，而后通过使用“stu[idx_max].Display();”来输出该学生有关的全部数据信息。
  3．程序执行后的输出界面样式可设计为：
  TOTAL=3
  CStudent 1 : 100001 ma 78 86 90（注意空格）
  CStudent 2 : 100002 li 85 91 88
  CStudent 3 : 100003 hu 82 89 88
  CStudent1.Sum=254,CStudent1.average=84.6667
  CStudent2.Sum=264,CStudent2.average=88
  CStudent3.Sum=259,CStudent3.average=86.3333
  class_Sum_max=264
  The infomation of the CStudent with class_Sum_max : 100002 li 85 91 88
  【样例输入】
3
100001 ma 78 86 90
100002 li 85 91 88
100003 hu 82 89 88
  【样例输出】
  TOTAL=3
  CStudent 1 : 100001 ma 78 86 90 
  CStudent 2 : 100002 li 85 91 88
  CStudent 3 : 100003 hu 82 89 88
  CStudent1.Sum=254,CStudent1.average=84.6667
  CStudent2.Sum=264,CStudent2.average=88
  CStudent3.Sum=259,CStudent3.average=86.3333
  class_Sum_max=264
  The infomation of the CStudent with class_Sum_max : 100002 li 85 91 88*/
#include <iostream>
#include <cstring>
using namespace std;
class CStudent 
{ //学生类 CStudent
	unsigned long reg_num; //数据成员：注册号
	char name[30]; //数据成员：姓名
	float math, eng, comp; //数据成员：数学、英语、计算机成绩
	public: //公有成员函数
	float Sum(); //求三门课总成绩的函数 Sum
	float Average(); //求三门课平均成绩的函数 Average
	void Display()
	{
		cout << "CStudent " << reg_num << " " << name << " " << math << " " << eng << " " << comp << endl;
	}
//显示学生数据信息的函数 Display
	void SetData (unsigned long r, char* n, float m, float e, float c)
	{
		reg_num = r;
		strcpy(name, n);
		math = m;
		eng = e;
		comp = c;
	}	
};

float CStudent::Sum()
{
	return math+eng+comp;
}
float CStudent::Average()
{	
	return (math+eng+comp)/3;	
}
int main()
{
	int TOTAL;	
	cin>>TOTAL;
	CStudent stu[150];
	unsigned long reg_num;
	char name[30];
	float math, eng, comp;
	int i;
	for (i = 0; i < TOTAL; i++) 	
	{	
		cin >> reg_num >> name >> math >> eng >> comp;	
		stu[i].SetData(reg_num, name, math, eng, comp);
	}
	int idx_max = 0;
	for (i = 1; i < TOTAL; i++)
	{	
		if (stu[i].Sum() > stu[idx_max].Sum())
		{
			idx_max = i;
		}
		
    }
	cout << "TOTAL=" << TOTAL << endl;
	for (i = 0; i < TOTAL; i++) 
	{
		cout << "CStudent " << i + 1 << " : ";
		stu[i].Display();
	}
	for(i=0;i<TOTAL;i++)
	{	
		cout << "CStudent" << i + 1 << ".Sum=" << stu[i].Sum() << ",CStudent" << i + 1 << ".average=" << stu[i].Average() << endl;
	}
	cout << "class_Sum_max=" << stu[idx_max].Sum() << endl;
	cout << "The infomation of the CStudent with class_Sum_max : ";
	stu[idx_max].Display();
	return 0;
}
