#include<string>
#include<iostream>

using namespace std;

void main(){
	int N;
	cin >> N;
	string *s;
	s = new string[N];
	for (int i = 0; i < N; i++){
		cin >> s[i];
	}
	//for (int j = 0; j < N; j++){
	//	cout << s[j] << endl;
	//}

	char c = '/';
	char *t = "-";
	int pos=0;
	int new_pos = 0;
	int new_pos_last = 0;
	int s_len = 0;//拷贝的字符串的长度
	int c_len = 0;
	string *s_new = new string[N];
	char c_new[10000];
	for (int j = 0; j < N; j++){
//		cout << s[j] << endl;
		new_pos=s[j].find(c, pos + 1);
		//cout << new_pos << endl;
		s_len = s[j].copy(c_new, new_pos, 0);
		c_len = s_len;
		while (new_pos != -1){
			new_pos_last = s[j].find(c, new_pos+1);
//			cout << new_pos_last << " ";
			s_len = s[j].copy(c_new + c_len, new_pos_last - new_pos, new_pos);

			strcat(c_new, t);
			c_len = c_len + s_len + 1;
			//c_new[new_pos_last - new_pos] = "-";
			new_pos = new_pos_last;

		}
		for (int k = 0; k < c_len; k++){
			cout << c_new[k];
		}
		//cout << s_len<<" ";
		



	}
	system("pause");
}