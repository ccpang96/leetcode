/*
给定一个二叉树，原地将它展开为一个单链表。
*/

#include<iostream>

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



 //没想到递归一把竟然过了
class Solution {
public:
	void flatten(TreeNode* root) {

		if (!root || (!root->left && !root->right))
			return;

		//有左节点但是没有右节点
		if (root->left && !root->right) {
			TreeNode* temp = root->right;
			root->right = root->left;
			root->left = temp;
		}
		//既有左节点又有右节点
		if (root->left && root->right) {
			TreeNode* temp = root->right;
			root->right = root->left;
			root->left = nullptr;  //将左节点置为空
			TreeNode* cur = root->right;
			while (cur->right != nullptr) {
				cur = cur->right;
			}
			cur->right = temp;
		}
		flatten(root->left);
		flatten(root->right);

	}
};