/*
	�绰�������ϣ�����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
	�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��


*/


#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
	map<int, string> map1{ { 2, "abc" },{ 3, "def" },{ 4, "ghi" },{ 5, "jkl" },{ 6, "mno" },{ 7, "pqrs" },{ 8, "tuv" },{ 9, "wxyz" } };
	vector<string> ans;
	string temp;

	void DFS(int index, string & digits) {

		if (index == digits.size()) { //����߽�
			ans.push_back(temp);
			return;
		}
		for (int i = 0; i < map1[digits[index] - '0'].size(); i++) {
			temp.push_back(map1[digits[index] - '0'][i]);
			DFS(index + 1, digits);
			temp.pop_back();  //����
		}
	}

	vector<string>letterCombinations(string digits) {
		if (digits.empty())
			return ans;
		DFS(0, digits);
		return ans;
	}

};
