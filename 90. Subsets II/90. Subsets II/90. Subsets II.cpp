// 90. Subsets II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void subRec(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int begin){
	res.push_back(temp);

	for (int i = begin; i < nums.size(); i++){
		if (i&&i > begin&&nums[i] == nums[i-1])continue;//注意这里是i和i-1
		temp.push_back(nums[i]);
		subRec(res, temp, nums, i + 1);
		temp.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	subRec(res, temp, nums, 0);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> res;
	vector<int> nums{ 1, 2, 2 };
	res = subsets(nums);
	for (auto i : res){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

