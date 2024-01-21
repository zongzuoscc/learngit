/*【问题描述】根据下面部分代码，补充完成学生成绩类Score。在主函数中定义学生成绩对象数组。用Sum()计算每个学生的总成绩、
  用Show()显示每个学生的成绩。增加静态成员函数getAvg()，用于返回学生的总平均分。
 【输入形式】
  包含一组测试数据。第一行输入一个整数n（1<=n<=100）。
  接下来n行。每行先输入一个整数op：
  当op==1时，输入x, y, z。代表输入一位新同学i(i从1开始编号)的语文、数学、英语成绩，无需输出。
  当op==2时，输入i，输出第i同学的总成绩。数据保证这位同学的成绩已经录入。
  当op==3时，输入i，依次输出第i同学的语文数学英语成绩，成绩之间用空格隔开。
  当op==4时，输出当前已经录入学生的总平均分，结果保留两位小数。
  (1<=n<=100, 1<=id<=10, 1<=op<=3, 0<=x,y,z<=100,全部输入都为整型数)
  【输出形式】
  当op==2，3，4时，输出所求答案，每个答案占一行。
  【样例输入和输出】
  10
  1 90 85 90
  1 80 90 75
  2 1
  265（此行为输出内容）
  3 2
  80 90 75（此行为输出内容）
  4
  255.00（此行为输出内容）
  1 80 80 85
  1 50 60 65
  1 30 90 75
  3 5
  30 90 75（此行为输出内容）
  4
  225.00（此行为输出内容）
  注意：输入之间会有一些输出，但测试只看cout结果。  
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Score 
{	
private:	
	int Chinese, Math, English;
	static int TotalScore;
	static int TotalStudent;
public:
	Score() {}
	void setScore (int c, int m, int e) 
	{	
		Chinese=c;
		Math=m;
		English=e;
		TotalStudent++;
		TotalScore+=Chinese+Math+English;
	}
	int Sum() 
	{	
		int sum;
		sum=Chinese+Math+English;
		return sum;
	}
	void Show() 
	{	
		cout<<Chinese<<" "<<Math<<" "<<English<<endl;
	}
	double static getAve() 
	{	
		double ave;
		ave=(TotalScore*1.0)/TotalStudent;
		return ave;
	}
};
int Score::TotalScore = 0; 
int Score::TotalStudent=0;
int main() 
{	
	int n, op, i, c, m, e;	
	cin >> n;
	int id = 1;
	Score sco[11];
	while(n--) 
	{	
		cin >> op;	
		if(op == 1) 
		{
			cin >> c >> m >> e;	
			sco[id++].setScore(c,m,e);
		} 
		else if(op == 2) 
		{	
			cin >> i;	
			cout << sco[i].Sum() << endl;
		} 
		else if(op == 3)
		{	
			cin >> i;	
			sco[i].Show();
		} 
		else
		{	
			cout << fixed << setprecision(2) << Score::getAve() << endl;
		}
	}
	return 0;
}
