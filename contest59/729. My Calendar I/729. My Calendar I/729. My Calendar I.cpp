// 729. My Calendar I.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>

using namespace std;

class MyCalendar {
public:
	MyCalendar() {

	}

	bool book(int start, int end) {
		TRange *newrange = new TRange();
		newrange->start = start;
		newrange->end = end;
		if (occpied.empty()){
			occpied.push_back(*newrange);
			return true;
		}
		for (int i = 0; i < occpied.size(); i++){
			if (start >= occpied[i].start&&start < occpied[i].end)return false;
			if (end > occpied[i].start&&end < occpied[i].end)return false;
			if (start <= occpied[i].start&&end >= occpied[i].end)return false;//��Ҫ�����������
		}
		occpied.push_back(*newrange);
		return true;
	}

private:
	struct TRange
	{
		int start;
		int end;
	};
	vector<TRange> occpied;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

