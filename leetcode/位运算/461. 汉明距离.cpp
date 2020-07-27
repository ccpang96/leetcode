/************************************************************************/
/*@File Name         : 461. ��������.cpp
/*@Created Date      : 2020/7/16 15:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
/************************************************************************/



#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 

class Solution {
public:
	int hammingDistance(int x, int y) {
		int n = x ^ y; //���������м���λ��ͬ\
					          
		int count = 0;
		while (n) {
			n &= n - 1;  //�����n��1�ĸ���
			count++;
		}
		return count;
	}
};