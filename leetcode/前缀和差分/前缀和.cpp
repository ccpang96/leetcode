/*
	����һ������Ϊn�����У�������������m��ѯ�ʣ�ÿ��ѯ������һ��l, r������ÿ��ѯ�ʣ����ԭ�����дӵ�l��������r�����ĺ͡�
*/
/*
	ʱ�临�Ӷȣ�
	https://oi-wiki.org/basic/prefix-sum/

*/


/*
#include<cstring>
#include<iostream>
using namespace std;

const int N = 100005;
int a[N]; //ԭ����
int s[N]; //ǰ׺��

int n, m;



int main() {
	scanf("%d%d", &n, &m);
	memset(s, 0, sizeof s);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	//���ǰ׺��
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
//��״����Ľⷨ

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

