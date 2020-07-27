/************************************************************************/
/*@File Name         : ac89.求快速幂的方法.cpp
/*@Created Date      : 2020/7/25 10:17
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :三个整数 a,b,p,在同一行用空格隔开。
输出格式：输出一个整数，表示a^b mod p的值。
/************************************************************************/


#include<iostream>
using namespace std;


//int main() {
//
//	int a, b, p;
//	cin >> a >> b >> p;
//
//	int res = 1 % p;
//	while (b) {
//		if (b & 1) 
//			res = res * 1ll * a %p;
//		a = a * 1ll * a %p;
//		b >>= 1;
//	}
//
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}
