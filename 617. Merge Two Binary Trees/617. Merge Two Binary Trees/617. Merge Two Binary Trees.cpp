// 617. Merge Two Binary Trees.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stack>
//#include<map>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归法
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (!t1)return t2;
	if (!t2)return t1;
	t1->val += t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
}

//非递归法
TreeNode* mergeTreeNoRec(TreeNode* t1, TreeNode* t2){
	if (!t1)return t2;
	stack<vector<TreeNode*>> btstk;
	btstk.push({ t1, t2 });
	while (!btstk.empty()){
		vector<TreeNode*> temp = btstk.top();
		btstk.pop();
		if ((!temp[0]) || (!temp[1]))continue;
		temp[0]->val += temp[1]->val;
		if (!temp[0]->left){
			temp[0]->left = temp[1]->left;
		}
		else{
			btstk.push({ temp[0]->left, temp[1]->left });
		}
		if (!temp[0]->right){
			temp[0]->right = temp[1]->right;
		}
		else{
			btstk.push({ temp[0]->right, temp[1]->right });
		}
	}
	return t1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

