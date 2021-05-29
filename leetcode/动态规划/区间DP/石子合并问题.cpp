/*

设有N堆石子排成一排，其编号为1，2，3，…，N。

每堆石子有一定的质量，可以用一个整数来描述，现在要将这N堆石子合并成为一堆。

每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。

例如有4堆石子分别为 1 3 5 2， 我们可以先合并1、2堆，代价为4，得到4 5 2， 又合并 1，2堆，代价为9，得到9 2 ，再合并得到11，总代价为4+9+11=24；

如果第二步是先合并2，3堆，则代价为7，得到4 7，最后一次合并代价为11，总代价为4+7+11=22。

问题是：找出一种合理的方法，使总的代价最小，输出最小代价。

*/

#include<iostream>
#include<algorithm>
using namespace std;


/*
const int N = 310, INF = 0x3f3f3f3f;
int f[N][N];
int s[N];
int n;

int main() {
	cin >> n;
	memset(f, INF, sizeof(f));     //记得初始化
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		f[i][i] = 0;             //初始化
	}
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];

	for (int len = 2; len <= n; len++) {  //一堆石子不需要合并
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
*/