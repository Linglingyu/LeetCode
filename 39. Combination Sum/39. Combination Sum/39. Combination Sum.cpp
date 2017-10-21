// 39. Combination Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void combineRec(vector<vector<int>> &res, vector<int>& candidates, int target, int begin, vector<int> combination){
	if (!target){
		res.push_back(combination);
		return;
	}

	for (int i = begin; i < candidates.size()&&target>=candidates[i]; i++){
		combination.push_back(candidates[i]);
		combineRec(res, candidates, target - candidates[i], i, combination);
		combination.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> combination;
	combineRec(res, candidates, target, 0, combination);
	return res;

}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> candidates{ 2, 3, 6, 7 };
	vector<vector<int>> res = combinationSum(candidates, 7);
	for (auto i : res){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

