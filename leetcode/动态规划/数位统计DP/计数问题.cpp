/*
������������ a �� b���� a �� b ֮�������������0~9�ĳ��ִ�����
���磬a=1024��b=1032���� a �� b ֮�乲��9�������£�
1024 1025 1026 1027 1028 1029 1030 1031 1032
���С�0������10�Σ���1������10�Σ���2������7�Σ���3������3�εȵȡ�

�����ʽ
�����������������ݡ�
ÿ���������ռһ�У������������� a �� b��
������һ��Ϊ0 0ʱ����ʾ������ֹ���Ҹ��в�������

�����ʽ
ÿ���������һ�������ÿ�����ռһ�С�
ÿ���������ʮ���ÿո���������֣���һ�����ֱ�ʾ��0�����ֵĴ������ڶ������ֱ�ʾ��1�����ֵĴ������Դ����ơ�
���ݷ�Χ
0<a,b<100000000

*/
/*
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


//��ӵ�lλ����rλ���ɵ����Ƕ���
int get(vector<int>&num, int l, int r) {
	int res = 0;
	for (int i = l; i >= r; i--) {
		res = res * 10 + num[i];
	}
	return res;
}

//��10��i�η�
int power10(int x) {
	int res = 1;
	while (x--) res *= 10;
	return res;
}

int count(int n, int x) {
	if (!n) return 0;  //��n= 0ʱ��ֱ��return 0 
	vector<int>num;
	//��n��ÿһλ���ٳ���
	while (n) {
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size(); //n����n��λ��
	int res = 0;

	for (int i = n - 1 - !x; i >= 0; i--) {  //����λ��  ���Ϊ8  ��x=0ʱ���ӵڶ�λ��ʼö��
		if (i < n - 1) {  //ȥ�����λ
			res += get(num, n - 1, i + 1) * power10(i);  //��0<=xxx<=abcʱ
			if (!x) res -= power10(i); //��x==0ʱ��ע��ǰ��0
		}
		if (num[i] == x) res += get(num, i - 1, 0) + 1;  //
		else if (num[i] > x) res += power10(i);
	}
	return res;
}


int main() {
	int a, b;
	while (cin >> a >> b, a || b) {
		if (a > b) swap(a, b);  //ȷ��a <b

		for (int i = 0; i < 10; i++) {
			cout << count(b, i) - count(a - 1, i) << " ";
		}
		cout << endl;
	}
}

*/