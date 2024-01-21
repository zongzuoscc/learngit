#include <iostream>
#include <cstdio>
#define pi 3.14
using namespace std;
int main()
{
	double r;
	scanf("%lf",&r);
	printf("%.3lf %.4lf\n",(4/3.0)*pi*r*r*r,9.1*0.01*(4/3.0)*pi*r*r*r);
	return 0;
 } 
