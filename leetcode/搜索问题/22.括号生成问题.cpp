/************************************************************************/
/*@File Name         : 22.括号生成问题.cpp
/*@Created Date      : 2020/6/28 16:17
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
using namespace std;

 

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>result;
		if (n <= 0)
			return result;
		
		dfs("", n, n, result);
		return result;
	}
	void dfs(string s1, int left, int right, vector<string>&ans) {

		if (left == 0 && right == 0) {
			ans.push_back(s1);
			return;
		}

		//剪枝操作
		if (left > right)
			return;

		if (left > 0) {
			dfs(s1+'(', left - 1, right, ans);
		}
		if (right > 0)
			dfs(s1+')', left, right - 1, ans);
	}
};

//int main() {
//	vector<string>result = Solution().generateParenthesis(2);
//
//	system("pause");
//	return 0;
//}