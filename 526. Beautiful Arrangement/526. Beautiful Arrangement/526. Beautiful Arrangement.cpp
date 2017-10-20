// 526. Beautiful Arrangement.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

//vector<int> temp;
vector<int>::iterator it;
void countRec(int &numofBA,int t,vector<int> arr){
	if (t >= arr.size()){
		int j = 0;
		
		cout << "beautiful: ";
		for (auto k : arr){
			cout << k << " ";
		}
		cout << endl;
		numofBA++;
		
		return;
	}

	for (int i = t; i < arr.size(); i++){
		//it = find(temp.begin(), temp.end(), i);
		//if (it != temp.end())continue;
		//temp.push_back(i);
		swap(arr[i], arr[t]);
		if (((t+1) % arr[t] != 0) && (arr[t] % (t+1)) != 0)continue;
		countRec(numofBA, t + 1, arr);
		swap(arr[i], arr[t]);
		//temp.pop_back();
	}
}

int countArrangement(int N) {
	int numofBA = 0;
	vector<int> Arr;
	for (int i = 1; i <= N; i++)Arr.push_back(i);
	countRec(numofBA, 0, Arr);
	return numofBA;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = countArrangement(15);
	cout << res << endl;
	system("pause");
	return 0;
}

