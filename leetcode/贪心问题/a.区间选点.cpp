/*
给定N个闭区间[ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。

输出选择的点的最小数量。

位于区间端点上的点也算作区间内。

输入格式
第一行包含整数N，表示区间数。

接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需的点的最小数量。

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




//1.将每个区间按照右端点按照从小到大排序
//2.从前往后依次枚举每个区间，如果当前区间已经包含点，则直接pass，否则直接选择最右侧的点。



/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100005, INF = 0x3f3f3f3f;
int n;


struct Range {
	int l, r;

}ab[N];

bool cmp(const Range & a, const Range &b) {
	return a.r < b.r;
}

int main() {

	cin >> n;
	 
	for (int i = 0; i < n; i++)
		cin >> ab[i].l >> ab[i].r;
	 
	sort(ab, ab + n, cmp);

	int result = 0;
	int right_value = -INF;
	for (int i = 0; i < n; i++) {
		if (right_value > ab[i].r || right_value < ab[i].l) {  //说明不在区间内
			result++;
			right_value = ab[i].r; //将右区间端点附给right_value
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}

*/