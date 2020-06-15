/************************************************************************/
/*@File Name         : 二叉树的最近公共祖先-递归法.cpp
/*@Created Date      : 2020/6/14 19:46
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
	TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
		//走到这一步，说明p或者q被找到，则返回p或者q，否则返回nullptr
		if (!root || root == p || root == q) {
			return root;
		}
 
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (!left && !right)	return nullptr;
		if ( !right && left)	return left;
		if (!left && right   )	return right;
		
		return root;
	}
};



class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q) {
			return root;
		}
		//走到这一步，说明p或者q被找到，
		if (root == p || root == q)
			return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && !right)
			return left;
		if (!left && right)
			return right;

		return root;
	}
};