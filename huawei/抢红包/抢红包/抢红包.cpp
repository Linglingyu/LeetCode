// 抢红包.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int Seclarge(vector<int> &arr){
	sort(arr.begin(),arr.end());
	return arr[3];
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> arr;
	int temp;
	for (int i = 0; i < 5; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	int res = Seclarge(arr);
	cout << res;
	system("pause");
	return 0;
}

