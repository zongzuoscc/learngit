/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = 0; j < n-i-1; j++) 
		{
			if (arr[j] > arr[j+1]) 
			{
				// 交换相邻元素
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}*/
#include <iostream>
using namespace std;
class Solution 
{
public:
	int Fibonacci(int n) 
	{
		int a = 0, b = 1;
		while (n -- ) 
		{
			int c = a + b;
			a = b, b = c;
		}
		return a;
	}
};
int main()
{
	Solution a;
	int n;
	cin>>n;
	cout<<a.Fibonacci(n);
	return 0;
}
