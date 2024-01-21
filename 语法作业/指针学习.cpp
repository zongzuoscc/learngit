#include <iostream>
using namespace std;
int main() 
{
	char str[100];
	int a[100];
	int count = 0; // 计数器
	
	cin.getline(str, 100); // 读入字符串
	
	char* p = str;
	while (*p) // 遍历字符串
	{
		if (*p >= '0' && *p <= '9') // 找到数字
		{
			int n = 0;
			while (*p >= '0' && *p <= '9') // 组成整数
			{
				n = n * 10 + (*p - '0');
				p++;
			}
			a[count++] = n; // 存入数组并计数
		}
		else
		{
			p++;
		}
	}
	
	cout << count << endl; // 输出整数的个数
	for (int i = 0; i < count; i++) // 输出整数
	{
		cout << a[i] << endl;
	}
	
	return 0;
}
