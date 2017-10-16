// BinaryTreeTraverse.cpp : 定义控制台应用程序的入口点。
//树的先序，中序，后序的递归和非递归方式遍历
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree();
	BinaryTree(int i){
		value = i;
	}
};

//先序 递归
void preOrderTraversRecurse(BinaryTree *root){
	cout << root->value;
	if (root->left)
		preOrderTraversRecurse(root->left);
	if (root->right)
		preOrderTraversRecurse(root->right);
}

//先序 非递归
void preOrderTravers(BinaryTree *root){
	if (!root){
		return ;
	}
	stack<BinaryTree *> ts;
	ts.push(root);
	while (!ts.empty()){
		BinaryTree *temp = ts.top();
		cout << temp->value;
		ts.pop();
		if (temp->right)
			ts.push(temp->right);
		if (temp->left)
		ts.push(temp->left);
	}
}

//中序 递归
void midOrderTraversRecurse(BinaryTree *root){
	if (root->left)
		preOrderTraversRecurse(root->left);
	cout << root->value;
	if (root->right)
		preOrderTraversRecurse(root->right);
}

//中序 非递归
void midOrderTravers(BinaryTree *root){
	stack<BinaryTree *> ts;
	BinaryTree *temp;
	temp = root;

	while (!ts.empty()||temp){
		while (temp){
			ts.push(temp);
			temp = temp->left;
		}
		temp = ts.top();
		cout << temp->value;
		ts.pop();
		temp = temp->right;
	}
}

vector<int> inorderTraversal(BinaryTree* root) {
	vector<int> res;
	stack<BinaryTree*> nodes;
	BinaryTree *temp = root;
	//nodes.push(temp);
	while (!nodes.empty()||temp){
		while (temp){
			nodes.push(temp);
			temp = temp->left;
		}
		BinaryTree *temp1 = nodes.top();
		res.push_back(temp1->value);
		cout << temp1->value << endl;
		nodes.pop();
		temp = temp1->right;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree *bt0 = new BinaryTree(3);
	BinaryTree *bt1 = new BinaryTree(5);
	BinaryTree *bt2 = new BinaryTree(2);
	BinaryTree *bt3 = new BinaryTree(7);
	BinaryTree *bt4 = new BinaryTree(10);
	bt0->left = bt1;
	bt0->right = bt2;
	bt1->left = bt3;
	bt1->right = bt4;
	bt0->right = bt2;
	bt3->left = nullptr;
	bt3->right = nullptr;
	bt4->left = nullptr;
	bt4->right = nullptr;
	bt2->left = nullptr;
	bt2->right = nullptr;
	//preOrderTraversRecurse(bt0);
	//preOrderTravers(bt0);
	vector<int> result = inorderTraversal(bt0);
	//midOrderTravers(bt0);
	system("pause");
	return 0;
}

