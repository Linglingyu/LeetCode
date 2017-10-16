#include <iostream>  
#include <cstdio>  
using namespace std;

int sum;

void dfs(int** a, int x, int y, int n, int cnt){
	a[x][y] = ++cnt;
	if (cnt >= sum){
		return;
	}
	for (int i = 0; i < n - 1; ++i){
		y++;
		a[x][y] = ++cnt;
	}

	for (int i = 0; i < n - 1; ++i){
		x++;
		a[x][y] = ++cnt;
	}
	for (int i = 0; i < n - 1; ++i){
		y--;
		a[x][y] = ++cnt;

	}
	for (int i = 0; i < n - 2; ++i){
		x--;
		a[x][y] = ++cnt;
	}

	if (cnt >= sum)
		return;
	y++;
	dfs(a, x, y, n - 2, cnt);
}

void print(int n){
	n = sqrt(double(n + 1));
	int **a = new int *[n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];
	int cnt = 0;
	sum = n*n;
	dfs(a, 0, 0, n, cnt);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d  ", a[i][j]-1);
		}
		printf("\n");
	}
	system("pause");
}

void main(){
	int n = 35;
	print(n);
}