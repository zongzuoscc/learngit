/*实验4-3
  【问题描述】
  利用cin.getline()函数从键盘录入一句英文，其中每个单词之间用一个空格隔开，最后用'.'结束。统计该句话中单词的个数，并依次输出每个单词。
  输出个数后换行，输出每个单词后也换行。注意：在本平台下，cin.getline()函数的使用方式如下：
  char s[50]; 
  cin.getline(s,50); //最多存储49个字符
  【输入形式】
  输入一句英文，其中每个单词之间用一个空格隔开，最后一个单词后面用英文的'.'作为结束；
  【输出形式】
  输出每个单词后换行，最后一行输出单词的数量。*/
#include <iostream>
using namespace std;
int main()
{
	char s[50];
	cin.getline(s,50,'.');
	int count=0;
	for (int i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		{
			cout<<endl;
			count++;
		}
		else
		{
			cout<<s[i];
		}
	}
	count++;
	cout<<endl<<count<<endl;
}
/*#include <iostream>
  using namespace std;
  
  int main() {
  char s[50];
  int wordCount = 0;
  
  cout << "Please enter an English sentence: ";
  cin.getline(s, 50, '.'); // 以.为结束符
  
  for (int i = 0; s[i] != '\0'; i++) {
  if (s[i] == ' ') { // 遇到空格就输出一个单词
  cout << endl; // 换行
  wordCount++; // 单词数量加1
  } else {
  cout << s[i]; // 输出当前字符
  }
  }
  
  wordCount++; // 最后一个单词后面没有空格，需要额外加1
  
  cout << endl << "Total number of words: " << wordCount << endl;
  
  return 0;
  }*/
