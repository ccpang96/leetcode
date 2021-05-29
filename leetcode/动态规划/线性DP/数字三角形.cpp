/*
	给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5

输入格式

第一行包含整数n，表示数字三角形的层数。

接下来n行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。
输出格式

输出一个整数，表示最大的路径数字和。
数据范围

1≤n≤500
,
−10000≤三角形中的整数≤10000

输入样例：

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

输出样例：

30

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

const int N = 505, INF = 1E9;
int a[N][N]; 
int f[N][N];
int n; //代表三角形的层数

int main() {

	cin >> n;

	//如果在状态转移方程中有i-1个状态话，就从第1个开始读取
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	//初始化的时候要从i= 0初始化，并且要考虑到状态转移过程中的边界条件
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i+1; j++) {
			f[i][j] = -INF;
		}
	}
	
	//开始状态转移过程
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
	
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);  //从左上角或者右上角转移过来
		}
	}

	//然后再找出最大值

	int result = -INF;
	for (int i = 1; i <= n; i++)
		result = max(result, f[n][i]);
	cout << result << endl;
	system("pause");
	return 0;

}

*/





//也可以自底向下的DP
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

const int N = 505, INF = 1E9;
int a[N][N];
int f[N][N];
int n; //代表三角形的层数

int main() {

	cin >> n;
	//如果在状态转移方程中有i-1个状态话，就从第1个开始读取
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	//初始化的时候要从i= 0初始化，并且要考虑到状态转移过程中的边界条件
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i + 1; j++) {
			f[i][j] = -INF;
		}
	}
	for (int j = 0; j <= n + 2; j++) {
		f[n + 1][j] = 0;
 	}

	for (int i = n; i >= 1; i--)
		for (int j = i; j >= 1; j--) {
			f[i][j] = max(f[i + 1][j] + a[i][j], f[i + 1][j + 1] + a[i][j]);
		}

	cout << f[1][1] << endl;
	system("pause");
	return 0;
}
*/