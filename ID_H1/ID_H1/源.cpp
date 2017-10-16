#include<iostream>
 
using namespace std;

void main(){
	int N, K;
	cin >> N >> K;
	int id=0;

	//for (int i = 0; i <= K; i++){
	//	for (int j = 0; j <= K; j++){
	//		id = i * 10 + j;
	//		cout << id << endl;
	//	}
	//}
	int j = 0;
	int temp = 0;
	int temp2 = 0;
	int temp3 = 0;
	for (id = pow(10,(N-1)); id < pow(10, N); id++){
		temp = id;
		for (j = 0; j < N; j++){
			temp2 = temp % 10;
			temp = temp / 10;
			temp3 = temp % 10;
			if (temp2 > K){
				break;
			}
			if (temp2*temp3 > K){
				break;
			}
		}
		if (j == N){
			cout << id << endl;
		}
	}

	system("pause");
}