// 70. Climbing Stairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int climbStairs(int n) {
	int *w = new int[n+1];
	w[0] = 0;
	w[1] = 1;
	w[2] = 2;
	for (int i = 3; i <= n; i++){
		w[i] = w[i - 1] + w[i - 2];
	}

	return w[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

