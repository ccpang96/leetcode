
/*
求把N*M的棋盘分割成若干个1*2的的长方形，有多少种方案。

例如当N=2，M=4时，共有5种方案。当N=2，M=3时，共有3种方案。

如下图所示：

2411_1.jpg

输入格式
输入包含多组测试用例。

每组测试用例占一行，包含两个整数N和M。

当输入用例N=0，M=0时，表示输入终止，且该用例无需处理。

输出格式
每个测试用例输出一个结果，每个结果占一行。

数据范围
1≤N,M≤11
输入样例：
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
输出样例：
1
0
1
2
3
5
144
51205

*/


/*
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 12, M = 1 << N;   //N表示的是当前列，而M表示的是当前列的所以行的状态，这里M用的是二进制表示方法
int n, m;      //矩形的行数和列数
long long  f[N][M];  //代笔当矩形的前i-1列排好之后，从i-1列捅到第i列的状态为j的方案的集合。j存储的是i-1列的哪些行伸出的小方格的状态，二进制
bool st[M];



//状态虽然是整数，但是我们将它当做一个二进制数来看
int main() {

	while (cin >> n >> m, n || m) {


		for (int i = 0; i < 1 << n; i++) {  //判断n位数能组成的2^n-1个数中，分别有多少个连续0

			st[i] = true;
			int cnt = 0;
			for (int j = 0; j < n; j++) {  //比如枚举1111的各个位数，然后计算有没有连续奇数个0
				if (i >> j & 1) { //判断第j位是否为1，如果是1，则判断前面是否有连续奇数个0
					if (cnt & 1) {
						st[i] = false;
						break;
					}
					cnt = 0;
				}
				else
					cnt++;
			}
			if (cnt & 1) st[i] = false;  //最后还要判断一下是否为0
		}
		memset(f, 0, sizeof f);  //memset也可以对一个数组赋值
		f[0][0] = 1;

		for (int i = 1; i <= m; i++)  //m是列数
			for (int j = 0; j < 1 << n; j++)  //n是行数 j是当前列伸出到下一列的
				for (int k = 0; k < 1 << n; k++) //k是前一列伸出的
					if ((j & k) == 0 && (st[j | k]))
						// j & k == 0 表示 i 列和 i - 1列同一行不同时捅出来
						// st[j | k] == 1 表示 在 i 列状态 j， i - 1 列状态 k 的情况下是合法的.
						f[i][j] += f[i - 1][k];
		cout << f[m][0] << endl;
	}

	system("pause");
	return 0;
}
*/