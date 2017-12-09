// 739. Daily Temperatures.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#define MAX 65535

using namespace std;

//TLE
vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> res(temperatures.size(),0);
	for (int i = 0; i < temperatures.size(); i++){
		for (int j = i+1; j < temperatures.size(); j++){
			if (temperatures[j] > temperatures[i]){
				res[i] = j - i;
				break;
			}
		}
	}
	return res;
}

//using next[] array
//注意到温度范围[30,100]
vector<int> dailyTemperatures2(vector<int>& temperatures) {
	vector<int> res(temperatures.size(),0);
	vector<int> next(101, MAX);
	for (int i = temperatures.size() - 1; i >= 0; i--){
		int warmer = MAX;
		for (int t = temperatures[i] + 1; t <= 100; t++){
			if (next[t] < warmer)
				warmer = next[t];
		}
		if (warmer < MAX)
			res[i] = warmer - i;
		next[temperatures[i]] = i;
	}
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> temperature{ 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> res = dailyTemperatures2(temperature);
	system("pause");
	return 0;
}

