/************************************************************************/
/*@File Name         : 438. 找到字符串中所有字母异位词.cpp
/*@Created Date      : 2020/5/18 15:56
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/************************************************************************/
/*@ Problem Name         : 438. 找到字符串中所有字母异位词
/*@ Description 		 :给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
*************************************************************************
/*@ Example1-Input	 	 :s: "cbaebabacd" p: "abc"
/*@ Example1-Output		 :[0, 6]
/*@ Example1-Explanation :起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
*************************************************************************
/*@ Example1-Input	 	 :s: "abab" p: "ab"
/*@ Example1-Output		 :[0, 1, 2]
/*@ Example1-Explanation :起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

/*@补充说明：
/************************************************************************/

/************************************************************************/
/*@FullName:  findAnagrams
/*@Brief:     在s中查找p的字母异位词
/*@Parameter: s : 主串  p: 模式串 
/*@Returns:   vector，返回的是匹配成功的起始索引
/*@time:      2020/5/18 15:59
/*@author:    ccpang
/************************************************************************/
vector<int> findAnagrams(string s, string p) {

	vector<int>result;
	//输入参数有效性判断
	if (s.size() <= p.size())
		return result;


	//申请一个散列表，用于记录s中元素出现的情况，因为s中只有小写字母，所以是26个
	int hash[26] = {0};
	
	//预处理，更新hash表
	for (int i = 0; i < p.size(); i++)
		hash[p[i] - 'a']++;


	int l = 0; //左指针
	int count = 0; //满足条件的元素个数


	for (int r = 0; r < s.size(); r++) {
		hash[s[r] - 'a']--;

		if (hash[s[r] - 'a'] >= 0)		//只有在p中存在的元素才会>=0
			count++;					//匹配长度+1

		if (r > p.size() - 1) {			//左指针要移动
			hash[s[l] - 'a']++;			//将64行减掉的元素的个数重新加上，原来是p中的元素现在变为> 0,不是p中的元素刚好=0

			if (hash[s[l] - 'a'] > 0) //是p中的元素
				count--;		//匹配的个数-1
			l++;				//更新滑动窗口
		}
		 
		if (count == p.size())
			result.push_back(l);

	}
	return result;

}



int main() {

	// 测试 [5/18/2020 Administrator]
	string s1 = "cbaebabacd";
	string s2 = "abc";
	vector<int> result = findAnagrams(s1, s2);
	for (auto &m : result)
		cout << m << ",";
	cout << endl;
	system("pause");
	return 0;
}

/************************ (C) COPYRIGHT ccpang *****END OF FILE****/