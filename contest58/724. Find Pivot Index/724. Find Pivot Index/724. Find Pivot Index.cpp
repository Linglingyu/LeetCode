// 724. Find Pivot Index.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
	if (nums.empty())return -1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++){
		sum += nums[i];
	}
	int temp = 0;
	for (int i = 0; i < nums.size(); i++){
		if (temp * 2 + nums[i] == sum){
			return i;
		}
		else{
			temp += nums[i];
		}
	}
	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums{ -1,-1,-1,1,1,1 };
	int res = pivotIndex(nums);
	return 0;
}

