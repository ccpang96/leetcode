/*

问法一：给定n个立方体，去组成2个塔高度相同的塔，求能组成的塔的高度的最大值是多少
问法二：网易笔试：n个物品，两个人均分，求最少扔掉的物品是多少？

例子：
输入
5
1 3 4 5 2
问法一：输出7
问法二：输出1
*/

/*
状态表示： dp[i][j]:表示读取第i个立方体时，双塔高度差为j时，较高塔的高度值
属性：max

状态划分：读取第i个物品时，有三种情况：
1.扔掉这个物品  dp[i][j] = max(dp[i-1][j],dp[i][j]
2.放在高塔上    d[i][j]  = max(dp[i-1][j-a[i]] + a[i]),dp[i][j])  j必须大于a[i]
3.放在低塔上：（1）、低塔超过高塔 （2）、低塔仍然低于高塔
dp[i][j] = max(dp[i-1][a[i] - j] +j,dp[i][j])  j < a[i]
dp[i][j] = max(dp[i-1][j+a[i]],dp[i][j])

最后返回：dp[n][0] 表示遍历完n个物品，高度差为0的情况
*/

/*
#include<iostream>
#include<algorithm>


const int N = 1010;
using namespace std;

int n;
int a[N];
int f[N][N];


int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, -0x3f, sizeof f);

	f[0][0] = 0;  //前i个木块组成的双子塔的高度为0时的木块大小

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j]);  //扔掉这个物品
			if (j >= a[i]) {  //放在高塔上
				f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i]);
			}
			if (j < a[i]) { //放在低塔上
				f[i][j] = max(f[i - 1][a[i] - j] + j, f[i][j]); //低塔超过高塔
			}
			//放在低塔上，高塔仍然超过低塔
			f[i][j] = max(f[i - 1][j + a[i]], f[i][j]);
		}
	}

	if (f[n][0] <= 0)
		cout << "Impossiable " << endl;
	else
		cout << f[n][0] << endl;

	system("pause");
	return 0;
}


*/