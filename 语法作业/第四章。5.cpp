/*实验4-4图像旋转
  
  【问题描述】
  旋转是图像处理的基本操作，在这个问题中，你需要将一个图像逆时针旋转90度。
  计算机中的图像表示可以用一个矩阵来表示，为了旋转一个图像，只需要将对应的矩阵旋转即可。
  【输入格式】
  输入的第一行包含两个整数n, m，分别表示图像矩阵的行数和列数。
  接下来n行每行包含m个整数，表示输入的图像。
  【输出格式】
  输出m行，每行包含n个整数，表示原始矩阵逆时针旋转90度后的矩阵。每行后空格结束。*/
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int b[m][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			b[j][i]=a[i][m-j-1];
		}
	}
	for(i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
