#include<iostream>
#include<string>
using namespace std;

/*
	//n�����鳤�ȣ�m�ǲ���������i�ǶԵ�i�������м��ϻ��߼�ȥk
	���ʱ�临�Ӷ�:O(mlogn)
	����ʱ�临�Ӷ�:O(mlog(n-i))
*/


/*
int a[10005];  //��Ӧԭ������
int d[10005]; //��Ӧ��״����
int n; //Ԫ�صĸ���

//������������һλ1��λ��
int lowbit(int x) {
	return x & -x;
}

//��ǰx������
//d[14] = d[14] + d[12] +d[8]

//�����ѯ
int  query(int x) {
	int res = 0;
	while (x ) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

//�������
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
			update(i, a[i]);  //����Ҳ�Ǹ��µĹ���
		}

		cout << "�����״���飺";
		for (int i = 1; i <= n; i++)
			cout << d[i] << " ";
		cout << endl;


		string s;
		int x, y;
		while (cin >> s && s[0] != 'e') {
			//��ѯ����
			cin >> x >> y;
			if (s[0] == 'Q') {
				int sum = query(y) - query(x - 1);
				cout << sum << endl;
			}
			else if (s[0] == 'A') { //����
				update(x, y);
			}
			else if (s[0] == 'S') { //��ȥ
				update(x, -y);
			}
		}

	}
	system("pause");
	return 0;
}*/