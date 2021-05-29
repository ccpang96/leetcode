/*
有N件物品和一个容量为V的背包

物品一共有三类：
	第一类物品只能用1次（01背包）；
	第二类物品可以用无限次（完全背包）；
	第三类物品最多只能用 si次（多重背包）

每种体积是vi，价值是wi

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。
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
struct Thing {
	int kind;
	int c, w;
};

int n, m;
vector<Thing>things;
int f[N];

int main() {
	
	cin >> n >> m; //物品的种类，以及背包的容量m
	
	for (int i = 0; i < n; i++) {
		int c, w, s;
		cin >> c >> w >> s;
		if (s < 0)  things.push_back({ -1,c,w });		//01背包问题
		else if (s == 0) things.push_back({ 0,c,w });	//完全背包问题
		else {  //分组背包通过二进制分解成logs个01背包
			for (int k = 1; k <= s; k <<= 1) {
				things.push_back({ -1,c*k,w*k });
				s -= k;
			}
			if (s) things.push_back({ -1,c*s,w*s });
		}
	}

	for (auto &thing  : things) {
		
		if (thing.kind == 0) { //完全背包问题
			for (int j = thing.c; j <= m; j++)
				f[j] = max(f[j], f[j - thing.c] + thing.w);
		}
		else {   //01背包问题
			for (int j = m; j >= thing.c; j++)
				f[j] = max(f[j], f[j - thing.c] + thing.w);
		}
	}

	cout << f[m] << endl;

	system("pause");
	return 0;
}*/