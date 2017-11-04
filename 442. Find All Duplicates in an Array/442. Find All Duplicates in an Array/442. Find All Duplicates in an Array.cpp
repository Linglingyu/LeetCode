// 442. Find All Duplicates in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] != nums[nums[i] - 1]) {
			cout << nums[i] << " "<<nums[nums[i]-1]<<endl;
			swap(nums[i], nums[nums[i] - 1]); 
		}
		else i++;
	}
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != i + 1) res.push_back(nums[i]);
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num{ 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> res = findDuplicates(num);
	system("pause");
	return 0;
}

