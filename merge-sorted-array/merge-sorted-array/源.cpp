#include<iostream>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 1000

/*ֱ��������A�в���B*/
void merge(int A[], int m, int B[], int n) {//leetcode:�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������
	int i=0,j = 0;
	for (i; i < n; i++){
		for (j; j < m; j++){
			if (A[j] <= B[i])
				continue;//�ҵ�����A�в���B[i]�ĵ�ַ
			for (int k = m; k > j-1; k--){
				A[k + 1] = A[k]; //**  �Ӻ���ǰ�鲢�����Բ�����
			}
			A[j] = B[i];//������A�в���B[i]������λ�ú��������Ҫ���� 
			m++;
			//for (int p = 0; p < m; p++)cout << A[p] << endl;
			//for (int q = 0; q < n; q++)cout << B[q] << endl;
			break;
		}
	}
	//�������B�л��������Ͱ�ʣ�µ�������A��
	i = i - 1;//** A,B Ϊ��
	if (B[i] > A[j - 1]){
		for (i; i < n; i++){
			A[j] = B[i];
			j = j + 1;
			m++;
		}
	}
}

/*������A��B�ϲ����������C��*/
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

/*A[first...mid��A[mid...last]���򣬽���ϲ���һ����������*/
/*midָ���м�λ�ã�lastָ����������һ��λ��*/
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

/*���÷��η���һ����������鲢����*/
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
	//mergenew(a, 6, b, 5, c);//��a��b������������ϲ���һ������
	int d[MAX] = { 0, 5, 6, 20, 26, 45, 3, 6, 25, 30, 66 };
	//mergeFrontEnd(d, 0, 5, 10);
	int e[MAX] = {5,20,30,26,3,6,0,66,25,45,6};
	divideSort(e, 0, 10);
	int f[MAX] = { 26, 3 };
	//mergeFrontEnd(f, 0, 0, 1);//mid���������м�λ�õĺ�һ��
	system("pause");
}

//#include<iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//#define MAX 1000
//
///*ֱ��������A�в���B*/
//void merge(int A[], int m, int B[], int n) {//leetcode:�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������
//	int i = 0, j = 0;
//	for (i; i < n; i++){
//		for (j; j < m; j++){
//			if (A[j] <= B[i])
//				continue;//�ҵ�����A�в���B[i]�ĵ�ַ
//			for (int k = m; k > j - 1; k--){
//				A[k + 1] = A[k]; //**  �Ӻ���ǰ�鲢�����Բ�����
//			}
//			A[j] = B[i];//������A�в���B[i]������λ�ú��������Ҫ���� 
//			m++;
//			//for (int p = 0; p < m; p++)cout << A[p] << endl;
//			//for (int q = 0; q < n; q++)cout << B[q] << endl;
//			break;
//		}
//	}
//	//�������B�л��������Ͱ�ʣ�µ�������A��
//	i = i - 1;//** A,B Ϊ��
//	if (B[i] > A[j - 1]){
//		for (i; i < n; i++){
//			A[j] = B[i];
//			j = j + 1;
//			m++;
//		}
//	}
//}
//
///*������A��B�ϲ����������C��*/
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
///*A[first...mid]��A[mid...last]���򣬽���ϲ���һ����������*/
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
///*���÷��η���һ����������鲢����*/
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