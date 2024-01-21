#include <iostream>
using namespace std;
int main()
{
	int lines;
	cin>>lines;
	for (int line=0;line<lines;line++)	
	{
		int a=1;
		for (;a<line*2+1;a+=2)	
		{
			cout<<a;
		}
		for (;a>=1;a-=2)	
		{
			cout<<a;
		}
		cout<<endl;	
	}
	return 0;
}
