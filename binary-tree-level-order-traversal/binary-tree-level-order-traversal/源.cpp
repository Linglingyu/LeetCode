#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){

	}
};

vector<vector<int> > levelOrder(TreeNode *root) {
	TreeNode *p,*q;
	p = root;
	queue<TreeNode*> que;
	vector<vector<int>> res;
	vector<int> innerres;
	auto quesize = que.size();
	que.push(p);
	while (!que.empty()){
		//cout << q->val;
		quesize = que.size();
		while (quesize)
		{
			q = que.front();
			innerres.push_back(q->val);
			que.pop();
			quesize--;
			if (q->left){ que.push(q->left); }
			if (q->right){ que.push(q->right); }
		}
		res.push_back(innerres);
		innerres.clear();
	}
	return res;
}

void main(){
	TreeNode tn1 = TreeNode(3);
	TreeNode tn2 = TreeNode(9);
	TreeNode tn3 = TreeNode(20);
	TreeNode tn4 = TreeNode(15);
	TreeNode tn5 = TreeNode(7);

	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	tn3.right = &tn5;

	vector<vector<int> > lores;
	lores = levelOrder(&tn1);

}