#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[3][3];
	int i, j, k, p, q, max, min;
	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			scanf("%d", &a[i][j]);               //输入数组
	}
	for (i=0; i<3; i++){
		for (j=0, max=0, p=0; j<3; j++){         //判断出该行元素的最大值
			if (a[i][j]>max){
				max=a[i][j];
				p=j;
			}
			else{
				max=max;
				p=p;
			}
		}
		for (k=0, min=a[i][p], q=i; k<3; k++){   //判断最大值在该列是否为最小值
			if (a[k][p]<min){
				min=a[k][p];
				q=k;
			}
			else{
				min=min;
				q=q;
			}
		}
		if (i==q){
			printf("%d is the saddle point!\n", a[i][p]);  //如果该最大值行号没有改变，输出鞍点
			break;
		}
	}
	if (i==3 && i!=q)
		printf("There is no saddle point!\n");             //输出没有鞍点
	system("pause");
	return 0;
}


