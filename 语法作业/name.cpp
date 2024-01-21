#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int Max_a=10000;
bool checknum(char x) {return x>='0'&&x<='9';}
int main()
{
	char s[Max_a];
	int k,i=-1,t=0,a[Max_a];
	cin.getline(s,Max_a);
	while (s[++i]!='\0')
	{
		if (checknum(s[i])) {
			k=s[i]-'0';
			while (checknum(s[++i])) k=k*10+(s[i]-'0');
			a[++t]=k;
		}
	}
	cout<<t<<endl;
	for (int i=1;i<=t;i++) cout<<a[i]<<endl;
}

