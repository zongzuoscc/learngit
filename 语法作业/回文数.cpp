#include <iostream>
using namespace std;

bool symm(long n);

int main()
{
	long n;
	cin >> n; // 输入搜索范围
	
	bool isFirst = true; // 用于控制输出格式
	for (long i = 1; i <= n; i++)
	{
		long m = 7 * i;
		long v = 3 * i * i;
		if (symm(i) && symm(m) && symm(v)) // 判断是否符合要求
		{
			if (isFirst)
			{
				cout << i;
				isFirst = false;
			}
			else
			{
				cout << " " << i;
			}
		}
	}
	cout << endl;
	return 0;
}

// 判断数字n是否为回文数的函数
bool symm(long n)
{
	long div = 1; // 用来计算数字的位数
	while (10 * div <= n)
	{
		div *= 10;
	}
	
	while (n > 0)
	{
		int high = n / div;
		int low = n % 10;
		if (high != low) // 如果对应数字不相等，则说明不是回文数，返回 false
		{
			return false;
		}
		n %= div; // 去掉最高位
		n /= 10; // 去掉最低位
		div /= 100; // 数字位数减少2位
	}
	
	return true;
}
