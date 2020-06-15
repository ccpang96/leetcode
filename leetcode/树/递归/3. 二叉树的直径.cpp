/************************************************************************/
/*@File Name         : 543. 二叉树的直径.cpp
/*@Created Date      : 2020/5/31 10:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 543. 二叉树的直径
/*@ Description 		 :给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

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

		int maxD = maxDepth(root);
		return ans - 1;
	}

	int maxDepth(TreeNode *root) {
		if (!root)
			return 0;
		int left = maxDepth(root->left);	//左子树的最大深度
		int right = maxDepth(root->right);	//右子树的最大深度
		ans = max(ans, left + right + 1);	//最大节点个数：L+R+1
		return 1 + max(left, right);
	}
};