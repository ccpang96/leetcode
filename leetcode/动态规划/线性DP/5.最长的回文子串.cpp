/*
	求最长的回文子串
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

class Solution {
public:
	string longestPalindrome(string &s) {
		if (s.empty())
			return s;
		int len = s.size();
		string result = "";
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		for (int l = 0; l < len; l++) {  //枚举长度
			for (int i = 0; i + l < s.size(); i++) {
				int j = i + l;
				if (l == 0)   //说明是单个字符
					dp[i][j] = true;
				else if (l == 1 && s[i] == s[j])
					dp[i][j] = true;
				else
					dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);  //只有内部是回文，才能确定外部是回文

				if (dp[i][j] && j - i + 1 > result.size()) {
					result = s.substr(i, j - i + 1);
				}
			}

		}
		return result;
	}
};