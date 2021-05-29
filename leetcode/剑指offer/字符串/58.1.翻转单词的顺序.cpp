/************************************************************************/
/*@File Name         : 58.1.��ת���ʵ�˳��.cpp
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
	//��תһ������Ҳ����һ������
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

	//�����ǲ��ܸı�ԭ���������ַ���
	string reverseWords(string &s) {
		if (s.empty())
			return s;

		//ȥ��ǰ׺�ո�
		int l = 0;
		while (l < s.size() && s[l] == ' ')
			l++;


		//ȥ����׺�ո�
		int k = s.size() - 1;
		while (k >= 0 && s[k] == ' ')
			k--;


		//�ж�k��l�Ƿ���Ч
		if (k >= l)
			s = s.substr(l, (k - l) + 1);
		else
			return "";


		string result; //���ı�ԭ�е������ַ���
					   //ȥ���м�ո�
		char last = ' ';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ' || last != ' ') {  //�ж�i��������Ϊ���ַ����Ҳ����м������Ϊ���ַ�
				result.push_back(s[i]);
			}
			last = s[i];
		}

		//��ת��������
		reverse(result, 0, result.size() - 1); //�ȶ��������ӷ�ת


		//��ת�����еĵ���
		l = 0;
		int i = 0;
		for (; i < result.size(); i++) {
			if (result[i] == ' ') {
				reverse(result, l, i - 1);   //��ת�������
				l = i + 1;
			}
		}
		reverse(result, l, result.size() - 1);
		return result;
	}

};