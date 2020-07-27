/************************************************************************/
/*@File Name         : 编程之美3.8二叉树两个节点间的最大距离.cpp
/*@Created Date      : 2020/7/5 10:01
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :如果我们把二叉树看做图，父子节点之间的连线看成是双向的，
我们姑且定义“距离”为两个节点之间边的个数。写一个程序求一棵二叉树中相距最远的两个节点之间的距离。
/************************************************************************/


//思路：
/*
情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
情况B: 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者
*//*@ Example1-Explanation :

/*@补充说明：
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
	int ans = 0;
	int diameterOfBinaryTree(TreeNode* root) {

		if (!root)
			return 0;
		maxDepth(root);
		return ans - 1;
	}

	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		ans = max(ans, L + R + 1);	//节点数目
		return max(L, R) + 1;

	}
};