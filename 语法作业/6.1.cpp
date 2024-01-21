#include <iostream>
using namespace std;
#include <string>
int  main()
{
	int count =0;
	int t = 0;
	char s[100];
	char p[100];
	cin.getline(s,100);
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p[t] = s[i];
			t++;
		}
		else
		{
			p[t] = 'p';
			t++; 
		}
		i++;
	}
	p[t] = 'p';
	p[t+1] = '\0';
	int j = 0;
	while(p[j]!='\0')
	{
		if(p[j]>='0'&&p[j]<='9'&&p[j+1] == 'p')
		{
			count++;
		}
		j++;
	}
	j = 0;
	cout<<count<<endl;
	while(p[j]!='\0')
	{
		if(p[j]>'0'&&p[j]<='9')
			cout<<p[j];
		if(p[j]>='0'&&p[j]<='9'&&p[j+1] == 'p')
			cout<<endl;
		j++;
	}
	return 0;
}
