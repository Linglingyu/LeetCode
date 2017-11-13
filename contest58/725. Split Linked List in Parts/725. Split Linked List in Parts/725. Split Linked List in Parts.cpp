// 725. Split Linked List in Parts.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
	int num = 0;
	ListNode *p = root;
	while (p){
		num++;
		p = p->next;
	}
	int ans = num / k;
	int rem = num % k;
	vector<ListNode*> res;
	ListNode *temp = root;
	ListNode *back = root;

	if (ans == 0){
		for (int i = 0; i < k; i++){
			ListNode *newhead = temp;
			back = temp;
			if (temp){
				temp = temp->next;
				back->next = NULL;
				res.push_back(newhead);
			}
			else{
				res.push_back(temp);
			}
		}
		return res;
	}


	for (int i = 0; i < k; i++){
		ListNode *newhead = temp;
		if (rem > 0){
			for (int j = 0; j < ans; j++){
				temp = temp->next;
			}
			back = temp;
			temp = temp->next;
			back->next = NULL;
		}
		else{
			for (int j = 0; j < ans-1; j++){
				temp = temp->next;
			}
			back = temp;
			temp = temp->next;
			back->next = NULL;
		}
		res.push_back(newhead);
		rem--;
	}
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* root = new ListNode(1);
	ListNode* temp = root;
	for (int i = 2; i < 4; i++){
		ListNode *newnode = new ListNode(i);
		temp->next = newnode;
		temp = temp->next;
	}
	vector<ListNode*> res = splitListToParts(root, 5);

	return 0;
}

