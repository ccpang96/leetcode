/************************************************************************/
/*@File Name         : 非递归前序遍历.cpp
/*@Created Date      : 2020/6/14 14:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 前序遍历
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
	vector<int> preorderTraversal(TreeNode* root) {
		//输入异常值处理

		vector<int>result;
		if (!root)
			return result;
		stack<TreeNode*>stack1;
		stack1.push(root);
		while (!stack1.empty()) {
			TreeNode* node = stack1.top();
			result.push_back(node->val);
			stack1.pop();
			if(node->right)
				stack1.push(node->right);
			if(node->left)
				stack1.push(node->left);
			
		}
		return result;
	}
};

 