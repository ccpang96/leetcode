/************************************************************************/
/*@File Name         : 非递归后序遍历.cpp
/*@Created Date      : 2020/6/14 14:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 后序遍历，第一次访问的时候再将节点重新入栈，然后再推入一个nullptr节点
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>result;
		if (!root)
			return result;
		stack<TreeNode*>stack1;
		stack1.push(root);
		while (!stack1.empty()) {
			TreeNode*node = stack1.top();
			stack1.pop();
			if (node != nullptr) {
				stack1.push(node);		//先push节点，再push nullptr，这样在出栈的时候，nullptr先出栈
				stack1.push(nullptr);
				if (node->right)
					stack1.push(node->right);
				if (node->left)
					stack1.push(node->left);
			}
			else {
				//空指针之后的值一定是第二次被放入的，所以在这一次对其进行处理
				result.push_back((stack1.top())->val);
				stack1.pop();
			}
		}
		return result;
	}
};