// 733. Flood Fill.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<stack>

using namespace std;

struct cord{
	int x;
	int y;
	cord(int x, int y) :x(x), y(y){};
};

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	vector<vector<int>> visited;
	for (int i = 0; i < image.size(); i++){
		vector<int> temp;
		for (int j = 0; j < image[0].size(); j++){
			temp.push_back(0);
		}
		visited.push_back(temp);
	}

	int color = image[sr][sc];
	cord cur = cord(sr, sc);
	stack<cord> cordstack;
	cordstack.push(cur);
	while (!cordstack.empty())
	{
		cord cur = cordstack.top();
		cordstack.pop();
		image[cur.x][cur.y] = newColor;
		visited[cur.x][cur.y] = 1;
		if ((cur.y>0)&&(image[cur.x][cur.y - 1] == color)&&(visited[cur.x][cur.y-1]==0)){//左
			cord temp = cord(cur.x, cur.y - 1);
			cordstack.push(temp);
		}
		if (((cur.x + 1)<image.size()) && (image[cur.x + 1][cur.y] == color) && (visited[cur.x+1][cur.y] == 0)){//下
			cord temp = cord(cur.x+1, cur.y);
			cordstack.push(temp);
		}
		if ((cur.y + 1<image[0].size()) && (image[cur.x][cur.y + 1] == color) && (visited[cur.x][cur.y+1] == 0)){//右
			cord temp = cord(cur.x, cur.y + 1);
			cordstack.push(temp);
		}
		if ((cur.x>0) && (image[cur.x - 1][cur.y] == color) && (visited[cur.x-1][cur.y] == 0)){//上
			cord temp = cord(cur.x-1, cur.y);
			cordstack.push(temp);
		}
	}
	return image;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> image;
	vector<int> a{ 0, 0, 0 };
	vector<int> b{ 0, 1, 1 };
	//vector<int> c{ 1, 0, 1 };
	image.push_back(a);
	image.push_back(b);
	//image.push_back(c);
	vector<vector<int>>res = floodFill(image, 1, 1, 1);
	system("pause");
	return 0;
}

