/*【问题描述】从键盘输入一个字符串，并在串中的第一次出现的最大元素后边插入字符串”ab”。
  
  【输入形式】任意输入一个字符串
  
  【输出形式】在串中的最大元素后边插入字符串”ab”
  
  【样例输入】123csCUMT
  
  【样例输出】123csabCUMT
  
  【样例说明】为了保证输入的字符串有空格，请使用cin.getline(char* , int); 本系统不支持使用gets。只插入一次ab。*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	char str[100];
	cin.getline(str,100);
	str[strlen(str)]='\0';
	int i,max=0;
	for(i=1;i<strlen(str);i++)
	{
		if(str[i]>str[max])
		{
			max=i;
		}
	}
	char str1[100];
	char str2[100];
	strncpy(str1,str,max+1);
	str1[max+1]='\0';
	strcpy(str2,str+max+1);
	strcat(str1,"ab");
	strcat(str1,str2);
	cout<<str1<<endl;
	return 0;
}
