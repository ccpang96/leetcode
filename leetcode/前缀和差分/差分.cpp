
/*
����һ������Ϊn���������С�

����������m��������ÿ������������������l, r, c����ʾ��������[l, r]֮���ÿ��������c��

����������������в���������С�
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

	//������̾����ڹ����������b
	for (int i = 1; i <= n; i++)
		insert(i, i, a[i]); 

	while (m--) {
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);  //O��1����ʱ�临�Ӷ�
	}

	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + b[i];
		cout << a[i] << " ";
	}
	cout << endl;
		

}

*/