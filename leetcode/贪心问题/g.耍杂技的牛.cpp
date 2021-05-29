/*
	
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int>PII;
const int  N = 50010;

int n;
PII cow[N];


int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int w, s; //w是重量、s是强壮值
		scanf("%d%d", &w, &s);
		cow[i] = { w + s,s };
	}

	sort(cow, cow + n);  //默认按照第一个数排序


	int res = -2e9, sum = 0;

	for (int i = 0; i < n; i++) {
		int s = cow[i].second, w = cow[i].first - s;
		res = max(res, sum - s);
		sum += w;
	}
	cout << res << endl;
	return 0;
}*/