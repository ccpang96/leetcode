/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
*/

//首先构建s+s，然后在s+s中查找s，如果出现的位置刚好为s.size()，那么则不是重复的子串构成，否则是。

#include<string>
using std::string;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		return (s + s).find(s, 1) != s.size();
	}
};