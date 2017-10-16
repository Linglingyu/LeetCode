#include<iostream>;
using namespace std;

void ReplaceBlank(char string[],int length){//length是字符串数组的总长
	int num = 0;//num是字符串数组中的空格数
	int i = 0;
	int originlength = 0;//originlength是字符串数组的实际长度
	while (string[originlength] != '\0'){
		cout << string[originlength] << " ";
		if (string[originlength] == ' '){
			num++;
		}
		originlength++;
	}

	int j = originlength + 2 * num-1 ;
	//将空格替换后的string长度增加2*num
	for (i = originlength - 1; i >= 0; i--){
		if (string[i] == ' '){
			//cout<<string[i];
			string[j] = '0';
			string[j - 1] = '2';
			string[j - 2] = '%';
			j = j - 3;
		}
		else{
			string[j] = string[i];
			cout << string[j] << endl;
			j = j - 1;
		}
	}
	for (int k = 0; k < originlength + 2 * num; k++){
		cout << string[k] << " ";
	}
}

#define len 20
void main(){
	//int len = 20;
	char string[len] = { 'w', 'e', ' ', 'a', 'r', 'e', ' ', 'h', 'a', 'p', 'p', 'y', '.', '\0' };
	ReplaceBlank(string, len);
}