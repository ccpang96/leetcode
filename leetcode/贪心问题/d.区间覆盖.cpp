/*
给定N个闭区间[ai,bi]以及一个线段区间[s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出-1。

*/

#include<iostream>
#include<algorithm>
using namespace std;

/*
1.将区间按照左端点从小到排序
2. 从前往后枚举每个区间，在所有能覆盖开始位置的start的区间中，选择一个右端点最大的。
3.选择完之后，将start更新为右端点的最大值

*/

/*
int n;
int result = 0;  //是可能截中最小值
const int N = 100010;

struct Range {
	int l, r;	

	bool operator<(const Range& w) const {
		return l < w.l; 
	}
}ab[N];


int main() {
	
	int st, ed;
	scanf("%d%d", &st, &ed);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ab[i].l, &ab[i].r);
	}
	
	sort(ab, ab +n);

	int res = 0;
	bool success = false;
	for (int i = 0; i < n; i++) {
		int j = i, r = -2e9;
		while (j < n&& ab[j].l <= st) {
			r = max(r, ab[j].r); //遍历左断点小于等于st的区间，寻找右断点最大的区间
			j++;
		}

		if (r < st) {  //说明右端点最大的区间的右端点都小于st，必然有空隙存在，失败
			break;
		}
		res++; 

		if (r >= ed) {  //成功找到
			success = true;
			break;
		}

		st = r;
		i = j - 1;
	}
	if (!success) res = -1;
	printf("%d\n", res);

	return 0;
}*/