/*
	����Ļ����Ӵ�
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
		for (int l = 0; l < len; l++) {  //ö�ٳ���
			for (int i = 0; i + l < s.size(); i++) {
				int j = i + l;
				if (l == 0)   //˵���ǵ����ַ�
					dp[i][j] = true;
				else if (l == 1 && s[i] == s[j])
					dp[i][j] = true;
				else
					dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);  //ֻ���ڲ��ǻ��ģ�����ȷ���ⲿ�ǻ���

				if (dp[i][j] && j - i + 1 > result.size()) {
					result = s.substr(i, j - i + 1);
				}
			}

		}
		return result;
	}
};