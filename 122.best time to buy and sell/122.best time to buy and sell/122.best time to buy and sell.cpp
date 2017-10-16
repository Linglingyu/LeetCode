// 122.best time to buy and sell.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
	int sum = 0;
	if (prices.empty() || prices.size() == 1)return sum;
	int buy = 0, sell = 0;
	while (sell<prices.size()){
		if (sell == prices.size() - 1 || prices[sell + 1]<prices[sell]){
			sum = sum + prices[sell] - prices[buy];
			sell = sell + 1;
			buy = sell;
		}
		else
		{
			sell = sell + 1;
		}
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> pri{ 2, 1 };
	int res = maxProfit(pri);
	cout << res << endl;
	system("pause");
	return 0;
}

