/*
����ת��Ϊ�������ַ���  11 ����> 1011
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

//�ݹ�ⷨ
void convertToBinary(unsigned int n)
{
	if (n / 3 != 0) {
		convertToBinary(n / 3);
	}
	printf("%d", n % 3);
}


//�����ⷨ
string toBinary(int n)
{
	std::string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}

