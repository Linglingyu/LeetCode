#include<iostream>

using namespace std;

bool Find(int *matrix, int rows, int columns, int number){
	int row=0;
	int column=columns-1;
	while (row <= rows&&column >= 0){
		if (matrix[row*columns + column] == number)
			return true;
		if (matrix[row*columns + column] > number){
			column--;
		}
		else{
			row++;
		}
	}
	return false;
}

void main(){
	int matrix[] = { 1, 2, 8, 9 , 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	int rows = 4;
	int columns = 4;
	bool doexist = Find(matrix, rows, columns, 1);
	system("pause");
}