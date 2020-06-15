/************************************************************************/
/*@File Name         : 101. ¶Ô³Æ¶þ²æÊ÷.cpp
/*@Created Date      : 2020/6/11 9:02
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
	bool isSymmetric(TreeNode* root) {
		return isSymmetric(root, root);
	}

	bool isSymmetric(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2)
			return true;
		if (!root1 || !root2)
			return false;
		if (root1->val != root2->val)
			return false;
		return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
	}
};