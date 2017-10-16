///*根据前序和中序遍历的结果重建二叉树*/
//#include<iostream>
//#define len 8
//
//using namespace std;
//
//struct BinaryTreeNode
//{
//	int value;
//	BinaryTreeNode *pLeft;
//	BinaryTreeNode *pRight;
//};
//
//BinaryTreeNode *reConstruct(int *pre,int *preend, int *in,int *inend){
//	int start = pre[0];
//	BinaryTreeNode *startRoot=new BinaryTreeNode();
//	startRoot->value = start;
//	startRoot->pLeft = startRoot->pRight = NULL;
//
//	int i = 0;
//	for (i = 0; i < (preend-pre)&&in[i] != start; i++);//在中序遍历中找到根节点的值
//
//	startRoot->pLeft=reConstruct(pre+1, pre + i, in, in + i-1);
//	startRoot->pRight = reConstruct(pre+i+1, preend, in+i+1, inend);
//
//	return startRoot;
//}
//
//void main(){
//	int preOrder[len] = {1,2,4,7,3,5,6,8};
//	int inOrder[len] = {4,7,2,1,5,3,8,6};
//	BinaryTreeNode *root = reConstruct(preOrder, preOrder+len-1, inOrder, inOrder+len-1);
//}
//
//

/*根据前序和中序遍历的结果重建二叉树*/
#include<iostream>
#define len 8

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *pLeft;
	BinaryTreeNode *pRight;
};

BinaryTreeNode *reConstruct(int *pre, int *preend, int *in, int *inend){

	// 初始化一个节点
	BinaryTreeNode *startRoot = new BinaryTreeNode();

	startRoot->pLeft = startRoot->pRight = NULL;
	int* pretmp = pre;
	int* intmp = NULL;
	int breakind = 0;
	for (; pretmp <= preend; pretmp++){
		intmp = in;
		for (; intmp <= inend; intmp++){
			if ((*intmp) == (*pretmp)){
				startRoot->value = (*intmp);
				breakind = 1;
				break;
			}
		}
		if (breakind)
			break;
	}
	cout << startRoot->value << endl;
	//cout<<*in<<' '<<*inend<<endl;
	if (in != intmp){
		startRoot->pLeft = reConstruct(pre, preend, in, intmp - 1);
	}
	if (inend != intmp){
		startRoot->pRight = reConstruct(pre, preend, intmp + 1, inend);
	}
	return startRoot;
}
void puttree(BinaryTreeNode* t, int h, char* bra){
	int i;
	if (t != NULL){
		puttree(t->pRight, h + 1, bra);
		for (i = 0; i<h; i++)putchar('\t');
		printf("%d ", t->value);

		putchar(bra[
			((NULL != (t->pLeft)) << 1)
				| (NULL != (t->pRight))
		]);
		putchar('\n');
		puttree(t->pLeft, h + 1, bra);
	}
}

void main(){
	int preOrder[len] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inOrder[len] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode *root = reConstruct(preOrder, preOrder + len - 1, inOrder, inOrder + len - 1);
	char bra[] = { "-/\\<" };
	puttree(root, 0, bra);
	system("pause");
}