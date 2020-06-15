/************************************************************************/
/*@File Name         : 10.最小路径.cpp
/*@Created Date      : 2020/6/14 7:22
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。
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
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0 || right == 0) return left + right + 1;		//有一侧子树为空
		return min(left, right) + 1;
	}
};