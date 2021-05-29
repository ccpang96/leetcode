/*
	电话号码的组合：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
	给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


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

		if (index == digits.size()) { //到达边界
			ans.push_back(temp);
			return;
		}
		for (int i = 0; i < map1[digits[index] - '0'].size(); i++) {
			temp.push_back(map1[digits[index] - '0'][i]);
			DFS(index + 1, digits);
			temp.pop_back();  //回溯
		}
	}

	vector<string>letterCombinations(string digits) {
		if (digits.empty())
			return ans;
		DFS(0, digits);
		return ans;
	}

};
