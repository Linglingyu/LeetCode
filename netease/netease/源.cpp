#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N,h[50];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> h[i];
	}
	sort(h,h+N);
	for (int i = 0; i < N; i++){
		cout<<h[i];
	}
	int tmp = 0; int max1, max2, min1, msave;
	for (int i = N; i >= 0;i=i-2){
		max1 = h[i]; max2 = h[i - 1]; min1 = h[N-i];
		tmp += (max1 - min1) + (max2 - min1);
		max1 = max(max1, msave);
		msave = min(max1, max2);
		max2 = h[i];
	}


	//int x, f, p, d;
	//cin >> x;
	//cin >> f;
	//cin >> d;
	//cin >> p;
	//if (d / x<=f){
	//	cout << d / x << endl;
	//}
	//else{
	//	cout << ( d + f*p) / (x + p) << endl;
	//}
	//

	return 0;
}