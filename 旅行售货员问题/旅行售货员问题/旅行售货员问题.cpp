// 旅行售货员问题.cpp : 定义控制台应用程序的入口点。
//


/****************************************************************
*问  题：旅行售货员
*算  法：回溯法
*描  述：解空间为 排列树
****************************************************************/
#include "stdafx.h"
#include <stdio.h>  
#include<Windows.h>
#define N 4                //城市数目  
#define NO_PATH -1         //没有通路  
#define MAX_WEIGHT 4000  
int City_Graph[N + 1][N + 1];  //保存图信息  
int x[N + 1];                //x[i]保存第i步遍历的城市  
int isIn[N + 1];             //保存 城市i是否已经加入路径  
int bestw;                 //最优路径总权值  
int cw=0;                    //当前路径总权值  
int bestx[N + 1];            //最优路径 

void Travel_Backtrack(int t){
	if (t > N){
		if (bestw > cw){
			bestw = cw;
			for (int i = 1; i <= N; i++){
				bestx[i] = x[i];
			}
			printf("%d", bestw);
		}
		return;
	}

	for (int i = 1; i <= N; i++){
		if (City_Graph[x[t - 1]][i] != NO_PATH&&!isIn[i]){
			cw += City_Graph[x[t - 1]][i];
			x[t] = i;
			isIn[i] = 1;
			Travel_Backtrack(t + 1);
			cw -= City_Graph[x[t - 1]][i];
			x[t] = 0;
			isIn[i] = 0;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	City_Graph[1][1] = NO_PATH;
	City_Graph[1][2] = 30;
	City_Graph[1][3] = 6;
	City_Graph[1][4] = 4;

	City_Graph[2][1] = 30;
	City_Graph[2][2] = NO_PATH;
	City_Graph[2][3] = 5;
	City_Graph[2][4] = 10;
	City_Graph[3][1] = 6;
	City_Graph[3][2] = 5;
	City_Graph[3][3] = NO_PATH;
	City_Graph[3][4] = 20;

	City_Graph[4][1] = 4;
	City_Graph[4][2] = 10;
	City_Graph[4][3] = 20;
	City_Graph[4][4] = NO_PATH;
	//测试递归法  
	for (i = 1; i <= N; i++){
		x[i] = 0;               //表示第i步还没有解  
		bestx[i] = 0;           //还没有最优解  
		isIn[i] = 0;            //表示第i个城市还没有加入到路径中  
	}

	x[1] = 1;                   //第一步 走城市1  
	isIn[1] = 1;                //第一个城市 加入路径  
	bestw = MAX_WEIGHT;
	cw = 0;
	Travel_Backtrack(2);        //从第二步开始选择城市  
	printf("最优值为%d/n", bestw);
	printf("最优解为:/n");
	for (i = 1; i <= N; i++){
		printf("%d ", bestx[i]);
	}
	printf("/n");
	system("pause");
	return 0;
}

