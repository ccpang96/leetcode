/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() && needle.empty())
			return 0;
		if (haystack.empty())
			return -1;  //匹配不成功
		if (needle.empty())
			return 0;  //模式串为空

	 


		int n = needle.size();   //模式串的长度
		int m = haystack.size(); //模板串的长度

		vector<int>ne(n + 10, -1); //从0开始时就要初始化为-1

		//求ne数组
		for (int i = 1, j = -1; i < n; i++) {
			while (j != -1 && needle[i] != needle[j + 1])
				j = ne[j];
			if (needle[i] == needle[j + 1]) j++;
			ne[i] = j;
		}

		//KMP匹配过程
		for (int i = 0, j = -1; i < m; i++) {
			while (j != -1 && haystack[i] != needle[j + 1])
				j = ne[j];
			if (haystack[i] == needle[j + 1])
				j++;
			if (j == n - 1) {
				//匹配成功
				return i - n + 1;
			}
		}
		return -1;
	}
};