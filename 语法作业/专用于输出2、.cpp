/*#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A";
	}
};
class B:public A
{
private:
	A obj;
public:
	B()
	{
		cout<<"B";
	}
};
int main()
{
	B obj;
	return 0;
}
/*#include <iostream>
using namespace std;
int main()
{
	int i=1;
	switch(i)
	{
	case 1:i++;
	case 2:i--;
	case 3:++i;break;
	case 4:--i;
	default:i++;
		
	}
	cout<<i<<endl;
	return 0;
  }
#include <iostream>
using namespace std;
void f1(int &x,char *p);
int main()
{
    /*int a=3;
	int *p;
	p=&a;
	cout<<p<<endl;
	cout<<*p<<endl;
	cout<<&p<<endl;
	cout<<&a<<endl;
    return 0;
	int a[]={1,2,3,4,5};
	int *p=a;
	//cout<<&(a+1)<<endl;
	//cout<<&(p+1)<<endl;
	cout<<&p[2]<<endl;
    //cout<<++(p+1)<<endl;
	int a[3][4],(*p)[4];
	p=a+2;
    p=a[1];
	int m;
	char s[]="c++";
	f1(m,s);
	  f1(m,&s);
	cout<<sizeof(float);
	return 0;

}
 
#include <iostream>
using namespace std;
int main()
{
	int b[]={5,3,4,1,8,9,0,10};
	int i=0,j;
	for(j=0;j<8;j++)
		if(b[j]<b[i])
		{
			i=j;
	        cout<<i<<' '<<b[i]<<endl;
		}
	return 0;
  }
#include <iostream>
using namespace std;
void P(int *x,int &y)
{
	y=*x+y;
	*x=y%4;
	cout<<*x<<' '<<y<<endl;
}
int main()
{
	int x=4,y=5;
	P(&y,x);
	cout<<x<<' '<<y<<endl;
	return 0;
}
 */
#include <iostream>
using namespace std;
class A
{
public:
	A(int i){
		x=i;
	}
	void dispa()
	{
		cout<<x<<",";
	}
private:
	int x;
};
class B:public A
{
public:
	B(int i):A(i+10){
		x=i;
	}
	void dispb()
	{
		dispa();
		cout<<x<<endl;
	}
private:
	int x;
};
int main()
{
	B b(2);
	b.dispb();
	return 0;
}
