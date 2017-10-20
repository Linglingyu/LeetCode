// ���ݷ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//01����
#define N 3         //��Ʒ������  
#define C 16        //����������  

int w[N] = { 10, 8, 5 };  //ÿ����Ʒ������  
int v[N] = { 5, 4, 1 };   //ÿ����Ʒ�ļ�ֵ  
int x[N] = { 0, 0, 0 };   //x[i]=1������Ʒi���뱳����0��������  

int CurWeight = 0;  //��ǰ���뱳������Ʒ������  
int CurValue = 0;   //��ǰ���뱳������Ʒ�ܼ�ֵ  

int BestValue = 0;  //����ֵ����ǰ������ֵ����ʼ��Ϊ0  
int BestX[N];       //���Ž⣻BestX[i]=1������Ʒi���뱳����0��������  

//t=0 to N-1
void backtrack(int t){
	if (t >= N) {//�ݹ�������ж�����
		if (CurValue > BestValue){
			BestValue = CurValue;
			for (int i = 0; i < N; i++)BestX[i] = x[i];
		}
	}
	else{
		//������ǰ�ڵ���ӽڵ�

		//�ű���	
			if (CurWeight + w[t] <= C){
				x[t] = 1;
				CurWeight += w[t];
				CurValue += v[t];
				backtrack(t + 1);
				CurWeight -= w[t];//�˴�����
				CurValue -= v[t];
			}
			//���ű���
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

