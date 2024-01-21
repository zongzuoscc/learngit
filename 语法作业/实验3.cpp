#include <iostream>

#include <cmath>

#define pi 3.1415926

using namespace std;

int main()

{
	
	double r,a,s,h;            //  a是角度
	
	cin>>r>>a;
	
	h=a*(pi/180);
	
	s=(a/360.0)*pi*r*r-(1/2.0)*r*r*sin(h);
	
	cout<<s<<endl;
	
	return 0;
	
}
