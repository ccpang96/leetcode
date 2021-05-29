

/*

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
		int flag = 1;
		int i = 0;
		long long  result = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			flag = -1;  //ÊÇ¸ºÊý
		if (str[i] == '+' || str[i] == '-')
			i++;

		while (i < str.size()) {
			if (isdigit(str[i])) {
				result = result * 10 + flag * (str[i] - '0');
				i++;
				if (result > INT_MAX)
					result = INT_MAX;
				if (result < INT_MIN)
					result = INT_MIN;
			}
			else
				break;
		}
		return static_cast<int>(result);
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
*/