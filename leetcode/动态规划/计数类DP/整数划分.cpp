/*
一个正整数n可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中n1≥n2≥…≥nk,k≥1
我们将这样的一种表示称为正整数n的一种划分。

现在给定一个正整数n，请你求出n共有多少种不同的划分方法。
输入格式
共一行，包含一个整数n。
输出格式
共一行，包含一个整数，表示总划分数量。

由于答案可能很大，输出结果请对109+7

取模。数据范围
1≤n≤1000
输入样例:
5
输出样例：
7
*/


/*

#include<iostream>
#include<algorithm>

using namespace std;

typedef unsigned long long ULL;
const int N = 1010;
const int mod = 1e9 + 7;

int f[N][N]; //当组成和为i时，恰好用掉j个数的方案数量.


			 //f[i][j]将状态分为两种：一种是最小值等于1的，一种是最小值大于1的。
			 //1.最小值小于1的，可以去掉这个1，状态用f[i-1][j-1]来表示.
			 //2.最小值大于1的，可以让集合中的每个数都减去1，状态用f[i-j][j]来表示
			 //状态转移方程：f[i][j] = f[i-1,j] + f[i-j,j]

int n;
int main() {
	cin >> n;
	f[0][0] = 1; //当和为0时，恰好用掉0个数的方案为1；
	for (int i = 1; i <= n; i++) {
		f[0][i] = 0;	//组成和为0，恰好用掉i> 0个数的方案数量为0;
		f[i][0] = 0;    //当组成和为i> 0,恰好用掉0个数的方案数量为0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
		}
	}



	//求个和
	ULL ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + f[n][i]) % mod;
	}


	cout << ans << endl;
	return 0;
}

*/