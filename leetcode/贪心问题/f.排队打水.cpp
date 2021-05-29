/*
有 n 个人排队到 1 个水龙头处打水，第 i 个人装满水桶所需的时间是 ti，请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？
输入格式
	第一行包含整数 n。第二行包含 n个整数，其中第 i 个整数表示第 i 个人装满水桶所花费的时间 ti。
输出格式
输出一个整数，表示最小的等待时间之和。

数据范围
1≤n≤105,1≤ti≤104

输入样例：
7
3 6 1 4 2 5 7

输出样例：
56
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
int t[N];

typedef long long LL;

bool cmp(int a, int b) {
	return a < b;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);

	sort(t, t + n,cmp); //先从小到大排序

	LL result = 0;  
	for (int i = 0; i < n; i++) {  //加上时间
		result += t[i] * (n -1-i);
	}

	cout << result << endl;
	return 0;
}*/
