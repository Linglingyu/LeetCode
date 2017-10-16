#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {

	if (head == nullptr || head->next == nullptr) 
		return head;

	//在插入时，有可能需要在链表头插入，为了方便，新建立个链表
	ListNode sortedList(0);
	ListNode *cur = head;

	while (cur){
		//因为cur的指向可能会改变，所以要预先存下cur的next，以备在下次循环时使用
		ListNode *next = cur->next;

		//node代表排序数组的当前节点
		//从前向后遍历排序数组的每一个节点，和当前未排序数组中的节点做比较            
		ListNode* node = &sortedList;
		while (node->next != nullptr && node->next->val<cur->val) //因为第一个元素是0，所以从next开始
		{
			node = node->next;
		}//node指向sortedList中最后一个小于cur的节点

		cur->next = node->next;
		node->next = cur;//把cur所指的节点插入到node所指的节点的下一个
		cur = next;
	}

	return sortedList.next;
}

ListNode *sortList(ListNode *head) {
	ListNode sorted(0);

	ListNode *cur = head;
	ListNode *nextcur;
	while (cur){
		nextcur = cur->next;
		ListNode *pos = &sorted;
		while (pos->next != NULL&&pos->next->val<cur->val){
			pos = pos->next;
		}
		cur->next = pos->next;
		pos->next = cur;
		cur = nextcur;
	}
	return sorted.next;
}

void main(){
	ListNode newNode1(1);
	ListNode newNode2(6);
	ListNode newNode3(3);
	ListNode newNode4(9);
	ListNode newNode5(2);
	newNode1.next = &newNode2;
	newNode2.next = &newNode3;
	newNode3.next = &newNode4;
	newNode4.next = &newNode5;
	newNode5.next = NULL;

	ListNode *afterSort = sortList(&newNode1);
};