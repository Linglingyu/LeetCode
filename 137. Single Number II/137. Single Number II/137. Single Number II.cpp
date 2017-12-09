// 137. Single Number II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
	int ones = 0, twos = 0;
	for (int i = 0; i < nums.size(); i++){
		ones = (ones^nums[i])&~twos;
		twos = (twos^nums[i])&~ones;
	}
	return ones;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>arr{ 43, 16, 45, 89, 45, -2147483648, 45, 2147483646, -2147483647, -2147483648, 43, 2147483647, -2147483646, -2147483648, 89, -2147483646, 89, -2147483646, -2147483647, 2147483646, -2147483647, 16, 16, 2147483646, 43 };
	//vector<int>arr{ 2, 2, 3, 2 };
	int res = singleNumber(arr);
	system("pause");
	return 0;
}

