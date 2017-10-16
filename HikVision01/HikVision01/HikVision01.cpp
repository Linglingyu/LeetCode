// HikVision01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool AllisNum(string str){
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		 }
		}
	return true;
}

bool AllisChar(string str){
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 65 && tmp <= 90)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool AllisCharLittle(string str){
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 97 && tmp <= 122)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool AllisSpecial(string str){
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 97 && tmp <= 122 && tmp >= 65 && tmp <= 90 && tmp >= 48 && tmp <= 57)
		{
			return false;
		}
		else
		{
			continue;
	
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string usrname,password;
	cin >> usrname >> password;
	string password_inv = password;
	reverse(password_inv.begin(), password_inv.end());
	if (password.length() < 8){
		cout << 0 << endl;
		return 0;
	}
	if (!password.compare(usrname)){
		cout << 0 << endl;
		return 0;
	}
	if (!password_inv.compare(usrname)){
		cout << 0 << endl;
		return 0;
	}
	if (AllisSpecial(password)){
		cout << 0 << endl;
		return 0;
	}
	if (AllisChar(password)){
		cout << 0 << endl;
		return 0;
	}
	if (AllisNum(password)){
		cout << 0 << endl;
		return 0;
	}
	if (AllisCharLittle(password)){
		cout << 0 << endl;
		return 0;
	}

	return 0;
}

