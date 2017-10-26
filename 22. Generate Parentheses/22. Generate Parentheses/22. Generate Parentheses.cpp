// 22. Generate Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>

using namespace std;

void genRec(int left, int right, vector<string> &res, string &temp,int max){
	if (temp.length()==max*2){
		res.push_back(temp);
		return;
	}
	if (left < max){
		temp.push_back('(');
		genRec(left + 1, right, res, temp, max);
		temp.pop_back();
	}
	if (right < left){
		temp.push_back(')');
		genRec(left, right + 1, res, temp, max);
		temp.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	string temp;
	vector<string> res;
	genRec(0, 0, res, temp,n);
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> res;
	res = generateParenthesis(3);
	for (auto i : res){
		cout << i << endl;
	}
	system("pause");
	return 0;
}

