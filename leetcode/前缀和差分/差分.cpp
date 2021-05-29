
/*
输入一个长度为n的整数序列。

接下来输入m个操作，每个操作包含三个整数l, r, c，表示将序列中[l, r]之间的每个数加上c。

请你输出进行完所有操作后的序列。
*/

/*
#include<iostream>

using namespace std;

const int N = 10010;

int a[N];
int b[N];

int n, m;

void insert(int l, int r, int c) {
	b[l] += c;
	b[r + 1] -= c;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	//这个过程就是在构建差分数组b
	for (int i = 1; i <= n; i++)
		insert(i, i, a[i]); 

	while (m--) {
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);  //O（1）的时间复杂度
	}

	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + b[i];
		cout << a[i] << " ";
	}
	cout << endl;
		

}

*/