#include<stdio.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int maxDepth(TreeNode *root) {
		TreeNode *temp;
		if (root==NULL){
			return 0;
		}
		if (!temp->left&&!temp->right){
			return 1;
		}
		else if (temp->left&&temp->right){
			return maxDepth(temp->left) > maxDepth(temp->right) ? maxDepth(temp->left) + 1 : maxDepth(temp->right) + 1;
		}
		else if (temp->left){
			return maxDepth(temp->left) + 1;
		}
		else{
			return maxDepth(temp->right) + 1;
		}
	}
};

void main(){
	TreeNode *root = new TreeNode(1);
	TreeNode *tn1 = new TreeNode(8);
	TreeNode *tn2 = new TreeNode(4);
	TreeNode *tn3 = new TreeNode(6);
	TreeNode *tn4 = new TreeNode(1);
	TreeNode *tn5 = new TreeNode(3);

}