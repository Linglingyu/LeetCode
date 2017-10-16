#include <stdio.h>
#include <stack>

using namespace std;

void calc_f(int n){
	int res = 0;
	stack<int> temp;
	temp.push(n);
	while (!temp.empty()){
		int t = temp.top();
		temp.pop();
		if (t >= 1024){
			temp.push(t-1);
			temp.push(t - 1024);
		}
		else{
			res++;
		}
	}
	printf("%d", res);
}

void main(){
	calc_f(2048);
	system("pause");
}