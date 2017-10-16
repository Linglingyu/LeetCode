// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//nvida 编程01
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*int T;
	cin >> T;
	map<string, int> m;
	while (T--){
		string str;
		cin >> str;
		if (str == "?"){
			string s1;
			cin >> s1;
			cout << m[s1] << endl;
		}
		else{
			string s2;
			string s3;
			cin >> s2 >> s3;
			if (s3[0] < '0' || s3[0] > '9'){
				m[str] = m[s3];
				cout << m[str] << endl;
			}
			else{
				int n = stoi(s3);
				m[str] = n;
				cout << n << endl;
			}
		}
	}*/

	string s;
	cin >> s;
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
		*it = toupper(*it);
	}
	cout << s<< endl;

	/*map<int,int> ss;
	ss[0]=6;
	ss[10]=10;
	ss[5]=3; 
	for (auto it : ss){
		cout << it.first <<it.second<<endl;
	}*/

	system("pause");
	return 0;
}

