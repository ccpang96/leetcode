/*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中0~9的出现次数。
例如，a=1024，b=1032，则 a 和 b 之间共有9个数如下：
1024 1025 1026 1027 1028 1029 1030 1031 1032
其中‘0’出现10次，‘1’出现10次，‘2’出现7次，‘3’出现3次等等…

输入格式
输入包含多组测试数据。
每组测试数据占一行，包含两个整数 a 和 b。
当读入一行为0 0时，表示输入终止，且该行不作处理。

输出格式
每组数据输出一个结果，每个结果占一行。
每个结果包含十个用空格隔开的数字，第一个数字表示‘0’出现的次数，第二个数字表示‘1’出现的次数，以此类推。
数据范围
0<a,b<100000000

*/
/*
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


//求从第l位到第r位构成的数是多少
int get(vector<int>&num, int l, int r) {
	int res = 0;
	for (int i = l; i >= r; i--) {
		res = res * 10 + num[i];
	}
	return res;
}

//求10的i次方
int power10(int x) {
	int res = 1;
	while (x--) res *= 10;
	return res;
}

int count(int n, int x) {
	if (!n) return 0;  //当n= 0时，直接return 0 
	vector<int>num;
	//把n的每一位都抠出来
	while (n) {
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size(); //n等于n的位数
	int res = 0;

	for (int i = n - 1 - !x; i >= 0; i--) {  //遍历位数  最大为8  当x=0时，从第二位开始枚举
		if (i < n - 1) {  //去掉最高位
			res += get(num, n - 1, i + 1) * power10(i);  //当0<=xxx<=abc时
			if (!x) res -= power10(i); //当x==0时，注意前导0
		}
		if (num[i] == x) res += get(num, i - 1, 0) + 1;  //
		else if (num[i] > x) res += power10(i);
	}
	return res;
}


int main() {
	int a, b;
	while (cin >> a >> b, a || b) {
		if (a > b) swap(a, b);  //确保a <b

		for (int i = 0; i < 10; i++) {
			cout << count(b, i) - count(a - 1, i) << " ";
		}
		cout << endl;
	}
}

*/