/************************************************************************/
/*@File Name         : 17. 电话号码的字母组合.cpp
/*@Created Date      : 2020/6/28 15:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

 
class Solution {
public:
	map<int, string>M{ { 2,"abc" },{ 3,"def" },{ 4,"ghi" },{ 5,"jkl" },{ 6,"mno" },{ 7,"pqrs" },{ 8,"tuv" },{ 9,"wxyz" } };
	vector<string>ans;
	string current;
	void DFS(int index, string& digits) {

		if (index == digits.size()) {
			ans.push_back(current);
			return;
		}


		for (int i = 0; i < M[digits[index] - '0'].size(); i++) {
			current.push_back(M[digits[index] - '0'][i]);
			DFS(index + 1, digits);
			current.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return ans;
		DFS(0, digits);
		return ans;

	}
};