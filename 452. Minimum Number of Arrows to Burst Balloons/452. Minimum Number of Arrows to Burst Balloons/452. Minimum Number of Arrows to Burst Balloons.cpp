// 452. Minimum Number of Arrows to Burst Balloons.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
	return a.first < b.first;
}

int findMinArrowShots(vector<pair<int, int>>& points) {
	if (points.empty())return 0;
	sort(points.begin(), points.end(), compare);//�ұ����갴����������
	int shotnum = 1;
	int shotpoint = points[0].second;
	int i = 1;
	while(i < points.size()){
		if (shotpoint >= points[i].first){
			if (shotpoint > points[i].second){
				shotpoint = points[i].second;
			}
		}
		else{
			shotnum++;
			shotpoint = points[i].second;
		}
		i++;
	}
	return shotnum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

