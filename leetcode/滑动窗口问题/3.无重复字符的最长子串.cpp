/************************************************************************/
/*@File Name         : 3.无重复字符的最长子串.cpp
/*@Created Date      : 2020/5/18 15:28
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 
/************************************************************************/

/* Includes *************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/************************************************************************/
/*@ Problem Name         : 3.无重复字符的最长子串
/*@ Description 		 :给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*************************************************************************
/*@ Example1-Input	 	 :"abcabcbb"
/*@ Example1-Output		 :3 
/*@ Example1-Explanation : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*************************************************************************
/*@ Example1-Input	 	 :"pwwkew"
/*@ Example1-Output		 :3
/*@ Example1-Explanation :因为无重复字符的最长子串是 "wke"，所以其长度为 3。

/*@补充说明：你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
/************************************************************************/
 
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;

		int hash[256] = { 0 };  //注意此处一定要初始化

		int ans = 0;
		int l = 0;
		for (int r = 0; r < s.size(); r++) {
			hash[s[r]]++;

			//滑动左侧窗口
			while (hash[s[r]] > 1) {
				hash[s[l]]--;
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};
