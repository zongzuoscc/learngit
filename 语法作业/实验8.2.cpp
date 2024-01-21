/*编程序，对 k=1，2，3，…，14，15，按下式分别计算出 15 组（i，d，c）：
  整数 i=2k-1；实数 d=kk+k-9.8；字符 c=‘H’+k。并通过使用运算符“<<”
  将这15组数据保存到当前目录下自定义的text型磁盘文件ft.txt之中。*/
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;
int main()
{
	fstream fout("ft.txt",ios::out);
	fout<<"(";
	int k;
	for(k=1;k<=15;++k)
	{
		switch (k%3) 
		{
		case 1:
			fout<<2*k-1;
			break;
		case 2:
			fout<<1.0*k*k+k-9.8;
			break;
		case 0:
			fout<<(char)('H'+k);
			break;
		}
		if(k%3==1||k%3==2)
		{
			fout<<",";
		}
		if(k%3==0&&k!=15)
		{
			fout<<")\n(";
		}
	}
	fout<<")";
	return 0;
}
