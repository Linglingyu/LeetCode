// 461. Hamming Distance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<math.h>
#include<algorithm>

using namespace std;

int hammingDistance(int x, int y) {
	int dis = 0;
	if (x == 0 && y == 0)return 0;

	int m = (x==0) ? 0:(log(1.0*x) / log(2.0)+1);
	int n = (y==0) ? 0: (log(1.0*y) / log(2.0)+1);
	int iter = max(m, n);
	while (iter)
	{
		if (((x >> iter) & 0x01) != ((y >> iter) & 0x01))
			dis++;
		iter--;
	}
	//比较一下最后一位
	if ((x & 0x01) != (y & 0x01))dis++;
	return dis;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = hammingDistance(1, 4);
	system("pause");
	return 0;
}

