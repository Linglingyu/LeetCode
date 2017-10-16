/*fibonacci数列，不用递归的解法*/
#include<iostream>

using namespace std;

long long Fibonacci(unsigned n){
	if (n == 0)return 0;
	if (n == 1)return 1;

	long long fibone = 0;
	long long fibtwo = 1;
	long long fibn = 0;
	for (unsigned int i = 1; i < n; i++){
		fibn = fibone + fibtwo;
		fibone = fibtwo;
		fibtwo = fibn;
	}
	return fibn;
}

void main(){
	long long res;
	unsigned ind = 100;
	res = Fibonacci(ind);
	cout << res << endl;
	system("pause");
}