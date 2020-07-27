/************************************************************************/
/*@File Name         : 11.统计左叶子节点的和.cpp
/*@Created Date      : 2020/6/14 7:34
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;
		int left = sumOfLeftLeaves(root->left);
		int right = sumOfLeftLeaves(root->right);

		int result = 0;
		if (root->left && !root->left->left && !root->left->right)
			result = root->left->val;
		return left + right + result;
	}
};