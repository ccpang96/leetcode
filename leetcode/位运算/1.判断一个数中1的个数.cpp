#include<iostream>
using namespace std;

void  func(int i) {
	int count = 0;
	while (i) {
		i &= i - 1; //��������1��1
		count++;  //count��ֵ�ĸ���
	}
	cout << count << endl;
}

//int main() {
//	func(5);
//	system("pause");
//	return 0;
//}