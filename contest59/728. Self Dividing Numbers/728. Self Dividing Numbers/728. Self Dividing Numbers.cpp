// 728. Self Dividing Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

bool dividable(int num){
	int i;
	int temp = num;
	while (temp){
		i = temp % 10;
		if (!i)return false;
		if (num%i)return false;
		temp = temp / 10;
	}
	return true;
}

vector<int> selfDividingNumbers(int left, int right) {
	vector<int> res;
	for (int j = left; j <= right; j++){
		if (dividable(j))res.push_back(j);
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

