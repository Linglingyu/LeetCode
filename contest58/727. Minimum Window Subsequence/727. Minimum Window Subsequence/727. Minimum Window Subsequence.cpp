// 727. Minimum Window Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string lcs(string s1, string s2){
	if (s1.empty() || s2.empty())return "";
	int **dp = new int*[s1.size() + 1];
	for (int i = 0; i < s1.size() + 1; i++){
		dp[i] = new int[s2.size() + 1];
	}
	//memset(dp, 0, (s1.size() + 1)*(s2.size() + 1));
	for (int i = 0; i <= s1.size(); i++){
		for (int j = 0; j <= s2.size(); j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < s1.size() + 1; i++){
		for (int j = 1; j < s2.size() + 1; j++){
			if (s1[i - 1] == s2[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < s1.size() + 1; i++){
		for (int j = 1; j < s2.size() + 1; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int m = 0;
	for (m = 0; m < s1.size(); m++){
		cout << dp[m][1] << endl;
		if (dp[m][1] != 0){ 
			break; 
		}
	}
	int n = 0;
	for (int n = 0; n < s1.size(); n++){
		if (dp[n][s2.size()] == s2.size())break;
	}
	int len = 0;
	len = n -2;
	cout <<"len"<< len;
	string res = s1.substr(m,len);
	return res;
}

//string minWindow(string S, string T) {
//	
//}

int _tmain(int argc, _TCHAR* argv[])
{
	lcs("abcdebdde", "bde");
	return 0;
}

