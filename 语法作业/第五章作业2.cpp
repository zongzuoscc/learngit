#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	//学生的姓名 
	string name[5];
	//学生的各科分数、学生的总分数、所有学生中最高的分数 
	float score[5][4]={0},total_score[5],max_score=0;
	//总分数最高的学生的位置 
	int temp;
	for(int i=0;i<5;i++)
	{
		cin>>name[i];
		for(int j=0;j<4;j++)
		{
			cin>>score[i][j];
			total_score[i]+=score[i][j];
		}
		cout<<name[i]<<"的总成绩为："<<fixed << setprecision(2) <<total_score[i]<<"，"<<"平均成绩为："<<fixed << setprecision(2) <<total_score[i]/4<<endl;
		if(total_score[i]>max_score)
		{
			temp=i;
			max_score=total_score[i]; 
		}
	}
	cout<<name[temp]<<"的平均分最高"<<endl; 
	return 0;
}
