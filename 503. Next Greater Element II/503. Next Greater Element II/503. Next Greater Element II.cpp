// 503. Next Greater Element II.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<stack>

using namespace std;

//ʱ�临�Ӷ���n*n�Ľⷨ
vector<int> nextGreaterElements01(vector<int>& nums) {
	vector<int> res;
	if (nums.size() == 1){
		res.push_back(-1);
		return res;
	}
	for (int i = 0; i < nums.size(); i++){
		int j ;
		if (i<nums.size() - 1){
			j = i + 1;
		}
		else{
			j = 0;
		}
		while (j != i){
			if (nums[j] > nums[i]){
				res.push_back(nums[j]);
				break;
			}
			if (j == nums.size()-1){
				j = 0;
			}
			else{
				j++;
			}
		}
		if (j == i){
			res.push_back(-1);
		}
	}
	return res;
}

//ʹ��һ������ջ�Ľⷨ��ʱ�临�ӶȽ�Ϊn��
vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int> stk;
	vector<int> res;
	for (int i = nums.size()-1; i >= 0; i--){
		while (!stk.empty()){
			if (nums[stk.top()] <= nums[i]){
				stk.pop();
			}
			else{
				res.push_back(nums[stk.top()]);
				stk.push(i);
				break;
			}
		}
		if (stk.empty()){
			res.push_back(-1);
			stk.push(i);
		}
	}

	for (int i = nums.size()-1; i >= 0; i--){
		while (!stk.empty()){
			if (nums[stk.top()] <= nums[i]){
				stk.pop();
			}
			else{
				res[i]=nums[stk.top()];
				stk.push(i);
				break;
			}
		}
		if (stk.empty()){
			res[i]=-1;
			stk.push(i);
		}
	}
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num{ 3,8,4,1,2 };
	vector<int> res = nextGreaterElements(num);
	return 0;
}

