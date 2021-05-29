/************************************************************************/
/*@File Name         : 58.1.翻转单词的顺序.cpp
/*@Created Date      : 2020/6/13 9:17
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	//翻转一个句子也包括一个单词
	void reverse(string &s, int l, int r) {
		if (s.empty() || l >= r)
			return;
		while (l < r) {
			char temp = s[l];
			s[l] = s[r];
			s[r] = temp;
			l++;
			r--;
		}
	}

	//首先是不能改变原来的输入字符串
	string reverseWords(string &s) {
		if (s.empty())
			return s;

		//去掉前缀空格
		int l = 0;
		while (l < s.size() && s[l] == ' ')
			l++;


		//去掉后缀空格
		int k = s.size() - 1;
		while (k >= 0 && s[k] == ' ')
			k--;


		//判断k和l是否有效
		if (k >= l)
			s = s.substr(l, (k - l) + 1);
		else
			return "";


		string result; //不改变原有的输入字符串
					   //去掉中间空格
		char last = ' ';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ' || last != ' ') {  //判断i不是最后的为空字符，且不是中间的连续为空字符
				result.push_back(s[i]);
			}
			last = s[i];
		}

		//翻转整个句子
		reverse(result, 0, result.size() - 1); //先对整个句子翻转


		//翻转句子中的单词
		l = 0;
		int i = 0;
		for (; i < result.size(); i++) {
			if (result[i] == ' ') {
				reverse(result, l, i - 1);   //翻转这个单词
				l = i + 1;
			}
		}
		reverse(result, l, result.size() - 1);
		return result;
	}

};