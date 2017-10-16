/*��ת�������Сֵ�����Ӷ�Ϊo(logn)�Ľⷨ*/
/*���벻���������������������û�п��ǵ�*/
#include<iostream>

using namespace std;

int Min(int *num, int length){
	if (num == NULL || length <= 0)
		throw new std::exception("Invalid parameters");

	int p = 0, q = length-1;
	int mid = 0;
	while (p + 1 != q){
		mid = (p + q) / 2;
		if (num[mid] > num[p]){
			p = mid;
		}
		else if(num[mid]<num[q]){
			q = mid;
		}
	}
	return num[q];
}

void main(){
	int a[] = { 3, 4, 5, 1, 2 };
	int res=Min(a, 5);
	cout << res << endl;
	system("pause");
	
}