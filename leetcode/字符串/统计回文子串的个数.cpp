/*
	统计一个字符串中有多少个回文子串,具有不同开始位置或结束位置的子串，即使由相同的字符组成，也会被视为不同的子串
*/

#include<string>
#include<iostream>
using namespace std;



class Solution {
public:
	int countSubstrings(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			//单点拓展
			int l = i, r = i;
			while (l >= 0 && r < s.size() && s[l--] == s[r++]) ans++;

			//两点拓展
			l = i, r = i + 1;
			while (l >= 0 && r < s.size() && s[l--] == s[r++]) ans++;


		}
		return ans;
	}

};
