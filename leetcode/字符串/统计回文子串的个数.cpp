/*
	ͳ��һ���ַ������ж��ٸ������Ӵ�,���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ����ͬ���ַ���ɣ�Ҳ�ᱻ��Ϊ��ͬ���Ӵ�
*/

#include<string>
#include<iostream>
using namespace std;



class Solution {
public:
	int countSubstrings(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			//������չ
			int l = i, r = i;
			while (l >= 0 && r < s.size() && s[l--] == s[r++]) ans++;

			//������չ
			l = i, r = i + 1;
			while (l >= 0 && r < s.size() && s[l--] == s[r++]) ans++;


		}
		return ans;
	}

};
