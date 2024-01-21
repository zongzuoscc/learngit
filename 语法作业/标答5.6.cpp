#include <iostream>

#include <cmath>

using namespace std;

struct Node {
	
	int data;
	
	Node* next;
	
};

struct List {
	
	Node* head;
	
	int length;
	
};

void createList(List &lst,int n){
	
	lst.head = new Node;
	
	lst.head->data=1;
	
	lst.head->next=NULL;
	
	lst.length=1;
	
	Node* pcurr = lst.head;
	
	for (int i = 1; i < n; i++) {
		
		Node *pnext = new Node;
		
		pnext->data=i+1;
		
		pnext->next=NULL;
		
		pcurr->next=pnext;
		
		pcurr = pnext;
		
		lst.length++;
		
	}
	
	pcurr->next=lst.head;//循环链表
	
}

void play(List& lst,int k, int m){
	
	int i;
	
	for (i=1;i<k;i++)
		
		lst.head=lst.head->next;
	
	while(lst.length)
		
	{
		
		for (i = 1; i < m - 1; i++)
			
		{ lst.head = lst.head->next; }//head指向待删结点的前驱
		
		Node *p = lst.head->next;
		
		cout<<p->data<<' ';
		
		lst.head->next=p->next;
		
		delete p;
		
		lst.head = lst.head->next;//head指向被删结点的下一个结点
		
		lst.length--;
		
	}
	
}

int main()

{
	
	int n, k, m;
	
	cin>>n>>k>>m;
	
	List lst;
	
	createList(lst,n);
	
	play(lst,k,m); 
	
	return 0;
	
}

