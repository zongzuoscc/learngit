/*#include <iostream>
using namespace std;
class Point
{
private:
	int x,y;
public:
	Point(int xx,int yy)
	{
		x=xx;
		y=yy;
	}
	Point &setPoint(int x,int y)
	{
		this->x=x+8;
		(*this).y=y+8;
		return *this;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
  };
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
  }*/
//接下来我要设计一个寻找素数的函数,并输出
#include <iostream>
using namespace std;
void isprime(int n)
{
	for (int i=2;i<=n;i++)
	{
		if(n%i!=0)
		{
			cout<< n<<" ";
			break;
		}
	}
}
int main()
{
	int x;
	cin>>x;
	int n[x];
	int i;
	for(i=0;i<x;i++)
	{
		cin>>n[i];
	}
	for (i=0;i<x;i++)
	{
		isprime(n[i]);
	}
	return 0;
}
