// 337. House Robber III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<algorithm>
#include<map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归的写法，可能会栈溢出且时间长
int rob(TreeNode* root) {
	if (!root) return 0;

	int value = root->val;

	if (root->left)value +=rob(root->left->left)+rob(root->left->right);
	if (root->right)value +=rob(root->right->left)+rob(root->right->right);

	return max(value, rob(root->left) + rob(root->right));
}

//用一个map把算过的存起来
map<TreeNode *, int> mem;
int rob_m(TreeNode* root){
	if (!root)return 0;
	if (mem[root]!=0)return mem[root];
	int value = root->val;
	if (root->left)value += rob_m(root->left->left) + rob_m(root->left->right);
	if (root->right)value += rob_m(root->right->left) + rob_m(root->right->right);
	int maxv = max(value, rob_m(root->left) + rob_m(root->right));
	mem[root] = maxv;
	return maxv;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

