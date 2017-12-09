// 260. Single Number III.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	map<int, int> data;
	for (int i = 0; i < nums.size(); i++){
		if (data[nums[i]])
			data[nums[i]]++;
		else
			data[nums[i]] = 1;
	}
	vector<int> res;
	for (auto j = data.begin(); j != data.end(); j++){
		if (j->second == 1){ 
			res.push_back(j->first); 
		}
	}
	return res;

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

