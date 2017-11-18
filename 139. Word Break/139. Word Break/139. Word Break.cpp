// 139. Word Break.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<string>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
	vector<bool>dp(s.size()+1, false);
	dp[0] = true;
	string word;
	for (int i = 1; i <= s.size(); i++){
		for (int j = i-1; j >= 0; j--){
			if (dp[j]){
				word = s.substr(j, i - j);
				if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
					dp[i] = true;
				}
			}
		}
	}
	return dp[s.size()];

}
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "leetcode";
	vector<string> dict{ "leet", "code" };
	bool res = wordBreak(s, dict);
	system("pause");
	return 0;
}

