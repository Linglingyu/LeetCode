// 738. Monotone Increasing Digits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>

using namespace std;
//TLE
int monotoneIncreasingDigits1(int N) {
	int last = 0;
	int newlast = 0;
	while (N--){
		if (N < 10)return N;
		int res = N;
		last = res % 10;
		res = res / 10;
		while (res){
			newlast = res % 10;
			if (newlast > last)break;
			last = newlast;
			res = res / 10;
		}
		if (!res)return N;
		N = N--;
	}
}

string int2str(int N){
	string res;
	int temp=N;
	while (temp){
		int a = temp % 10;
		temp = temp / 10;
		char b = a;
		res.push_back(b);
	}
	return res;
}

//这是从高位开始改，然后再回到高位的做法
//也可以直接从低位开始改
int monotoneIncreasingDigits(int N) {
	string n = to_string(N);//int转string
	vector<int>str;
	int res = N;
	while (res){
		str.push_back(res % 10);
		res = res / 10;
	}
	int ind = -1;
	int i;
	for (i = str.size() - 1; i >= 0; i--){
		if (str[i]>str[i - 1]){
			str[i]--;
			ind = i;
			break;
		}
	}
	
	for (int j = i + 1; j<str.size(); j++){
		if (str[j]>str[j - 1]){
			str[j]--;
			ind = j;
		}
	}
	if (ind){
		for (int i = 0; i<ind; i++){
			str[i] = 9;
		}
	}
	int num = 0;
	for (int i = str.size()-1; i >= 0; i--){
		num = num * 10 + str[i];
	}
	return num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = monotoneIncreasingDigits(10);
	system("pause");

	return 0;
}

