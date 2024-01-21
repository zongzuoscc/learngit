/*对于整型数组a[10]和b[10]，编制程序完成下列任务:
  （1）由用户从键盘为两个数组输入值；
  （2）求出两个数组的最大值和最小值；
  （3）把数组a和b中的整数分别从小到大和从大到小排序；
  （4）把两个有序的数组a和b组成一个长度为20的有序数组c[20]，使数组c的顺序为从小到大。
  【输入形式】
  输入两行整数，每行10个，第一行是数组a里的数组，第二行是数组b里的数值；
  【输出形式】
  输出五行：
  第一行有两个整数，分别是数组a的最大值和最小值，两个整数之间用一个空格分隔；
  第二行有两个整数，分别是数组b的最大值和最小值，两个整数之间用一个空格分隔；
  第三行按照从小到大的顺序输出数组a里的数值，每个数字后面有一个空格，最后一个数字后面也有空格；
  第四行按照从大到小的顺序输出数组b里的数值，每个数字后面有一个空格，最后一个数字后面也有空格；
  第五行按照从小到大的顺序输出合并后数组c里的数值，每个数字后面有一个空格，最后一个数字后面也有空格。*/
#include <iostream>
using namespace std;
int main()
{
	int a[10],b[10],c[20];
	int i;
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<10;i++)
	{
		cin>>b[i];
	}
	int amax=a[0],amin=a[0],bmax=b[0],bmin=b[0];
	for(i=1;i<10;i++)
	{
		if(a[i]>amax)
		{
			amax=a[i];
		}
		if(a[i]<amin)
		{
			amin=a[i];
		}
		if(b[i]>bmax)
		{
			bmax=b[i];
		}
		if(b[i]<bmin)
		{
			bmin=b[i];
		}
	}
	cout<<amax<<" "<<amin<<endl;
	cout<<bmax<<" "<<bmin<<endl;
	for (int i = 10 - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1]) 
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < 10; j++) 
		{
			if (b[j] > b[minIndex]) 
			{
				minIndex = j;
			}
		}
		int temp = b[minIndex];
		b[minIndex] = b[i];
		b[i] = temp;
	}
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<10;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<10;i++)
	{
		c[i]=a[i];
	}
	for(i=0;i<10;i++)
	{
		c[i+10]=b[i];
	}
	for (int i = 20-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (c[j] > c[j + 1]) 
			{
				int temp;
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
		}
	}
	for(i=0;i<20;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
	return 0;
}
