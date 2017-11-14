// 79. Word Search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

bool exist(vector<vector<char>>& board, int y, int x, string word, int begin){
	if (begin == word.size())return true;
	if (y < 0 || x < 0 || y == word.size() || x == word[y].size()||board[y][x]=='\0')return false;
	if (board[y][x] != word[begin])return false;
	char t = board[y][x];
	board[y][x] = '\0';
	if (exist(board, y - 1, x, word, begin + 1) || exist(board, y, x-1, word, begin + 1) || exist(board, y + 1, x, word, begin + 1) || exist(board, y, x+1, word, begin + 1))
		return true;
	board[y][x] = t;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	string temp;
	vector<string> res;
	if (word.size() > board.size()*board[0].size())
		return false;
	
	for (int y = 0; y < board.size(); y++){
		for (int x = 0; x < board[y].size(); x++){
			if (exist(board, y, x, word, 0))return true;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char>> board;
	
	/*vector<char> innner1{ 'A', 'B', 'C', 'E' };
	vector<char> innner2{ 'S', 'F', 'C', 'S' };
	vector<char> innner3{ 'A', 'D', 'E', 'E' };*/

	vector<char> innner1{ 'A' };
	vector<char> innner2{ 'A' };
	board.push_back(innner1);
	board.push_back(innner2);
	//board.push_back(innner3);

	bool res = exist(board, "AA");
	system("pause");
	return 0;
}

