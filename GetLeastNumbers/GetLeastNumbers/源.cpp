/*��multisetʵ�֣�multiset��set���ǻ��ں����ʵ�ֵ�*/
#include<iostream>
#include<set>
#include<vector>
#include<functional>

using namespace std;

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet &leastNumbers, int k){
	leastNumbers.clear();

	if (k < 1 || data.size() < k)
		return;

	vector<int>::const_iterator iter = data.begin;
	for (; iter != data.end(); ++iter){
		if (leastNumbers.size() < k){
			leastNumbers.insert(*iter);
		}
		else{
			setIterator iterGreast = leastNumbers.begin();

			if (*iter < *iterGreast){
				leastNumbers.erase(iterGreast);
				leastNumbers.insert(*iter);
			}
		}
	}
}