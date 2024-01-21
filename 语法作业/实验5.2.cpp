/*在进行文章重复度检查时，经常需要统计一段英文中的单词数量，并找出长度最长的单词。
  设有如下定义：char str[500];
  编写程序，通过利用cin.getline(str,500);实现从键盘输入一小段英文（其中可以包含空格，但在同一行），
  利用函数统计该段英文中包含几个单词，输出统计出的单词数量、最长单词的长度以及长度最长的单词，空格隔开。
  注意：函数声明使用void split(char *str);如果有最长的单词不只一个，输出最先找到的那个。
  【输入形式】一小段英文，不要超过500个字符
  【输出形式】单词数量、最长单词的长度以及长度最长的单词，空格隔开。
  【输入样例】welcome to china university of mining and technology
  【输出样例】8 10 university*/
#include <iostream>
#include <cstring>
using namespace std;
void split(char *str);
int main()
{
	char str[500];
	cin.getline(str,500);
	split(str);
	return 0;
}
void split(char *str)
{
	strcat(str," ");
	int len=strlen(str);
	int num=0,n=0,pos,longest=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			num++;
			if(n>longest)
			{
				longest=n;
				pos=i-longest;
			}
			n=0;
		}
		else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			n++;
		}
	}
	cout<<num<<" "<<longest<<" ";
	for(int i=pos;i<pos+longest;i++)
	{
		cout<<str[i];
	}
}


/*
#include<iostream>
#include<string.h>
using namespace std;
void solveProblem(char str[]){//可以分为两个函数，但是需要遍历2次，所以这里遍历一次以缩短时间
	strcat(str," ");//在字符串后加一个空格，方便下列程序的操作
	int len=strlen(str);
	int num=0,n=0,pos,longest=0;
	for(int i=0;i<len;i++){
		if(str[i]==' ') {
			num++;
			if(n>longest){
				longest=n;
				pos=i-longest;//找出最大单词的位置
			}
			n=0;
		}
		else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
			n++;
		}
	}
	cout<<num<<" "<<longest<<" ";
	for(int i=pos;i<pos+longest;i++){
		cout<<str[i];
	}//最后输出最长字符串 
}
int main(){
	char str[500];
	cin.getline(str,500);
	solveProblem(str);
	return 0;
}
 */
