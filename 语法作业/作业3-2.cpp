#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	for(a='X';a<='Z';a++)
	{
		for(b='X';b<='Z';b++)
		{
			if(a!=b)
			{
				for(c='X';c<='Z';c++)
				{
					if(a!=c&&b!=c)
					{
						if(a!='X'&&c!='X'&&c!='Z')
						{
							printf("A--%c B--%c C--%c",a,b,c);
						}
					}
				}
			}
		}
	}
	return 0;
 } 
