/*
给定一个R行C列的矩阵，表示一个矩形网格滑雪场。
矩阵中第 i 行第 j 列的点表示滑雪场的第 i 行第 j 列区域的高度。
一个人从滑雪场中的某个区域内出发，每次可以向上下左右任意一个方向滑动一个单位距离。
当然，一个人能够滑动到某相邻区域的前提是该区域的高度低于自己目前所在区域的高度。

下面给出一个矩阵作为例子：
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

在给定矩阵中，一条可行的滑行轨迹为24-17-2-1。
在给定矩阵中，最长的滑行轨迹为25-24-23-…-3-2-1，沿途共经过25个区域。
现在给定你一个二维矩阵表示滑雪场各区域的高度，请你找出在该滑雪场中能够完成的最长滑雪轨迹，并输出其长度(可经过最大区域数)。

*/

/*
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int  N = 310;

int f[N][N]; //所有从(i,j)点开始滑雪的路径
int h[N][N]; //高度

int n, m; //行和高度

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
int dp(int i, int j) {

	int &v = f[i][j];  //c++的特性，v代表f[x][y]
	if (v != -1) return v;  //记忆化搜索的牛逼之处在这里：用一个数组保存已经搜索过的值

	v = 1;
	for (int k = 0; k < 4; k++) {
		int a = i + dx[k], b = j + dy[k];
		if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[i][j]) {
			v = max(v, dp(a, b) + 1);
		}
	}

	return v;
}

int main() {
	int res = 0;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &h[i][j]);
		}
	}
	memset(f, -1, sizeof f); //将f置为-1

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res = max(res, dp(i, j));
		}
	}

	cout << res << endl;
	return 0;

}*/