/*一个整数集合中含有n个数字，每个数字都在0~n之间。假设0~n的n+1个数字中有且仅有一个数字不在该集合中，请找出这个数字。
  【输入格式】
  第一行输入一个数字s，表示集合中数字的数量
  第二行输入s个数字，以空格隔开。
  1 <= s <= 1000
  【输出格式】
  输出缺失的数字
  【输入样例】
  4
  0 1 2 4
【输出样例】
  3                                                                                                                      */
#include <iostream>
using namespace std;
void sort(int a[], int n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - 1 - i; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int s;
	cin>>s;
	int num[s];
	for (int i=0;i<s;i++)
	{
		cin>>num[i];
	}
	sort(num,s);
	int missingNum = num[0];
	for (int i = 0; i < s; i++) {
		if (num[i] != missingNum) {
			break;
		}
		missingNum++;
	}
	
	cout << missingNum << endl;
	return 0;
}
