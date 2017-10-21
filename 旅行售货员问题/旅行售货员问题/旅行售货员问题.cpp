// �����ۻ�Ա����.cpp : �������̨Ӧ�ó������ڵ㡣
//


/****************************************************************
*��  �⣺�����ۻ�Ա
*��  �������ݷ�
*��  ������ռ�Ϊ ������
****************************************************************/
#include "stdafx.h"
#include <stdio.h>  
#include<Windows.h>
#define N 4                //������Ŀ  
#define NO_PATH -1         //û��ͨ·  
#define MAX_WEIGHT 4000  
int City_Graph[N + 1][N + 1];  //����ͼ��Ϣ  
int x[N + 1];                //x[i]�����i�������ĳ���  
int isIn[N + 1];             //���� ����i�Ƿ��Ѿ�����·��  
int bestw;                 //����·����Ȩֵ  
int cw=0;                    //��ǰ·����Ȩֵ  
int bestx[N + 1];            //����·�� 

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
	//���Եݹ鷨  
	for (i = 1; i <= N; i++){
		x[i] = 0;               //��ʾ��i����û�н�  
		bestx[i] = 0;           //��û�����Ž�  
		isIn[i] = 0;            //��ʾ��i�����л�û�м��뵽·����  
	}

	x[1] = 1;                   //��һ�� �߳���1  
	isIn[1] = 1;                //��һ������ ����·��  
	bestw = MAX_WEIGHT;
	cw = 0;
	Travel_Backtrack(2);        //�ӵڶ�����ʼѡ�����  
	printf("����ֵΪ%d/n", bestw);
	printf("���Ž�Ϊ:/n");
	for (i = 1; i <= N; i++){
		printf("%d ", bestx[i]);
	}
	printf("/n");
	system("pause");
	return 0;
}

