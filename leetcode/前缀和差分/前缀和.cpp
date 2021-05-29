/*
	对于一个长度为n的序列，接下来再输入m个询问，每个询问输入一对l, r，对于每个询问，输出原序列中从第l个数到第r个数的和。
*/
/*
	时间复杂度：
	https://oi-wiki.org/basic/prefix-sum/

*/


/*
#include<cstring>
#include<iostream>
using namespace std;

const int N = 100005;
int a[N]; //原数组
int s[N]; //前缀和

int n, m;



int main() {
	scanf("%d%d", &n, &m);
	memset(s, 0, sizeof s);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	//求出前缀和
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		cout << s[y] - s[x - 1] << endl;
	}

	return 0;
}
*/
//树状数组的解法

/*
#include<iostream>

const int N = 100005;
int a[N];
int d[N];
int n, m;


int lowbit(int x) {
	return x & -x;
}

int query(int x) {
	int res = 0;
	while (x) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

void update(int i,int val,int len) {
	while (i <= len) {
		d[i] += val;
		i += lowbit(i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i], n);
	}
	 
	int x, y;
	
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		cout << query(y) - query(x - 1) << endl;
	}
	
	return 0;
}
*/

