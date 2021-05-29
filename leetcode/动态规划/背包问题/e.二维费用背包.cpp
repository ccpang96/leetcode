/*
	有N件物品和一个容量为V的背包，背包能承受的最大重量是M。每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。
	求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。输出最大值。
*/


/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 1005;

int f[N][N];  //重量为i，体积为j的情况下，背包的最大价值
int n, v, m;  //代表物品数量、物品体积、物品重量
int cv[N], cm[N], w[N];

int main() {

	cin >> n >> v >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cv[i], &cm[i], &w[i]);
	}

	for (int i = 0; i < n; i++) { 
		for (int j = m; j >= cm[i]; j--) {  //j是重量
			for (int k = v; k >= cv[i]; k--) {  //k是体积
				f[j][k] = max(f[j][k], f[j- cm[i]][k - cv[i]] + w[i]); //重量为j时，体积为k时的背包内物品的最大价值
			}
		}
	}
	cout << f[m][v] << endl;
	system("pause");
	return 0;
}
*/