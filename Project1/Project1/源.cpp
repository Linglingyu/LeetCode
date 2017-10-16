#include <iostream>
#include<set>
#include <stdlib.h>
#include<string>
#include <sstream>
#include<queue>
#include<math.h>
#include<stack>
#include<algorithm>
using namespace std;
vector<string> vec;
void mincut(const string& str, const set<string>& dict)
{
	int max_len = 0;
	int cnt = 0;
	int i, j;
	for (i = 0; i<str.length();){
		max_len = 0;
		for (j = i; j<str.length(); j++){
			string tmp = str.substr(i, j - i + 1);
			if (dict.find(tmp) != dict.end()){
				max_len = max(max_len, j - i + 1);
			}
		}
		if (max_len == 0){
			cout << "n/a";
			return;
		}
		vec.push_back(str.substr(i, max_len));
		cnt++;
		i = i + max_len;
	}
	for (auto it = vec.begin(); it != vec.end(); it++){
		if (it == vec.begin())
			cout << *it;
		else
			cout << " " << *it;
	}

}


int main(int argc, const char * argv[])
{
	string strS;
	string dictStr;
	int nDict;
	set<string> dict;

	cin >> strS;
	cin >> nDict;
	for (int i = 0; i < nDict; i++)
	{
		cin >> dictStr;
		dict.insert(dictStr);
	}
	mincut(strS, dict);
	system("pause");
	return 0;
}