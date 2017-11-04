// 392. Is Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

bool isSubsequence(string s, string t) {
	int i = 0;
	int j = 0;
	if (s.empty())return true;
	while (i < s.size()&&j<t.size()){
		if (s[i] == t[j]){
			if (i == s.size() - 1){
				return true;
			}
			if (j == t.size() - 1){
				return false;
			}
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string s{ "axc" };
	string t{ "ahbgdc" };
	bool res = isSubsequence(s, t);
	cout << res << endl;
	system("pause");
	return 0;
}

