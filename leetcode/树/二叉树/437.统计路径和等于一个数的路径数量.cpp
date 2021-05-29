/*
给定一个二叉树，它的每个结点都存放着一个整数值。找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
双递归：时间复杂度O(n2)
*/

#include<iostream>
#include<sstream>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root)
			return 0;
		int res = pathSumWithNode(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		return res;
	}

	int pathSumWithNode(TreeNode *root, int sum) {
		if (root == nullptr)
			return 0;

		int res = 0;
		if (root->val == sum)
			res = 1;

		res += pathSumWithNode(root->left, sum - root->val) + pathSumWithNode(root->right, sum - root->val);
		return res;
	}
};

