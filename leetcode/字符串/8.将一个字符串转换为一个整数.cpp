/************************************************************************/
/*@File Name         : 8.将一个字符串转换为一个整数.cpp
/*@Created Date      : 2020/6/26 15:58
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
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
	int myAtoi(string str) {
		int minus = 1;
		long long number = 0;
		int i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '-') minus = -1;
		if (str[i] == '-' || str[i] == '+') i++;    //这种情况可以处理有两个占位符的情况

		for (; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				number = number * 10 + minus * (str[i] - '0');
				if (number < INT_MIN)
					number = INT_MIN;
				else if (number > INT_MAX)
					number = INT_MAX;
			}
			else
			{
				break;		//碰见其他的字符，即使是空格也视作错误
			}
		}
		return static_cast<int>(number);
	}
};



//int main() {
//
//	string word = "word the 123";
//	int result = Solution().myAtoi(word);
//	
//	system("pause");
//	return 0;
//}
