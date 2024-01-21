/*2.某公司对员工每月工资计算如下：每月工资=基础工资+变动工资，研发人员的变动工资为研发补贴( subsidy)，
  每月按照在研产品数(Number)*500发放研发补贴。销售人员的变动工资为销售提成(Sales_Commission)，销售提成按照销售额(Sales_Volume)的百分之三进行提成. 
  由它公有派生出2个类：DStaff(研发人员)、Salesman(销售人员)，派生类中增加的数据成员也为double型。  
  主函数中定义抽象类的指针，再定义DStaff(研发人员)、Salesman(销售人员)对象各一个，各对象的初始值均由键盘输入。
  应用C++的多态性，将各派生类对象的地址赋给基类指针，通过指针计算各对象的月工资并输出。   
  注： 设置输出格式可用如下语句 
  cout<<setiosflags(ios::fixed)<<setprecision(2); 
  输入描述 
  研发人员的姓名   基础工资  在研产品数量 
  销售人员的姓名   基础工资  销售额 
  输出描述 
  研发人员的姓名   基础工资  研发工资  总工资 
  销售人员的姓名   基础工资  销售额    总工资
  样例输入 Copy 
Zhanghao  5000   5
LiLin    3000     100000
  样例输出 Copy 
  Zhanghao的工资明细
  基础工资:5000.00,研发补贴:2500.00,总工资:7500.00
  LiLin的工资明细
  基础工资:3000.00,销售提成:3000.00,总工资:6000.00
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Employee
{
public:
	Employee(string na,double B_Salary):BasicSalary(B_Salary),Name(na){}
	virtual void calSalary()=0;
	virtual void print()=0;
	string getName() {return Name;}
protected:
	double BasicSalary,TotalSalary;
private:
	string Name;
};
class DStaff:public Employee//研发人员
{
private:
	int Number;//在研产品数
public:
	DStaff(string na,double B_Salary,int Number):Employee(na,B_Salary),Number(Number){}
	void calSalary()
	{
		TotalSalary=BasicSalary+Number*500;
	}
	void  print()
	{
		cout<<getName()<<"的工资明细"<<endl<<"基础工资:"<<setiosflags(ios::fixed)<<setprecision(2)<<BasicSalary<<",研发补贴:"<<Number*500<<",总工资:"<<TotalSalary<<endl;
	}
};
class Salesman:public Employee//销售人员
{
private:
	double Sales_Volume;
public:
	Salesman(string na,double B_Salary,int S_Volume):Employee(na,B_Salary),Sales_Volume(S_Volume){}
	void calSalary()
	{
		TotalSalary=BasicSalary+Sales_Volume*0.03;
	}
	void print()
	{
		cout<<getName()<<"的工资明细"<<endl<<"基础工资:"<<setiosflags(ios::fixed)<<setprecision(2)<<BasicSalary<<",销售提成:"<<Sales_Volume*0.03<<",总工资:"<<TotalSalary<<endl;
	}
};
int main()
{
	string name1,name2;
	double bs1,bs2;
	int num;//研发产品数
	double sv;
	cin>>name1>>bs1>>num;
	cin>>name2>>bs2>>sv;
	Employee *emp1=new DStaff(name1,bs1,num);
	Employee *emp2=new Salesman(name2,bs2,sv);
	emp1->calSalary();
	emp2->calSalary();
	emp1->print();
	emp2->print();
	return 0;
}








/*
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string na, double B_Salary) : BasicSalary(B_Salary), Name(na) {}
	virtual void calSalary() = 0;
	virtual void print() const = 0;
	string getName() const { return Name; }
protected:
	double BasicSalary, TotalSalary;
private:
	string Name;
};

class DStaff : public Employee 
{
public:
	DStaff(string na, double B_Salary, int Product_Number) : Employee(na, B_Salary), ProductNumber(Product_Number) {}
	void calSalary() override 
	{
		TotalSalary = BasicSalary + ProductNumber * 500;
	}
	void print() const override 
	{
		cout  << getName() <<"的工资明细"<<endl<< "基础工资: " << setiosflags(ios::fixed) << setprecision(2) << BasicSalary
		<< "  研发补贴: " << ProductNumber * 500 << "  总工资: " << TotalSalary << endl;
	}
	
private:
	int ProductNumber;
};

class Salesman : public Employee
{
public:
	Salesman(string na, double B_Salary, double Volume) : Employee(na, B_Salary), SalesVolume(Volume) {}
	void calSalary() override 
	{
		TotalSalary = BasicSalary + SalesVolume * 0.03;
	}
	void print() const override 
	{
		cout<< getName() <<"的基础工资"<<endl<< "基础工资: " << setiosflags(ios::fixed) << setprecision(2) << BasicSalary
		<< "  销售提成: " << setiosflags(ios::fixed) << setprecision(2) << SalesVolume * 0.03 << "  总工资: " << setiosflags(ios::fixed) << setprecision(2) << TotalSalary << endl;
	}
	
private:
	double SalesVolume;
};

int main() 
{
	string name1, name2;
	double basicSalary1, basicSalary2;
	int productNumber;
	double salesVolume;
	
	cin >> name1 >> basicSalary1 >> productNumber >> name2 >> basicSalary2 >> salesVolume;
	
	Employee* emp1 = new DStaff(name1, basicSalary1, productNumber);
	Employee* emp2 = new Salesman(name2, basicSalary2, salesVolume);
	
	emp1->calSalary();
	emp2->calSalary();
	
	emp1->print();
	emp2->print();
	
	delete emp1;
	delete emp2;
	
	return 0;
}
*/
