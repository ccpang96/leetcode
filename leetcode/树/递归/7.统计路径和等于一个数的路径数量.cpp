/************************************************************************/
/*@File Name         : 47.路径总和3.cpp
/*@Created Date      : 2020/5/31 14:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 47.路径总和3
/*@ Description 		 :给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
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
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ret = pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		return ret;
	}

	int pathSumStartWithRoot(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ret = 0;
		if (root->val == sum) ret++;
		ret += pathSumStartWithRoot(root->left, sum - root->val) + pathSumStartWithRoot(root->right, sum - root->val);
		return ret;
	}
};
