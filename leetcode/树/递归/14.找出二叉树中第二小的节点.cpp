/************************************************************************/
/*@File Name         : 14.找出二叉树中第二小的节点.cpp
/*@Created Date      : 2020/6/14 8:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

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
	int findSecondMinimumValue(TreeNode* root) {
		if (!root)
			return -1;

		if (!root->left)
			return -1;
		int leftVal = root->left->val;
		int rightVal = root->right->val;
		if (leftVal == root->val) leftVal = findSecondMinimumValue(root->left);
		if (rightVal == root->val) rightVal = findSecondMinimumValue(root->right);
		if (leftVal != -1 && rightVal != -1)
			return min(leftVal, rightVal);
		if (leftVal != -1)
			return rightVal;
		
		return leftVal;
		
	}
};