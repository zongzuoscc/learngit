/*设有两个整数集合A和B，请输出A∩B的元素，其中集合A、B用单向链表表示。
【输入格式】
第一行输入一个数字n，表示集合A中数字的数量
第二行输入n个数字，以空格隔开。
第三行输入一个数字m，表示集合B中数字的数量
第四行输入m个数字，以空格隔开。
【输出格式】
若干个整数，即A∩B的元素，每个整数后面有一个空格
【输入样例】
7
3 9 11 4 2 7 1
5
1 3 5 7 9
【输出样例】
1 7 9 3
程序请按照如下要求设计：
*/
#include <iostream>
using namespace std;
struct Node
{    int data;
	Node *next;
};
struct Set
{    int num;
	Node *head;
};
void init(Set *x)
{
	x->head=NULL;	
	x->num=0;
}
void createSet(Set *x)
{
	int n;
	int num1;
	cin >> n;         // 输入节点的数量
	for(int i = 0; i < n; i++)
	{
		cin >> num1;                // 输入节点的数据
		Node *p = new Node;         // 创建一个新节点
		p->data = num1;             // 将节点的数据设置为输入值
		p->next = NULL;             // 将节点的下一个指针设为 NULL
		if(x->head == NULL)
		{
			x->head = p;            // 如果集合的头指针为空，则将头指针指向当前节点
		} 
		else 
		{
			p->next = x->head;      // 否则，将当前节点的下一个指针指向头节点
			x->head = p;            // 将头指针指向当前节点
		}
		x->num++;                   // 集合中节点数量 +1
	}
//生成链表时一定采用往前插入的方法，即每个新产生的结点插入到链表的第一个结点的前面。
} 
void intersect(Set *x,Set *y)
{
	Node *p = x->head;              // 指向集合 x 的头节点
	Node *q = y->head;              // 指向集合 y 的头节点
	while(p) {
		while(q) {
			if(p->data == q->data) {
				cout << p->data << " ";    // 输出相交节点的数据
			}
			q = q->next;                   // 移动到下一个节点
		}
		q = y->head;                       // 重置集合 y 的指针
		p = p->next;                       // 移动到下一个节点
	}
    //外层循环对集合x进行遍历，内层循环对集合y进行多次遍历，遇到交集的元素，输出的是集合x中的值。
}
int main()
{
	Set a,b;	
	init(&a);
	init(&b);
	createSet(&a);
	createSet(&b);
	intersect(&a,&b);
	return 0;
}
