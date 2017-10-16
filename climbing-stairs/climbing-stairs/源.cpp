#include<iostream>

using namespace std;

int climbStaris(int n){
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 2;
	}

	return climbStaris(n - 1) + climbStaris(n - 2);
}

void main(){
	cout<<climbStaris(3)<<endl;
	system("pause");
}