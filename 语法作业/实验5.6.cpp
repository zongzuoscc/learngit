/*
  设有n个小朋友围坐一圈玩丢手绢（用编号1，2，……n代表玩游戏的人），从第k（k大于等于1并且小于等于n）个小朋友开始报数，
  数到m的那个人出列。他的下一位继续从1开始报数，数到m的人出列，依此类推，直到所有人都出列为止。
  要求：n个小朋友围坐一圈用单向循环链表表示。
  【输入格式】
  三个整数n k m，其中n表示玩游戏的人数，k表示从第k个人开始玩，m表示报数的值
  【输出格式】
  n个整数，分别对应依次退出游戏的小朋友的编号
  【输入样例】
  13 2 3
  【输出样例】
  4 7 10 13 3 8 12 5 11 6 2 9 1
  程序可以参考如下框架：
 */
#include<iostream>
using namespace std;

// 定义节点结构体
struct Node {
	int data;         // 节点数据
	Node* next;       // 指向下一个节点的指针
};

// 定义链表结构体
struct List {
	Node* head;       // 指向链表头节点的指针
	int length;       // 链表的长度
};

// 创建链表，初始化链表中的节点
void createList(List &lst,int n){
	lst.length = 0;    // 链表长度初始化为0
	Node *q;
	for(int i = 1; i <= n; i++) {
		Node *p = new Node;     // 创建一个新节点
		p->next = NULL;         // 新节点的下一个指针初始化为 NULL
		if(i == 1) {
			lst.head = p;       // 如果是第一个节点，将头指针指向新节点
			p->data = i;
			q = lst.head;       // 临时指针 q 指向头指针
			lst.length++;       // 链表长度 +1
		} else {
			while(q->next) {
				q = q->next;    // 找到链表的尾节点
			}
			q->next = p;        // 将新节点添加到尾节点后
			p->data = i;        // 设置新节点的数据
			lst.length++;       // 链表长度 +1
		}
	}
	q->next->next = lst.head;  // 将尾节点的下一个指针指向头节点，形成循环链表
	return;
}

// 约瑟夫环游戏
void play(List& lst, int k, int m){	
	Node *q = lst.head;          // 指针 q 指向头节点
	Node *p = q;                 // 指针 p 指向当前节点
	int Node_count = lst.length; // 链表中节点的数量
	
	// 特殊情况处理：链表只有一个节点时，直接输出该节点
	if(Node_count == 1) {
		cout << q->data;
		return;
	}
	
	for(int i = 0; i < k-1; i++) {
		q = q->next;             // 将指针 q 向后遍历 k-1 次
	}
	
	while(Node_count > 2) {
		int cnt = 1;
		// 循环遍历链表，直到找到第 m 个节点
		for(; cnt < m; cnt++) {
			q = q->next;
			while(p->next != q) {
				p = p->next;    // 将指针 p 指向当前节点的前一个节点
			}
		}	
		cout << q->data << " ";  // 输出第 m 个节点的数据
		p->next = q->next;        // 将前一个节点的 next 指针指向当前节点的下一个节点
		q = p->next;              // 将指针 q 指向下一个节点
		Node_count--;             // 链表长度减1
	}
	
	// 输出最后两个节点的数据
	for(int cnt = 1; cnt < m; cnt++) {
		q = q->next;
	}
	cout << q->data << " " << q->next->data;
}

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	List lst;
	createList(lst, n);   // 创建链表
	play(lst, k, m);      // 玩约瑟夫环游戏
	return 0;
}
