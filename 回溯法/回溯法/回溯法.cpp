// 回溯法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//01背包
#define N 3         //物品的数量  
#define C 16        //背包的容量  

int w[N] = { 10, 8, 5 };  //每个物品的重量  
int v[N] = { 5, 4, 1 };   //每个物品的价值  
int x[N] = { 0, 0, 0 };   //x[i]=1代表物品i放入背包，0代表不放入  

int CurWeight = 0;  //当前放入背包的物品总重量  
int CurValue = 0;   //当前放入背包的物品总价值  

int BestValue = 0;  //最优值；当前的最大价值，初始化为0  
int BestX[N];       //最优解；BestX[i]=1代表物品i放入背包，0代表不放入  

//t=0 to N-1
void backtrack(int t){
	if (t >= N) {//递归结束的判定条件
		if (CurValue > BestValue){
			BestValue = CurValue;
			for (int i = 0; i < N; i++)BestX[i] = x[i];
		}
	}
	else{
		//遍历当前节点的子节点

		//放背包	
			if (CurWeight + w[t] <= C){
				x[t] = 1;
				CurWeight += w[t];
				CurValue += v[t];
				backtrack(t + 1);
				CurWeight -= w[t];//此处回溯
				CurValue -= v[t];
			}
			//不放背包
			x[t] = 0;
			backtrack(t + 1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	backtrack(0);
	cout << BestValue << endl;
	system("pause");
	return 0;
}

