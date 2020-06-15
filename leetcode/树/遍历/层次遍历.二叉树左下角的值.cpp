/************************************************************************/
/*@File Name         : 层次遍历.二叉树左下角的值.cpp
/*@Created Date      : 2020/6/14 9:33
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个二叉树，在树的最后一行找到最左边的值。
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
	int findBottomLeftValue(TreeNode* root) {

		//题目假设输入值不为nullptr

		queue<TreeNode*>q1;
		q1.push(root);
		int result = 0;
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			q1.pop();

			if (q1.empty() && !node->left && !node->right)
				result = node->val;

			if (node->right)
				q1.push(node->right);

			if (node->left) {
				q1.push(node->left);
			}

		}
		return result;
	}
};

