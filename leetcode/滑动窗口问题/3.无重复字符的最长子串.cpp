/************************************************************************/
/*@File Name         : 3.���ظ��ַ�����Ӵ�.cpp
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
/*@ Problem Name         : 3.���ظ��ַ�����Ӵ�
/*@ Description 		 :����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*************************************************************************
/*@ Example1-Input	 	 :"abcabcbb"
/*@ Example1-Output		 :3 
/*@ Example1-Explanation : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
*************************************************************************
/*@ Example1-Input	 	 :"pwwkew"
/*@ Example1-Output		 :3
/*@ Example1-Explanation :��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��

/*@����˵������Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
/************************************************************************/
 
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;

		int hash[256] = { 0 };  //ע��˴�һ��Ҫ��ʼ��

		int ans = 0;
		int l = 0;
		for (int r = 0; r < s.size(); r++) {
			hash[s[r]]++;

			//������ര��
			while (hash[s[r]] > 1) {
				hash[s[l]]--;
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};
