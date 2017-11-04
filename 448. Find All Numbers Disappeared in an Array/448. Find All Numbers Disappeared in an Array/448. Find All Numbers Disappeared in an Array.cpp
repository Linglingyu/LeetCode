// 448. Find All Numbers Disappeared in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> res;
	int i = 0;
	while (i < nums.size()){
		if (nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
		else
			i++;
	}
	for (i = 0; i < nums.size(); i++){
		if (nums[i] != i + 1)res.push_back(i + 1);
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> res;
	vector<int> num{ 4, 3, 2, 7, 8, 2, 3, 1 };
	res = findDisappearedNumbers(num);

	return 0;
}

