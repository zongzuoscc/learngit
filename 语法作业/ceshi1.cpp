#include <bits/stdc++.h>

#include<iomanip>

using namespace std;

int main()

{
	
	string Name[5];
	
	int score[5][4],TotalScore[5]={0},AverageScore[5],i,j,k;
	
	for (i=0;i<5;i++)
		
	{
		
		cin>>Name[i];
		
		for(j=0;j<4;j++)
			
		{
			
			cin>>score[i][j];
			
			cout<<endl;
			
		}
		
	}
	
	for(i=0;i<5;i++)
		
	{
		
		for(j=0;j<4;j++)
			
		{
			
			TotalScore[i]+=score[i][j];
			
		}
		
		AverageScore[i]=TotalScore[i]/4.0;
		
	}
	
	for(i=0,k=0;i<4;i++)
		
	{
		
		if(AverageScore[i+1]>AverageScore[i])
			
			k=i+1;
		
	}
	
	cout<<setiosflags(ios::left)<<setw(10)<<"Name"<<setw(9)<<"TotalScore"<<"AverageScore"<<endl;
	
	for(i=0;i<5;i++)
		
	{
		
		cout<<setiosflags(ios::left)<<setw(10)<<Name[i]<<setw(9)<<TotalScore[i]<<AverageScore[i]<<endl;
		
	}
	
	cout<<"Student with the highest AverageScore is "<<Name[k]<<","<<"AverageScore is "<<AverageScore[k]<<endl;
	
	return 0;
	
}
