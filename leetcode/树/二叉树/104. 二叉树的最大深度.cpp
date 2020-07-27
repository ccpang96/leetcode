/************************************************************************/
/*@File Name         : 104. 二叉树的最大深度.cpp
/*@Created Date      : 2020/5/31 6:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/

/************************************************************************/
/*@ Problem Name         : 104. 二叉树的最大深度
/*@ Description 		 :给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
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
#include<cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//深度优先搜索递归版本
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + max(left, right);
	}
};

/*
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int depth = 0;
		stack<pair<TreeNode*, int>>s1;
		s1.push(pair<TreeNode*, int>{root, depth});
		TreeNode* p = root;
		int maxDepth = 0;
		while (!s1.empty() || p != nullptr) {
			while (p != nullptr) {
				s1.push(pair<TreeNode*, int>{p, ++depth});
				p = p->left;
			}
			p = s1.top().first;
			depth = s1.top().second; //深度 在取出头部节点时，深度会修改为当前顶部节点的值
			s1.pop();
			maxDepth = max(depth, maxDepth);
			p = p->right;
		}
		return maxDepth;
	}
};*/