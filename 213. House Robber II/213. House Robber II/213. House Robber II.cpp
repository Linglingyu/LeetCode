// 213. House Robber II.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<int> maxprofit(nums.size()+1,0);
	maxprofit[0] = 0;
	maxprofit[1] = nums[0];//��һ��͵��
	for (int i = 2; i < nums.size(); i++){//���һ�䲻��͵��
		maxprofit[i] = max(maxprofit[i - 1], maxprofit[i - 2] + nums[i - 1]);
	}
	int max1 = maxprofit[nums.size()];

	maxprofit[1] = 0;//��һ��û͵
	for (int i = 2; i <= nums.size(); i++){//���һ����͵
		maxprofit[i] = max(maxprofit[i - 1], maxprofit[i - 2] + nums[i - 1]);
	}
	int max2 = maxprofit[nums.size()];

	return max1 > max2 ? max1 : max2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> arr = { 1 };
	int res = rob(arr);
	system("pause");
	return 0;
}

