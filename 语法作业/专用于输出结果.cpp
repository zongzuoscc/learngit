#include <iostream>
using namespace std;
bool isPrime(int n) 
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) 
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	char str[256];
	cin.getline(str, 256);
	int current_num = 0;
	bool decimal_flag = false;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			current_num = current_num * 10 + (str[i] - '0');
		} 
	/*	else if (str[i] == '.') 
		{
			if (!decimal_flag)
			{
				if (isPrime(current_num))
				{
					cout << current_num << " ";
				}
				current_num = 0;
			}
			decimal_flag = true;
	  } */
		else
		{
			if (!decimal_flag) 
			{
				if (isPrime(current_num))
				{
					cout << current_num << " ";
				}
				current_num = 0;
			}
			decimal_flag = false;
		}
	}
	if (!decimal_flag)
	{
		if (isPrime(current_num))
		{
			cout << current_num << " ";
		}
	}
	return 0;
}

