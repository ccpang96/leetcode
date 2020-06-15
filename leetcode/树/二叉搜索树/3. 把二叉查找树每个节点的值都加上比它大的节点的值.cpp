/************************************************************************/
/*@File Name         : 3. 把二叉查找树每个节点的值都加上比它大的节点的值.cpp
/*@Created Date      : 2020/6/14 16:41
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
	int sum = 0;
public:
	TreeNode * convertBST(TreeNode* root) {
		dfs(root);
		return root;
	}
		
	void dfs(TreeNode* root) {
		if (root == nullptr)
			return;
		dfs(root->right);
		sum += root->val;
		root->val = sum;
		dfs(root->left);
	}
};
