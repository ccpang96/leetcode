/*
有 N 种物品和一个容量是 V的背包。第 i种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围

0<N,V≤100

0<vi,wi,si≤100

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2

输出样例：10
*/


//三重循环解决问题

/*
f[i] : 总体积为i的情况下，商品的最大价值f[i]

看01背包问题的板子：
for(int i = 1; i <= n; i ++) {
for(int j = m;j >= c[i]; j--)

f[j] = max(f[j],f[j-c[i]] + w[i]); //对于01背包问题我们只有两种选法 要么选要么不选，而对于多重背包我们有mi种选法

//改成下面这种方法：
f[j] = max(f[j],f[j-c[i]] + w[i], f[j- 2*c[i]] + 2* w[i],f[j- 3*c[i]] + 3* w[i],  ...)
}

//最终的结果：
1 f[i] = 0; //在这种情况下，就是不要求必须填满背包，所以最大值就是f[i]

2.f[0] = 0; f[i] = -INF;  //在这种情况下是必须填满背包
max(f[0...m])
*/


/*
//时间复杂度是n3次方
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


const int N = 105;
int n, m;
int c[N];  //c代表消耗的体积
int w[N]; //w代表利润
int s[N];  //s代表个数
int f[N];   //f代表当体积为i时，能装下的最大利润值


int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &c[i], &w[i], &s[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= c[i]; j--) {
			for (int k = 0; k <= s[i] && k*c[i] <= j; k++) {  //k*c[i] <=j 是一个小小的优化
				f[j] = max(f[j], f[j - k * c[i]] + k * w[i]);
			}
		}
	}

	cout << f[m] << endl;
	system("pause");
	return 0;
}

*/



/*
//用二进制优化
//复杂度是 n*log2(s[i]) *v
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


const int N = 2005; //代表物品的总数量
int n, m; //物品个数和背包总重量
int c[N];
int w[N];
int s[N];
int f[N];

struct Good {
	int c;
	int w;
};
int main() {

	scanf("%d%d", &n, &m); //物品数量和背包总重量

	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &c[i], &w[i], &s[i]);

	}
	vector<Good> goods;
	for (int i = 0; i <= n; i++) {
	//将s份拆成二进制份数
		for (int k = 1; k <= s[i]; k *= 2) {
			s[i] -= k;
			goods.push_back({ k*c[i],k*w[i] });
		}
		if (s[i] > 0)
			goods.push_back({ s[i] * c[i],s[i] * w[i] });
	}


	//然后用01背包问题解决
	for (auto &good : goods) {
		for (int j = m; j >= good.c; j--) {
			f[j] = max(f[j], f[j - good.c] + good.w);
		}
	}
	cout << f[m] << endl;
	return 0;

}

*/