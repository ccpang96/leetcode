/*
题目：	
	给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。  //这个数字也可以改成字符串
输入格式
	第一行包含整数N。
	第二行包含N个整数，表示完整序列。
输出格式
	输出一个整数，表示最大长度。
数据范围
	1≤N≤1000，−109≤数列中的数≤109
输入样例：
	7
	3 1 2 1 8 5 6
输出样例：
	4
*/

/*
问法一：求最长的上升子序列的长度
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
int a[N]; 
int f[N]; //代表以字符i结尾的上升子序列
int g[N]; //记录从哪个状态转移过来的
int n; //代表数的个数
int main() {
	
	cin >> n; 

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {

		f[i] = 1;
		for (int j = i - 1; j >=1; j--) {

			if (a[j] < a[i]) {

				// f[i] = max(f[i],f[j] +1);
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					g[i] = j;  //记录的是第i个字符是由哪个字符转移过来的
				}
				
			}
		}
	}
	


	//再从0~n中选择一个最大的
	
	//int result = -1e9;
	//for (int i = 1; i <= n; i++)
	//	result = max(result, f[i]);
	//cout << result << endl;


	int k = 1;
	for (int i = 1; i <= n; i++)
		if (f[k] < f[i])
			k = i; //最大
	
	printf("%d\n", f[k]); //最大的值

	for (int i = 0, len = f[k]; i < len; i++) {
		printf("%d ", a[k]);
		k = g[k]; //第i个字符是从g[k]转过来的
	}

	system("pause");
	return 0;
}

/*
	问法二：求最长上升子序列的序列
*/


