/*于一棵满二叉排序树深度为k，节点数为2^k-1;节点值为1至（2^k - 1）,给出k和任意三个节点的值，输出包含该三个节点的最小子树的根节点。

样例输入：4 10 15 13

样例输出：12*/

#include<iostream>

using namespace std;

int FindMinRoot(int left, int right,int small,int large){
	while (left < right){
		int mid = (left + right)/2;
		if (mid >= small&&mid <= large){
			return mid;
		}
		else if (mid < small){
			left = mid+1;
		}
		else if (mid > large){
			right = mid-1;
		}
	}
	return left;
}

void main(){
	int k;
	cin >> k;
	int arr[3];
	int max, min;
	for (int i = 0; i < 3; i++){
		cin >> arr[i];
	}
	max = arr[0] > arr[1] ? (arr[0] > arr[2] ? arr[0] : arr[2]) : (arr[1] > arr[2] ? arr[1] : arr[2]);
	min = arr[0] < arr[1] ? (arr[0] < arr[2] ? arr[0] : arr[2]) : (arr[1] < arr[2] ? arr[1] : arr[2]);

	int res = FindMinRoot(1, pow(2, k) - 1, min, max);
	cout << res << endl;
	system("pause");
}
