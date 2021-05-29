/*
	给定两个长度分别是N和M的字符串A和B，求既是A的子序列又是B的子序列的长度分别是多少？

	第一行包含两个整数N和M。

	第二行包含一个长度为N的字符串，表示字符串A。

	第三行包含一个长度为M的字符串，表示字符串B。

	字符串均由小写字母构成

	1≤N,M≤1000

	输入样例：
	4 5
	acbd
	abedc
	输出样例：
	3
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
int n, m;
char s[N];
char w[N];
int f[N][N]; //在第一个字符串的前i个字符中出现且在第二个字符串的前j个字符中出现的子串
			 //属性是子串的长度
int main() {

	cin >> n >> m;
	scanf("%s%s", s + 1, w + 1);   //从第s+1和w+1个字符开始读取

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]); //分别是最长子串不包含a[i]和b[j]、包含a[i]但是不包含b[j]、包含b[j]但是不包含a[i]、包含a[i]和b[j]
			if (s[i] == w[j])
				f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
		}
	}

	cout << f[n][m] << endl;
	system("pause");
	return 0;
}
*/