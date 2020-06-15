/************************************************************************/
/*@File Name         : 4.二叉查找树的最近公共祖先.cpp
/*@Created Date      : 2020/6/14 19:14
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 二叉搜索树的最低公共祖先可太简单了，因为二叉搜索数的中序遍历是有序的
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
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return nullptr;

		int rootVal = root->val;
		int leftVal = p->val;
		int rightVal = q->val;

		if (leftVal < rootVal && rightVal < rootVal) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (leftVal > rootVal && rightVal > rootVal)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};