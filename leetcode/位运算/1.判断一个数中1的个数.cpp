#include<iostream>
using namespace std;

void  func(int i) {
	int count = 0;
	while (i) {
		i &= i - 1; //能消除掉1个1
		count++;  //count的值的个数
	}
	cout << count << endl;
}

 