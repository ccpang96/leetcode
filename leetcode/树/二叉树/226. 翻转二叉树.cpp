/************************************************************************/
/*@File Name         : 226. 翻转二叉树.cpp
/*@Created Date      : 2020/5/31 10:57
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

//递归版本
class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (!root)
			return nullptr;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

//迭代版本:用栈实现
class Solution1 {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (!root) return nullptr;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp) {
				swap(tmp->left, tmp->right);
				q.push(tmp->left);
				q.push(tmp->right);
			}
		}
		return root;
	}
};