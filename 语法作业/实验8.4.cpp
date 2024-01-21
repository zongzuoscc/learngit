#include <iostream>
#include <fstream>
using namespace std;
bool isShuixian(int num)
{
	int temp = num;
	int sum = 0;
	while (temp != 0) 
	{
		int digit = temp % 10;
		sum += digit * digit * digit;
		temp /= 10;
	}
	return sum == num;
}

int main() 
{
	ofstream outfile("shuixian.txt");
	
	for (int i = 100; i < 1000; ++i)
	{
		if (isShuixian(i)) 
		{
			outfile << i << endl;
		}
	}
	
	outfile.close();
	return 0;
}

