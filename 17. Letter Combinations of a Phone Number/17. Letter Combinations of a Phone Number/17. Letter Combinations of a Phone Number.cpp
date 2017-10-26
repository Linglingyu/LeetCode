// 17. Letter Combinations of a Phone Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;

void combineRec(vector<string> &res, string &temp, string digits, int begin, map<char, string> combine){
	if (temp.size() >= digits.size()){
		res.push_back(temp);
		return;
	}

	for (int i = begin; i < digits.size(); i++){
		//cout << digits[i]<<endl;
		//int temp1 = digits[i];
		//cout << combine[digits[i]-48] << endl;
		for (int j = 0; j < combine[digits[i]-48].size(); j++){
			temp.push_back(combine[digits[i]-48][j]);
			combineRec(res, temp, digits, i + 1, combine);
			temp.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits) {
	map<char, string> combine;
	combine[2] = "abc";
	combine[3] = "def";
	combine[4] = "ghi";
	combine[5] = "jkl";
	combine[6] = "mno";
	combine[7] = "pqrs";
	combine[8] = "tuv";
	combine[9] = "wxyz";

	string temp;
	vector<string> res;
	if (digits.empty()){
		return res;
	}
	combineRec(res, temp, digits,0,combine);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> res = letterCombinations("3");
	for (auto i : res){
		cout << i << endl;
	}
	system("pause");
	return 0;
}

