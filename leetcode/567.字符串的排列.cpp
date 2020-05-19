/************************************************************************/
/*@File Name         : 567.字符串的排列.cpp
/*@Created Date      : 2020/5/19 17:09
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/

/************************************************************************/
/*@ Problem Name         : 567.字符串的排列
/*@ Description 		 :给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。


*************************************************************************
/*@ Example1-Input	 	 :s1 = "ab" s2 = "eidbaooo"
/*@ Example1-Output		 :True
/*@ Example1-Explanation : s2 包含 s1 的排列之一 ("ba").
*************************************************************************
/*@ Example1-Input	 	 :s1= "ab" s2 = "eidboaoo"
/*@ Example1-Output		 : False
/*@ Example1-Explanation :

/*@补充说明：//此题窗口不变，刚好等于s1的大小
/************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2) {

	//输入参数有效性判断
	if (s2.size() < s1.size() || s2.size() == 0 || s1.size() == 0)
		return false;


	int hash[256] = { 0 };
	
	for (int i = 0; i < s1.size(); i++) {
		hash[s1[i]]++;
	}

	int l = 0;		//左窗口
	int count = 0; //匹配的个数
	int found = false; //最终结果

	for (int r = 0; r < s2.size(); r++) {
		hash[s2[r]]--;	

		if (hash[s2[r]] >= 0)  //成功对消s1中的字符,匹配成功一个
			count++;

		//由于此题的窗口不变，是刚好等于s1.size()，所以要在r > s1.size()-1时，就要挪动左指针
		if (r > s1.size() - 1) {
			hash[s2[l]]++;	

			if (hash[s2[l]] > 0)  //如果大于0，说明这个元素是s2中的，则说明这个元素的匹配是不对的
				count--;	//所以让count--
			l++;
		}

		if (count == s1.size()) {
			found = true;
		}
	}
	return found;
}