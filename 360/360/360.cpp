// 360.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	vector<int> points;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		points.push_back(temp);
	}
	int ask;
	cin >> ask;
	vector<int> res;
	for (int j = 0; j < ask; j++){
		int l, r;
		cin >> l >> r;
		if (r - l < 2){
			//cout << 0;
			res.push_back(0);
		}
		else{
			int barrier = 0;
			for (int k = l-1; k < r - 2; k++){
				if (points[k] <= points[k + 1] && points[k + 1] <= points[k + 2]){
					cout << points[k] << " " << points[k+1] << " " << points[k+2] <<endl;
					barrier++;
				}
			}
			res.push_back(barrier);
			//cout << barrier<<endl;
		}
	}
	for (int p = 0; p < ask; p++){
		cout << res[p] << endl;
	}
	system("pause");
	return 0;
}

