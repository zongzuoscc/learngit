/*小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。
  小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子。
  为方便起见，用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。如下图中，第3串是小红想做的珠串；那么第1串可以买，
  因为包含了她全部想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。
  【输入形式】每次输入包含两个字符串，分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过500个珠子。
  【输出形式】如果可以买，则在一行中输出“Yes”以及有多少颗多余的珠子，其间以1个空格分隔；
  如果不可以买，则在一行中输出“No”以及缺少多少颗珠子，其间以1个空格分隔；。
  【输入样例1】
  ppRYYGrrYBR2258
  YrR8RrY
  【输出样例1】
  Yes 8
  【输入样例2】
  ppRYYGrrYB225
  YrR8RrY
  【输出样例2】
  No 2*/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char seller[500];
	char buyer[500];
	cin.getline(seller,500);
	cin.getline(buyer,500);
	// 统计卖家的珠串中各个颜色的个数
	int counts[256] = {0}; // 用数组 counts 统计珠串中各个字符的个数，数组大小为 256，表示 ASCII 码的范围
	for (int i = 0; i < (int)strlen(seller); i++)
	{ // 遍历卖家的珠串
		counts[(int)seller[i]]++; // 增加对应字符的计数
	}
	
	// 统计买家的珠串中各个颜色的个数以及总数
	int required[200] = {0}; // 用数组 required 统计买家需要的珠串中各个字符的个数
	int requiredCount = 0; // 买家需要的珠串中字符的总数
	for (int i = 0; i < (int)strlen(buyer); i++) 
	{ // 遍历买家的珠串
		if (counts[(int)buyer[i]] > 0)
		{ // 如果卖家的珠串中还有对应的字符
			counts[(int)buyer[i]]--; // 卖家的计数减一，表示卖出一颗珠子
		} 
		else 
		{
			required[(int)buyer[i]]++; // 否则，增加买家需要的珠串中对应字符的计数
			requiredCount++; // 买家需要的珠串中字符的总数加一
		}
	}
	
	// 判断是否可以买，并输出
	if (requiredCount == 0) 
	{ // 如果买家需要的珠串中字符的总数为 0，表示可以买
		int extra = (int)strlen(seller) - (int)strlen(buyer); // 计算卖家的珠串长度与买家的珠串长度差值作为额外的珠子数量
		cout << "Yes " << extra << endl; // 输出 "Yes" 和额外的珠子数量
	}
	else 
	{ // 否则，买家需要的珠串中有字符没有对应的卖家珠串
		cout << "No " << requiredCount << endl; // 输出 "No" 和买家需要的珠串中字符的总数
	}
	
	return 0;
}
