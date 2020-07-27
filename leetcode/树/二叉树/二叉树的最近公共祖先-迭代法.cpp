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



//迭代方法：先分别找到一个由根节点通往节点1和节点2的路径，分别存放在list1和list2中，然后再从后往前遍历list1和list2找到相等的值。
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

//递归方法：分别在左右子树中查找节点p和节点q，如果root=p或者root =q或者root =nullptr就返回，则判断如果left

class Solution1 {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//走到这一步，说明p或者q被找到，则返回p或者q，否则返回nullptr
		if (!root || root == p || root == q) {
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (!left && !right)	return nullptr;  //左右子树都没找到p和q就返回nullptr
		if (!right && left)	return left;	//右子树没找到，说明左子树就是公共节点
		if (!left && right)	return right;   //左子树没找到，说明右子树就是公共节点

		return root;   //说明根节点就是公共节点
	}
};
