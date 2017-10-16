#include<iostream>

using namespace std;

int getLCA(int a, int b) {
	while (a!=1&&b!=1){
		if (a == b){
			return a;
		}
		else if (a < b){
			b = b / 2;
		}
		else{
			a = a / 2;
		}
	}
	return 1;
}

void main(){
	int a, b;
	cin >> a >>" ">> b;
	cout<<getLCA(a, b)<<endl;
	system("pause");
}

