// 64. Minimum Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	vector<vector<int>> dp;
	for (int i = 0; i < grid.size(); i++){
		vector<int> temp(grid[0].size(), 0);
		dp.push_back(temp);
	}
	for (int i = 0; i < grid.size(); i++){
		for (int j = 0; j < grid[0].size(); j++){
			if (i == 0 && j == 0){ 
				dp[i][j] = grid[i][j]; 
				continue;
			}
			if (i == 0){ 
				dp[i][j] = dp[i][j - 1] + grid[i][j]; 
				continue;
			}
			if (j == 0){
				dp[i][j] = dp[i - 1][j] + grid[i][j];
				continue;
			}
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
	return dp[grid.size()-1][grid[0].size()-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> grid;
	vector<int> line1{ 1, 3, 1 };
	vector<int> line2{ 1, 5, 1 };
	vector<int> line3{ 4, 2, 1 };
	grid.push_back(line1);
	grid.push_back(line2);
	grid.push_back(line3);
	int res = minPathSum(grid);
	system("pause");
	return 0;
}

