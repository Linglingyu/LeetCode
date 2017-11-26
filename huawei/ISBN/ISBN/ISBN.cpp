// ISBN.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

bool isnum(char ch){
	if ((ch > 47) && (ch < 58)){
		return true;
	}
	else{
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<char> res;
	int sum = 0;
	char lan;
	cin >> lan;
	if (!isnum(lan)){
		cout << "ERROR";
		return -1;
	}
	sum += lan - 48;
	//cout << sum;
	char depara1;
	cin >> depara1;
	if (depara1 != '-'){
		cout << "ERROR";
		return -1;
	}
	char pub0, pub1, pub2;
	cin >> pub0 >> pub1 >> pub2;
	if (!(isnum(pub0) && isnum(pub1) && isnum(pub2))){
		cout << "ERROR";
		return -1;
	}
	sum += (pub0 - 48)*2;
	sum += (pub1 - 48)*3;
	sum += (pub2 - 48)*4;

	char depara2;
	cin >> depara2;
	if (depara2 != '-'){
		cout << "ERROR";
		return -1;
	}

	char book0, book1, book2, book3, book4;
	cin >> book0 >> book1 >> book2 >> book3 >> book4;
	if (!(isnum(book0) && isnum(book1) && isnum(book2) && isnum(book3) && isnum(book4))){
		cout << "ERROR";
		return -1;
	}
	sum += (book0 - 48)*5;
	sum += (book1 - 48)*6;
	sum += (book2 - 48)*7;
	sum += (book3 - 48)*8;
	sum += (book4 - 48)*9;

	sum = sum % 11;

	res.push_back(lan);
	res.push_back(depara1);
	res.push_back(pub0);
	res.push_back(pub1);
	res.push_back(pub2);
	res.push_back(depara2);
	res.push_back(book0);
	res.push_back(book1);
	res.push_back(book2);
	res.push_back(book3);
	res.push_back(book4);
	res.push_back('-');
	//char temp = (char)sum;
	//cout << temp << endl;
	if (sum == 10){
		res.push_back('X');
	}
	else{
		res.push_back(sum+48);
	}
	for (auto i : res){
		cout << i;
	}
	system("pause");
	return 0;
}

