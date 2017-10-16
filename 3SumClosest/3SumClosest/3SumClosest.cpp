// 3SumClosest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int sum = 0;
	int dis = 10000;
	int absdis = 10000;
	int res = 10000;
	for (int i = 0; i < nums.size(); i++){
		for (int j = i+1; j < nums.size(); j++){
			for (int k = j + 1; k < nums.size(); k++){
				sum = nums[i] + nums[j] + nums[k];
				absdis = (sum - target) > 0 ? (sum - target) : (target - sum);
				if (dis > absdis){
					dis = absdis;
					res = sum;
				}
			}
		}
	}
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> testarr;
	testarr.push_back(0);
	testarr.push_back(0);
	testarr.push_back(0);
	int result = threeSumClosest(testarr, 1);
	cout << result << endl;
	system("pause");
	return 0;
}

