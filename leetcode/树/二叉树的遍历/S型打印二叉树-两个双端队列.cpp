/************************************************************************/
/*@File Name         : S型打印二叉树-两个双端队列.cpp
/*@Created Date      : 2020/7/8 16:48
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :	按照S型打印二叉树，使用两个双端队列实现
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
	vector<vector<int>> printSTree(TreeNode* root) {
		vector<vector<int>>result;

		if (!root)
			return result;
		deque<TreeNode*>q, p;
		q.push_back(root);
		vector<int>tmp;
		while (!q.empty()) {
			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop_front();
				if (node->left)
					p.push_back(node->left);
				if (node->right)
					p.push_back(node->right);

				tmp.push_back(node->val);
			}
			result.push_back(tmp);
			tmp.clear();
			while (!p.empty()) {
				TreeNode* node = p.back();
				p.pop_back();
				if (node->right)
					q.push_front(node->right);
				if (node->left)
					q.push_front(node->left);

				tmp.push_back(node->val);
			}
			result.push_back(tmp);
			tmp.clear();

		}
		return result;
	}
};