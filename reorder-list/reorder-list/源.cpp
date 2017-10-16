#include<stdio.h>

//本地测试可以通过，在leetcode上报堆栈溢出，数组越界的错
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode reorderList(ListNode *head) {
	if (!head) return NULL;
	ListNode *p = head;
	ListNode *q = head;
	int n = 0;//n是list的最大下标，list的长度为n+1
	while (p->next){
		n++;
		p = p->next;
	}
	p = head;
	for (int i = 0; i < (n + 1) / 2; i++){//p指向中间节点
		p = p->next;
	}
	//将节点p及其往后的节点反转
	ListNode *r = p->next;
	p->next = NULL;
	p = r->next;
	r->next = NULL;
	while (p){
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	//将节点p指向的链表和head指向的前半段链表合并
	q = head;
	while (r){
		p = r->next;
		r->next = q->next;
		q->next = r;
		r = p;
		q = q->next->next;
	}
	return *head;
}


void main(){
	ListNode ln1 = ListNode(1);
	ListNode ln2 = ListNode(2);
	ListNode ln3 = ListNode(3);
	//ListNode ln4 = ListNode(4);
	//ListNode ln5 = ListNode(5);
	//ListNode ln6 = ListNode(6);
	ln1.next = &ln2;
	ln2.next = &ln3;
	//ln3.next = &ln4;
	//ln4.next = &ln5;
	//ln5.next = &ln6;

	reorderList(&ln1);
}