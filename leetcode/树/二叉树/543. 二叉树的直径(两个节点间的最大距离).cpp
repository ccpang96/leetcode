/************************************************************************/
/*@File Name         : 543. 二叉树的直径.cpp
/*@Created Date      : 2020/5/31 10:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 543. 二叉树的直径
/*@ Description 		 :
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
	int maxLength = 1;

	int diameterOfBinaryTree(TreeNode* root) {
		maxDepth(root);
		return maxLength - 1; //边的数量= 节点数量-1
	}

	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		maxLength = max(maxLength, left + right + 1);
		return 1 + max(left, right);
	}
 
	
};