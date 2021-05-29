/*
	有 N 件物品和一个容量是 V的背包。每件物品只能使用一次。第 i件物品的体积是 vi，价值是 wi.

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出最优选法的方案数。注意答案可能很大，请输出答案模 109+7的结果。


输入格式
第一行两个整数，N，V

，用空格隔开，分别表示物品数量和背包容积。

接下来有 N
行，每行两个整数 vi,wi，用空格隔开，分别表示第 i

件物品的体积和价值。
输出格式

输出一个整数，表示 方案数 模 109+7

的结果。
数据范围

0<N,V≤1000

0<vi,wi≤1000

输入样例

4 5
1 2
2 4
3 4
4 6

输出样例：

2

*/



/*
#include<iostream>
#include<algorithm>
using namespace std;



const int N = 100010,INF = 0x3f3f3f3f,mod = 1e9 + 7;

int c[N]; //存储体积值
int w[N]; //存储物品价值

int n, m; //物品个数和物品价值


int f[N]; //当体积为j时的最大价值  
int g[N]; //体积是j的情况下，它的方案数是多少


//由于我们要输出最大方案数，所以f[0]不能简单的初始化为0，因为我们要求的是体积恰好是j的情况下的最大价值，要输出这个方案数





int main() {
	cin >> n >> m;

	g[0] = 1; //当体积为0时，方案数只有一种
	for (int i = 1; i <= m; i++)
		f[i] = -INF;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i], &w[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= c[i]; j--) {
			
			int t = max(f[j], f[j - c[i]] + w[i]);
			int s = 0;
			if (t == f[j]) s += g[j];
			if(t == f[j- c[i]] + w[i])  s += g[j - c[i]]; //体积为j-c[i]的方案数
			if (s >= mod) s -= mod;
			f[j] = t;
			g[j] = s;
		}
	}

	int maxw = -INF;
	for (int j = 0; j <= m; j++) maxw = max(maxw, f[j]);
	int result = 0; //最优的方案数: 最优方案数可能对应多个不同体积：比如f[10]和f[8]都是最优方案
	for (int j = 0; j <= m; j++) {
		if (f[j] == maxw)
			result += g[j];
		if (result >= mod) result -= mod;
	}
	cout << result << endl;
}*/