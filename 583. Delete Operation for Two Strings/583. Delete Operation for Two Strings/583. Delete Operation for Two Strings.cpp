// 583. Delete Operation for Two Strings.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int lcs(string s1, string s2,int m,int n);

int minDistance(string word1, string word2) {
	return word1.size() + word2.size() - 2 * lcs(word1, word2, word1.size(), word2.size());
}

//���������lcs
int lcs(string s1, string s2, int m, int n){
	if (m == 0 || n == 0)
		return 0;

		if (s1[m-1] == s2[n-1]){
			cout << s1[m - 1] << "=" << s2[n - 1] << endl;
			return 1 + lcs(s1, s2, m - 1, n - 1);
		}
		else{
			return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
		}
}

//����ķ����ݹ����̫�࣬����ջ���
//�������ַ������Ѿ���õ������г��ȴ���һ����������ٵݹ����

int lcs_memory(string s1, string s2, int m, int n, int **memop);
int minDistance_memory(string s1, string s2){
	int **memo = new int*[s1.size()+1];
	for (int i = 0; i <= s1.size(); i++){
		memo[i] = new int[s2.size()+1];
	}

	for (int i = 0; i <= s1.size(); i++){
		for (int j = 0; j <= s2.size(); j++){
			memo[i][j] = 0;
		}
	}
	return s1.size()+s2.size()-2*lcs_memory(s1, s2, s1.size(), s2.size(),memo);
}

int lcs_memory(string s1, string s2, int m, int n, int **memop){
	if (m == 0 || n == 0)
		return 0;

	if (memop[m][n]){
		return memop[m][n];
	}

	if (s1[m - 1] == s2[n - 1]){
		cout << s1[m - 1] << "=" << s2[n - 1] << endl;
		memop[m][n] = 1 + lcs_memory(s1, s2, m - 1, n - 1, memop);
		return memop[m][n];
	}
	else{
		memop[m][n] = max(lcs_memory(s1, s2, m - 1, n, memop), lcs_memory(s1, s2, m, n - 1, memop));
		return memop[m][n];
	}

}

//���õݹ�ķ���
int minDistance_noiter(string s1, string s2){
	if (s1.empty() || s2.empty())return s1.size() + s2.size();
	int **dp = new int*[s1.size() + 1];
	for (int i = 0; i < s1.size()+1; i++){
		dp[i] = new int[s2.size() + 1];
	}
	//memset(dp, 0, (s1.size() + 1)*(s2.size() + 1));
	for (int i = 0; i <= s1.size(); i++){
		for (int j = 0; j <= s2.size(); j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < s1.size()+1; i++){
		for (int j = 1; j < s2.size() + 1; j++){
			if (s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return s1.size()+s2.size()-2*dp[s1.size()][s2.size()];
}

int _tmain(int argc, _TCHAR* argv[])
{
	string word1 = "a";
	string word2 = "a";
	int res = minDistance_noiter(word1, word2);
	cout << res << endl;
	system("pause");
	return 0;
}

