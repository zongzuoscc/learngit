#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poem.txt","r",stdin);
	char c=getchar();
	while (1)
	{
		if (c==EOF)
			break;
		cout<<c;
		c=getchar();
	}
	return 0;
}
