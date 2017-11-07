// 188. Best Time to Buy and Sell Stock IV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
#define MAX 65535

using namespace std;

int maxProfit(int k, vector<int>& prices) {
	int res=0;
	if (prices.size() == 1 || prices.empty())return res;
	if (k >= (prices.size() >> 1)){
		int buy = 0, sell = 0;
		while (sell < prices.size()){
			if (sell == prices.size() - 1 || prices[sell + 1] < prices[sell]){
				res = res + prices[sell] - prices[buy];
				sell = sell + 1;
				buy = sell;
			}
			else{
				sell = sell + 1;
			}
		}
		return res;
	}
	else{
		int *t_ik0 = new int[k + 1];
		int *t_ik1 = new int[k + 1];

		for (int i = 0; i <= k; i++){
			t_ik0[i] = 0;
			t_ik1[i] = -MAX;
		}

		//t_ik1[1] = -prices[0];

		for (int i = 0; i < prices.size(); i++){
			for (int j = k; j >0; j--){
				t_ik0[j] = max(t_ik0[j], t_ik1[j] + prices[i]);
				/*if (j == 0)
					t_ik1[j] = max(t_ik1[j], -prices[i]);

				else*/
					t_ik1[j] = max(t_ik1[j], t_ik0[j - 1] - prices[i]);
			}
		}

		return t_ik0[k];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> prices{1,2,4,2,5,7,2,4,9,0};
	int k = 4;
	int res = maxProfit(k, prices);
	cout << res << endl;
	system("pause");
	return 0;
}

