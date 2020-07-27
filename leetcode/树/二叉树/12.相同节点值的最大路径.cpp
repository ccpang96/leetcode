/************************************************************************/
/*@File Name         : 12.相同节点值的最大路径.cpp
/*@Created Date      : 2020/6/14 7:46
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
public:
	int ret = 0;
	int longestUnivaluePath(TreeNode* root) {
		if (!root)
			return 0;
		
		longestUnivaluePathWithRoot(root);
		return ret;
	}

	int longestUnivaluePathWithRoot(TreeNode*root) {
		if (!root)
			return 0;
		int left = longestUnivaluePathWithRoot(root->left);
		int right = longestUnivaluePathWithRoot(root->right);

		int rightPath = 0, leftPath = 0;
		if (root->left && root->left->val == root->val) {
			leftPath += left+1;
		}
		if (root->right && root->right->val == root->val)
			rightPath += right+1;
		ret = max(ret, rightPath + leftPath);
		return max(leftPath, rightPath);
		return ret;
	}
};
