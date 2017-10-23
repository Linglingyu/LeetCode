// 216. Combination Sum III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

void combinationRec(vector<vector<int>> &res, vector<int> &temp, int k, int n,int begin){
	if (!n&&temp.size()==k){
		res.push_back(temp);
		return;
	}

	for (int i = begin; i <= 9; i++){
		if (i > n)continue;
		temp.push_back(i);
		combinationRec(res, temp, k, n - i, i + 1);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> temp;
	combinationRec(res, temp, k, n,1);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> result;
	result = combinationSum3(3, 7);
	for (auto i : result){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

