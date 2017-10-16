#include<iostream>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 1000

/*直接在数组A中插入B*/
void merge(int A[], int m, int B[], int n) {//leetcode:段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
	int i=0,j = 0;
	for (i; i < n; i++){
		for (j; j < m; j++){
			if (A[j] <= B[i])
				continue;//找到数组A中插入B[i]的地址
			for (int k = m; k > j-1; k--){
				A[k + 1] = A[k]; //**  从后向前归并，可以不用移
			}
			A[j] = B[i];//在数组A中插入B[i]，插入位置后面的数都要后移 
			m++;
			//for (int p = 0; p < m; p++)cout << A[p] << endl;
			//for (int q = 0; q < n; q++)cout << B[q] << endl;
			break;
		}
	}
	//如果数组B中还有数，就把剩下的数插入A后
	i = i - 1;//** A,B 为空
	if (B[i] > A[j - 1]){
		for (i; i < n; i++){
			A[j] = B[i];
			j = j + 1;
			m++;
		}
	}
}

/*将数组A和B合并后放在数组C中*/
void mergenew(int A[], int m, int B[], int n, int C[]){
	int i=0,j=0,k=0;
	while (i<m && j<n){
		if (A[i] <= B[j]){
			C[k++] = A[i++];
		}
		else{
			C[k++] = B[j++];
		}
	}
	while (i<m){
		C[k++] = A[i++];
	}
	while (j<n){
		C[k++] = B[j++];
	}

	for (int num = 0; num < m + n; num++){
		cout << C[num] << endl;
	}
}

/*A[first...mid和A[mid...last]有序，将其合并成一个有序数组*/
/*mid指向中间位置，last指向数组的最后一个位置*/
void mergeFrontEnd(int A[],int first,int mid,int last){
	int temp[MAX] = {0};
	int i = first;
	int j = mid+1;
	int k = 0;
	while (i <= mid&&j <= last){
		if (A[i] <=A[j]){
			temp[k++] = A[i++];
		}
		else{
			temp[k++] = A[j++];
		}
	}

	while (i <= mid){
		temp[k++] = A[i++];
	}

	while (j <=last){
		temp[k++] = A[j++];
	}

	for (int iter = 0; iter < k; iter++){
		A[first+iter] = temp[iter];
		cout << A[first + iter] << " ";
	}
	cout << endl;
}

/*采用分治法对一个无序数组归并排序*/
void divideSort(int A[],int first,int last){
	if (first < last){
		int mid = (first + last) / 2;
		divideSort(A, first, mid);
		divideSort(A, mid+1, last);
		mergeFrontEnd(A, first, mid, last);
	}

}

void main(){
	int a[MAX] = { 0, 5, 6, 20, 26, 45 };
	int b[MAX] = { 0 };
	//merge(a, 6, b, 5);
	int c[MAX] = {0};
	//mergenew(a, 6, b, 5, c);//将a，b两个有序数组合并成一个数组
	int d[MAX] = { 0, 5, 6, 20, 26, 45, 3, 6, 25, 30, 66 };
	//mergeFrontEnd(d, 0, 5, 10);
	int e[MAX] = {5,20,30,26,3,6,0,66,25,45,6};
	divideSort(e, 0, 10);
	int f[MAX] = { 26, 3 };
	//mergeFrontEnd(f, 0, 0, 1);//mid参数需是中间位置的后一个
	system("pause");
}

//#include<iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//#define MAX 1000
//
///*直接在数组A中插入B*/
//void merge(int A[], int m, int B[], int n) {//leetcode:段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
//	int i = 0, j = 0;
//	for (i; i < n; i++){
//		for (j; j < m; j++){
//			if (A[j] <= B[i])
//				continue;//找到数组A中插入B[i]的地址
//			for (int k = m; k > j - 1; k--){
//				A[k + 1] = A[k]; //**  从后向前归并，可以不用移
//			}
//			A[j] = B[i];//在数组A中插入B[i]，插入位置后面的数都要后移 
//			m++;
//			//for (int p = 0; p < m; p++)cout << A[p] << endl;
//			//for (int q = 0; q < n; q++)cout << B[q] << endl;
//			break;
//		}
//	}
//	//如果数组B中还有数，就把剩下的数插入A后
//	i = i - 1;//** A,B 为空
//	if (B[i] > A[j - 1]){
//		for (i; i < n; i++){
//			A[j] = B[i];
//			j = j + 1;
//			m++;
//		}
//	}
//}
//
///*将数组A和B合并后放在数组C中*/
//void mergenew(int A[], int m, int B[], int n, int C[]){
//	int i = 0, j = 0, k = 0;
//	while (i<m && j<n){
//		if (A[i] <= B[j]){
//			C[k++] = A[i++];
//		}
//		else{
//			C[k++] = B[j++];
//		}
//	}
//	while (i<m){
//		C[k++] = A[i++];
//	}
//	while (j<n){
//		C[k++] = B[j++];
//	}
//
//	for (int num = 0; num < m + n; num++){
//		cout << C[num] << endl;
//	}
//}
//
///*A[first...mid]和A[mid...last]有序，将其合并成一个有序数组*/
//void mergeFrontEnd(int A[], int first, int mid, int last){
//	int temp[MAX] = { 0 };
//	int i = first;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid&&j <= last){
//		if (A[i] <= A[j]){
//			temp[k++] = A[i++];
//		}
//		else{
//			temp[k++] = A[j++];
//		}
//	}
//
//	while (i <= mid){
//		temp[k++] = A[i++];
//	}
//
//	while (j <= last){
//		temp[k++] = A[j++];
//	}
//
//	for (int iter = 0; iter < k; iter++){
//		A[first + iter] = temp[iter];
//	}
//}
//
///*采用分治法对一个无序数组归并排序*/
//void divideSort(int A[], int first, int last){
//	if (first < last){
//		int mid = (first + last) / 2;
//		divideSort(A, first, mid);
//		divideSort(A, mid + 1, last);
//		mergeFrontEnd(A, first, mid, last);
//	}
//	for (int wj = first; wj<last + 1; wj++){
//		cout << A[wj] << " ";
//	}
//	cout << endl;
//}
//void main(){
//	int e[MAX] = { 5, 20, 30, 26, 3, 6, 0, 66, 25, 45, 6 };
//	divideSort(e, 0, 10);
//	//mergeFrontEnd(e, 0, 5, 10);
//	system("pause");
//}