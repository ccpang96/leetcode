
/*
有 N 种物品和一个容量是 V的背包，每种物品都有无限件可用。
第i种物品的体积是 vi，价值是 wi
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N行，每行两个整数 vi,wi，用空格隔开，分别表示第 i种物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
数据范围

0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5

输出样例：
10

*/


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;



const int N = 1005;
int n, m;
int c[N];
int w[N];
int f[N];  //总体积为i的情况下，最大价值是多少 不要求恰好装满，如果要求恰好装满，那么只有f[0] = 0,才是合法状态，其他都要初始化为负无穷


int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i], &w[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = c[i]; j <= m; j++) {
			f[j] = max(f[j], f[j - c[i]] + w[i]);
		}
	}

	cout << f[m] << endl;
	return 0;
}*/