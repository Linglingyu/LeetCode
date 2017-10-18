// 46. Permutations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

void permuterecusion(vector<int>& nums, int begin, vector<vector<int>> &result);

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	
	permuterecusion(nums, 0,result);

	return result;
}

//nums[0..begin-1]固定
void permuterecusion(vector<int>& nums, int begin, vector<vector<int>> &result){
	if (begin>=nums.size()){
		cout << "result: ";
		for (int k = 0; k < nums.size(); k++){
			cout << nums[k] << " ";
		}
		cout << endl;
		result.push_back(nums);
		return;
	}

	for (int i = begin; i < nums.size(); i++){
		swap(nums[begin], nums[i]);
		for (int k = 0; k < nums.size(); k++){
			cout << nums[k] << " ";
		}
		cout << endl;
		permuterecusion(nums, begin+1, result);
		swap(nums[begin], nums[i]);
		for (int k = 0; k < nums.size(); k++){
			cout << nums[k] << " ";
		}
		cout << endl;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>nums{ 1, 2, 3 };
	vector<vector<int>>result;
	result = permute(nums);
	system("pause");
	return 0;
}

