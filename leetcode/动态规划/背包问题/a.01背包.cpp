/*
有 N 件物品和一个容量是 V的背包。每件物品只能使用一次。

第 i件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
输入格式

第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N行，每行两个整数 vi,wi，用空格隔开，分别表示第 i件物品的体积和价值。

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
int c[N]; //花费值
int w[N]; //盈利值

int f[N][N]; //化零为整：所以只考虑前i个物品，且总体积不超过j的选法的集合 属性：是max
int n, m;  //n个物品，背包的最大容量是m

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &c[i], &w[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j]; //不拿第i个物品  化整为零：不拿第i个物品+拿第i个物品
			if (j >= c[i])
				f[i][j] = max(f[i][j], f[i - 1][j - c[i]] + w[i]);
			}
	}
	cout << f[n][m] << endl;

	return 0;
}
*/

/*
//空间优化一维
const int N = 1005;
int c[N]; //花费值
int w[N]; //盈利值

int f[N]; //化零为整：总体积不超过j的选法的集合 属性：是max
int n, m;  //n个物品，背包的最大容量是m

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &c[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= c[i]; j--) {
			f[j] = max(f[j], f[j - c[i]] + w[i]);
		}

	cout << f[m] << endl;
	return 0;
}
*/