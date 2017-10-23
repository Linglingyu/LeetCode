// 40. Combination Sum II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void combineRec(vector<vector<int>> &res, vector<int> candidates, int target, int begin, vector<int> &currentCombination){
	if (!target){
		res.push_back(currentCombination);
		return;
	}

	for (int i = begin; i < candidates.size(); i++){
		//if (candidates[i] > target || (begin!=0 && currentCombination[begin - 1] == candidates[i]))continue;
		if (candidates[i] > target)return;
		if (i && i > begin && candidates[i] == candidates[i - 1]) continue;
		currentCombination.push_back(candidates[i]);
		combineRec(res, candidates, target - candidates[i], i + 1, currentCombination);//注意这里是i+1,不是begin+1，因为要把有重复的元素跳过
		currentCombination.pop_back();
	}

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> currentCombination;
	sort(candidates.begin(), candidates.end());
	combineRec(res,candidates, target, 0, currentCombination);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> candidates{10,1,2,7,6,1,5};
	vector<vector<int>> res;
	res = combinationSum2(candidates, 8);
	for (auto i : res){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

