/************************************************************************/
/*@File Name         : 461. 汉明距离.cpp
/*@Created Date      : 2020/7/16 15:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
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
		int n = x ^ y; //先异或求出有几个位不同\
					          
		int count = 0;
		while (n) {
			n &= n - 1;  //在求出n中1的个数
			count++;
		}
		return count;
	}
};