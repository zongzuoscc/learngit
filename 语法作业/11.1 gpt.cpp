#include <iostream>
using namespace std;
class BASE 
{
	char a;
public:
	BASE (char n=0):a(n){cout<<a;}
};
class DERIVED:public BASE 
{
	BASE b;
	char c;
public:
	DERIVED(char n):c(n),b(n+2),BASE(n+1){cout<<c;}
};
int main()
{
	DERIVED obj("X");
}
