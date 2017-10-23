// 77. Combinations.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

void combineRec(vector<vector<int>> &res, vector<int> &temp, int n, int k, int begin){
	if (temp.size() == k){
		res.push_back(temp);
		return;
	}

	for (int i = begin; i <= n; i++){
		temp.push_back(i);
		combineRec(res, temp, n, k, i + 1);
		temp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp;
	combineRec(res, temp, n, k, 1);
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> result;
	result = combine(4, 2);
	for (auto i : result){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

