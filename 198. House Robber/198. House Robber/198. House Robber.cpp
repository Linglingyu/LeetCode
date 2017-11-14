// 198. House Robber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.empty())return 0;
	int *p = new int[nums.size() + 1];//每一天的最大收益
	p[0] = 0;
	p[1] = nums[0];
	for (int i = 2; i <= nums.size(); i++){
		p[i] = max(p[i - 1], p[i - 2] + nums[i - 1]);
	}

	return p[nums.size()];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

