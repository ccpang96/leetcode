/************************************************************************/
/*@File Name         : 5.最长的回文子串.cpp
/*@Created Date      : 2020/6/26 9:03
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
	string longestPalindrome(string s) {

		string ans;
		vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
		for (int l = 0; l < s.size(); l++) {
			for (int i = 0; i + l < s.size(); i++) {
				int j = i + l;

				//对角线情况
				if (l == 0) {
					dp[i][j] = true;
				}
				//次对角线情况：两个字符紧紧挨着，是否是回文取决于两个字符串是否相等
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				//处理其他的
				else {
					dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]); //从对角线往右下角递推
				}


				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1); //从i
				}

			}
		}
		return ans;

	}
};


//int main() {
//	string input = "babad";
//	string result = Solution().longestPalindrome(input);
//	cout << result << endl;
//
//	system("pause");
//	return 0;
//}