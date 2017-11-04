// 435. Non-overlapping Intervals.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b){
	return a.end < b.end;
}
int eraseOverlapIntervals(vector<Interval>& intervals) {
	if (intervals.empty())return 0;

	sort(intervals.begin(), intervals.end(), compare);
	int events = 1;
	int totalend = intervals[0].end;
	int i = 1;
	while(i < intervals.size()){
		if (intervals[i].start >= totalend){
			totalend = intervals[i].end;
			events += 1;
		}
		i++;
	}

	return (intervals.size() - events);
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

