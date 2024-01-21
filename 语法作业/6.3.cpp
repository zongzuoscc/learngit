#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[100];
	char *p_str, *p_new_str;
	char new_str[200];
	int max_index = 0;
	
	cin.getline(str, 100);  // 使用 cin.getline 函数输入字符串
	
	p_str = str;
	p_new_str = new_str;
	
	while (*p_str)
	{
		// 找到最大元素的位置
		if (*p_str > str[max_index])
		{
			max_index = p_str - str;
		}
		
		// 将字符复制到新字符串中
		*p_new_str++ = *p_str++;
		
		// 在最大元素后面插入 "ab"，并只插入一次
		if (p_str - str == max_index + 1)
		{
			*p_new_str++ = 'a';
			*p_new_str++ = 'b';
		}
	}
	
	*p_new_str = '\0'; // 在新字符串的末尾加上 null 字符，成为一个完整的字符串
	
	cout << new_str << endl;
	
	return 0;
}
