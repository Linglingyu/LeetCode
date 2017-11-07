// 123. Best Time to Buy and Sell Stock III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
#define MAX 65535
#define K 3
#define LEN 100000

using namespace std;

int maxProfit(vector<int>& prices) {

	int t[LEN][K][2];

	t[0][2][0] = -MAX;
	t[0][2][1] = -MAX;
	t[0][1][0] = -MAX;
	t[0][1][1] = -prices[0];

	for (int i = 0; i < prices.size(); i++){
		t[i][0][0] = 0;
		t[i][0][1] = -MAX;
	}

	for (int i = 1; i < prices.size(); i++){
		t[i][2][0] = max(t[i - 1][2][0], t[i - 1][2][1] + prices[i]);
		t[i][2][1] = max(t[i - 1][2][1], t[i - 1][1][0] - prices[i]);
		t[i][1][0] = max(t[i - 1][1][0], t[i - 1][1][1] + prices[i]);
		t[i][1][1] = max(t[i - 1][1][1],  - prices[i]);//t[i - 1][0][0]=0
	}

	int temp1 = max(t[prices.size() - 1][2][0], t[prices.size() - 1][1][0]);
	int res = max(temp1, t[prices.size() - 1][0][0]);
	return res;
	//return t[prices.size()-1][2][0];
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> prices{ 1, 2, 4};
	int res = maxProfit(prices);
	cout << res << endl;
	return 0;
}

