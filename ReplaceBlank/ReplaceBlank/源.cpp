#include<iostream>;
using namespace std;

void ReplaceBlank(char string[],int length){//length���ַ���������ܳ�
	int num = 0;//num���ַ��������еĿո���
	int i = 0;
	int originlength = 0;//originlength���ַ��������ʵ�ʳ���
	while (string[originlength] != '\0'){
		cout << string[originlength] << " ";
		if (string[originlength] == ' '){
			num++;
		}
		originlength++;
	}

	int j = originlength + 2 * num-1 ;
	//���ո��滻���string��������2*num
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