/*
	给定N个闭区间[ai,bi

	]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

	输出最小组数。
	输入格式

	第一行包含整数N，表示区间数。

	接下来N行，每行包含两个整数ai,bi

	，表示一个区间的两个端点。
	输出格式

	输出一个整数，表示最小组数。
	数据范围

	1≤N≤105
	,
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
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;
int n; //区间个数


struct Range {
	int l, r;
	bool operator< (const Range &w) {
		return l < w.l;
	}

}ab[N];

int  main() {

	cin >> n; 

	for (int i = 0; i < n; i++)
		scanf("%d %d", &ab[i].l, &ab[i].r);

	sort(ab, ab + n);

	priority_queue<int, vector<int>, greater<int>>heap; //小根堆  堆中保存的是分组的右端点的值

	for (int i = 0; i < n; i++) {
		auto r = ab[i];
		if (heap.empty() || heap.top() >= r.l) //所有组中的右端点的最小值
			heap.push(r.r); // 新开一个组
		else {
			//int t = heap.top();
			heap.pop();
			heap.push(r.r);
		}
	}
	cout << heap.size() << endl;
	return 0;
}*/