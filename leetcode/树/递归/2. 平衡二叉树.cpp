/************************************************************************/
/*@File Name         : 110. Æ½ºâ¶þ²æÊ÷.cpp
/*@Created Date      : 2020/5/31 10:21
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
#include<cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:

	bool isBalanced(TreeNode* root) {
		int maxD = maxDepth(root);
		return result;
	}
	int maxDepth(TreeNode *root) {
		if (!root)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		if (abs(left - right) > 1) result = false;
		return 1 + max(left, right);
	}
private:
	bool result = true;
};