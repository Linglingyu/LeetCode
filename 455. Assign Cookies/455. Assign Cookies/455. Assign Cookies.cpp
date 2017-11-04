// 455. Assign Cookies.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int temp;
	int res=0;
	int i = 0;
	vector<int>::iterator itrg = g.begin();
	vector<int>::iterator itrs = s.begin();
	while(itrg!=g.end()&&itrs!=s.end()){
		cout << *itrg << endl;
		cout << *itrs << endl;
		if (*itrg <= *itrs){
			itrg++;
			itrs++;
			res++;
			continue;
		}
		else{
			itrs++;
		}

	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> g{ 1, 2 };
	vector<int> s{ 1, 2, 3 };
	int res = findContentChildren(g, s);
	cout << res << endl;
	system("pause");
	return 0;
}

