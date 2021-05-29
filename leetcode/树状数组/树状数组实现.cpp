#include<iostream>
#include<string>
using namespace std;

/*
	//n是数组长度，m是操作次数，i是对第i个数进行加上或者减去k
	求和时间复杂度:O(mlogn)
	更新时间复杂度:O(mlog(n-i))
*/


/*
int a[10005];  //对应原来数组
int d[10005]; //对应树状数组
int n; //元素的个数

//求出二进制最后一位1的位置
int lowbit(int x) {
	return x & -x;
}

//求前x的数和
//d[14] = d[14] + d[12] +d[8]

//区间查询
int  query(int x) {
	int res = 0;
	while (x ) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

//单点更新
void update(int x, int val) {
	while (x <= n) {
		d[x] += val;
		x += lowbit(x);
	}
}

int main() {
	
	int t;
	cin >> t;
	for (int tot = 1; tot <= t; tot++) {
		cout << "case:" << tot  << endl;
		memset(a, 0, sizeof a);
		memset(d, 0, sizeof d);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			update(i, a[i]);  //输入也是更新的过程
		}

		cout << "输出树状数组：";
		for (int i = 1; i <= n; i++)
			cout << d[i] << " ";
		cout << endl;


		string s;
		int x, y;
		while (cin >> s && s[0] != 'e') {
			//查询操作
			cin >> x >> y;
			if (s[0] == 'Q') {
				int sum = query(y) - query(x - 1);
				cout << sum << endl;
			}
			else if (s[0] == 'A') { //加上
				update(x, y);
			}
			else if (s[0] == 'S') { //减去
				update(x, -y);
			}
		}

	}
	system("pause");
	return 0;
}*/