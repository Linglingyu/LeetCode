/*快排练习 用数组写的*/
#include<iostream>

using namespace std;

int partition(int *a, int len){
	int temp = a[len - 1];
	int j = 0,i = -1;
	int temp2;
	for (j = 0; j < len; j++){
		if (a[j] < temp){
			i++;
			temp2 = a[j];
			a[j] = a[i];
			a[i] = temp2;
		}
	}
	temp2 = a[i + 1];
	a[i + 1] = temp;
	a[len - 1] = temp2;

	for (int k = 0; k < len; k++){
		cout << a[k]<< " ";
	}
	cout << endl;

	return (i + 1);
}

int* quickSort(int *a,int len){
	int mid = partition(a, len);
	if (mid!=0){
		quickSort(a, mid);
	}
	if (mid!=(len-1)){
		quickSort(a + (mid + 1), len - mid - 1);
	}
	return a;
}

void main(){
	int num_a[] = {3,4,7,9,2,6};
	int num_b[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int len = 8;
	int *res = quickSort(num_b, len);
	for (int k = 0; k < len; k++){
		cout << res[k] << " ";
	}

	system("pause");
}