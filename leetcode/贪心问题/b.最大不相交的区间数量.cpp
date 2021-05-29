/*
给定N个闭区间[ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。

输出可选取区间的最大数量。

输入格式
第一行包含整数N，表示区间数。

接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示可选取区间的最大数量。

数据范围
1≤N≤105,
−109≤ai≤bi≤109
输入样例：
3
-1 1
2 4
3 5
输出样例：
2

*/

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100001;
int n;	//	区间个数

struct Range {
	int l, r;
}ab[N];


bool cmp(const Range& r1, const Range& r2) {
	return r1.r < r2.r;
}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ab[i].l, &ab[i].r);
	}

	//按照右端点大小从小到大排序
	sort(ab, ab + n, cmp);

	Range last = ab[0];
	int result = 1;
	for (int i = 1; i < n; i++) {
		if (last.r < ab[i].l) {
			result++;
			last = ab[i];
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}*/