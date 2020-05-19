/************************************************************************/
/*@File Name         : 76. 最小覆盖子串.cpp
/*@Created Date      : 2020/5/18 17:43
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

#include<iostream>
#include<vector>
using namespace std;



/************************************************************************/
/*@ Problem Name         : 76. 最小覆盖子串
/*@ Description 		 :给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。


*************************************************************************
/*@ Example1-Input	 	 :	S = "ADOBECODEBANC", T = "ABC"
/*@ Example1-Output		 :	"BANC"
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
/************************************************************************/

/************************************************************************/
/*@FullName:  minWindow
/*@Brief:     在S中找到包含T的所有字符的最短字符串 ，这个窗口是变化的
/*@Parameter: s : 主串，t : 模式串
/*@Returns:   string : 包含了t中所有字符的s中最短的字符串
/*@time:      2020/5/18 17:45
/*@author:    ccpang
/************************************************************************/
string minWindow(string s, string t) {

	//输入参数有效性判断
	if (t.size() <= 0 || s.size() <= 0 || s.size() < t.size())
		return "";
	

	int hash[256] = { 0 };
	for (int i = 0; i < t.size(); i++)
		hash[t[i]]++;		//将模式串中的字母加入hash表

	int l = 0, count = t.size(), max = s.size() + 1;
	string result;
	
	for (int r = 0; r < s.size(); r++) {
		hash[s[r]]--;	//遍历主串s，去对消hash表中的t的元素

		if (hash[s[r]] >= 0)	//匹配上一个
			count--;


		while (l < r && hash[s[l]] < 0) { //将那些减为-1的元素再加上来
			hash[s[l]]++; 
			l++;		//左移窗口
		}

		//更新结果：只有新的窗口的长度比max小，才有机会更新
		if (count == 0 && r - l + 1 < max) { //如果count ==0 ,说明刚好t中的字符全部匹配
			max = r - l + 1;
			result = s.substr(l, r -l + 1); 
		}
	}
	 
	return result;
}


int main() {

	system("pause");
	return 0;
}