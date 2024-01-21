#include<iostream>
using namespace std;
void time(char*s);
int main()
{
	char s[100];
	cin.getline(s,100);
	time(s);
	return 0;
}
void time(char*s)
{
	int sum=0;
	int i=0,num[10]={0};
	while(s[i]!='\0')//'\0'为空字符 
	{
		if(s[i]>=48&&s[i]<=57)
		{
			sum++;
			switch(s[i])
			{
				case '0': num[0]++;break;
				case '1': num[1]++;break;
				case '2': num[2]++;break;
				case '3': num[3]++;break;
				case '4': num[4]++;break;
				case '5': num[5]++;break;
				case '6': num[6]++;break;
				case '7': num[7]++;break;
				case '8': num[8]++;break;
				case '9': num[9]++;break;
			}
		}
		i++;
	}
	cout<<"Number's amount is:"<<sum<<endl;
	cout<<"'0...9' amount is:";
	for(int j=0;j<10;j++)
		cout<<num[j]<<" ";
}
