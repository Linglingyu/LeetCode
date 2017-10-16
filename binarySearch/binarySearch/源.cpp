#include<iostream>

using namespace std;

int binarySearch(int nums[],int n,int target){//n��nums[]�ĳ���,���õݹ�Ľⷨ
	int low = 0, high = n - 1;
	int m;
	while (low < high){
		m = low + ((high - 1) >> 2);//��ֹ���
		if (nums[m] < target){
			low = m + 1;
		}
		else{
			high = m;
		}
	}
	if (nums[high] == target) return high;
	return -1;
}

void main(){
	int ascNum[6] = {0,3,4,7,9,10};
	int index = binarySearch(ascNum, 6, 2);
	cout << index << endl;
}