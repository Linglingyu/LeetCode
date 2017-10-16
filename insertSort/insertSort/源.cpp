#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode *i = head->next;
		for (i; i != NULL; i = i->next){
			int key = i->val;
			ListNode *j = head;
			while (j != i&&j->val<key){
				j = j->next;
			}
			j->next = i;
		}
	}
};

void WinMian(){
	ListNode newNode1(1);
	ListNode newNode2(6);
	ListNode newNode3(3);
	ListNode newNode4(9);
	ListNode newNode5(2);
	newNode1.next = &newNode2;
	newNode2.next = &newNode3;
	newNode3.next = &newNode4;
	newNode4.next = &newNode5;
};