/*
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

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
			return -1;  //ƥ�䲻�ɹ�
		if (needle.empty())
			return 0;  //ģʽ��Ϊ��

	 


		int n = needle.size();   //ģʽ���ĳ���
		int m = haystack.size(); //ģ�崮�ĳ���

		vector<int>ne(n + 10, -1); //��0��ʼʱ��Ҫ��ʼ��Ϊ-1

		//��ne����
		for (int i = 1, j = -1; i < n; i++) {
			while (j != -1 && needle[i] != needle[j + 1])
				j = ne[j];
			if (needle[i] == needle[j + 1]) j++;
			ne[i] = j;
		}

		//KMPƥ�����
		for (int i = 0, j = -1; i < m; i++) {
			while (j != -1 && haystack[i] != needle[j + 1])
				j = ne[j];
			if (haystack[i] == needle[j + 1])
				j++;
			if (j == n - 1) {
				//ƥ��ɹ�
				return i - n + 1;
			}
		}
		return -1;
	}
};