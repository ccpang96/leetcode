/************************************************************************/
/*@File Name         : 二叉树的最近公共祖先-迭代法.cpp
/*@Created Date      : 2020/6/14 20:24
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


	bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>&list) {
		list.push_back(root);
		if (root == node)
			return true;
		bool found = false;
		if (!found && root->left)  found = findPath(root->left, node, list);
		if (!found && root->right)  found = findPath(root->right, node, list);
		if (!found) {
			list.pop_back();
		}
		return found;
	}

	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return nullptr;

		vector<TreeNode*>list1;
		vector<TreeNode*>list2;

		bool found1 = findPath(root, p, list1);
		bool found2 = findPath(root, q, list2);

		TreeNode* node = root;
		if (found1 && found2) {
			for (int i = min(list1.size(), list2.size()) - 1; i >= 0;i--) {
				if (list1[i] == list2[i]) {
					node = list1[i];
					break;

				}
			}
		}
		return node;
	}
};