/*
有 N 组物品和一个容量是 V的背包。每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i 是组号，j是组内编号。求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

输出最大价值。

输入格式

第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。

接下来有 N组数据：每组数据第一行有一个整数 Si，表示第 i个物品组的物品数量；
每组数据接下来有 Si行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i 个物品组的第 j个物品的体积和价值；

输出格式

输出一个整数，表示最大价值。
数据范围

0<N,V≤100
0<Si≤100
0<vij,wij≤100


输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5

输出样例：
8
*/


//同样的思路：第i组要么不选，要么选第i组物品中的第k个物品


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


const int N = 110;
int c[N][N], w[N][N], s[N]; //c:第i组中物品j的重量； w:第i组中物品j的价值; s:第i组中的物品数量
int f[N]; //当装入第i组物品时，物品的最大价值


int n, m;

int main() {
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s[i]; //代表第i组中物品的种类
		for (int j = 0; j < s[i]; j++) {
			cin >> c[i][j] >> w[i][j];
		}
	}

	//从前往回枚举n件物品
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) { //容量为j时
			for (int k = 0; k < s[i]; k++) {
				if (c[i][k] <= j) {
					f[j] = max(f[j], f[j - c[i][k]] + w[i][k]);
				}
			}
		}
	}
	cout << f[m] << endl;
	system("pause");
	return 0;
}





*/