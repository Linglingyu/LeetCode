// 714. Best Time to Buy and Sell with Transaction Fee.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 65536

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
	int *t_0 = new int[prices.size()];
	int *t_1 = new int[prices.size()];
	for (int i = 0; i < prices.size(); i++){
		t_0[i] = 0;
		t_1[i] = -MAX;
	}

	for (int i = 1; i < prices.size(); i++){
		t_0[i] = max(t_0[i - 1], t_1[i - 1] + prices[i] - fee);
		t_1[i] = max(t_1[i - 1], t_0[i - 1] - prices[i]);
	}

	return t_0[prices.size()-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

