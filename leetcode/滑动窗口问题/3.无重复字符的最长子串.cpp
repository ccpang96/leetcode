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
 
int lengthOfLongestSubstring(string s) {
	//输入参数有效性判断
	if (s.size() <= 0)
		return 0;

	//申请一个散列表，用于存储窗口中元素的个数，本题是关于字符串的种类问题，所以开辟一个大小为256的数组
	int hash[256] = { 0 };

	int l = 0; //表示左指针
	int count = 0; //记录右指针指向字符出现的次数
	int result = 1; //最终的结果

	for (int r = 0; r < s.size(); r++) {
		//更新元素在hash表中出现的数量
		hash[s[r]]++;

		
		//如果条件不满足，则移动左指针直到条件满足
		while (hash[s[r]] != 1) { //  [5/18/2020 Administrator]
			hash[s[l]]--;
			l++;
		}
		//更新结果
		result = max(result, r - l + 1);
	}
	return result;
}