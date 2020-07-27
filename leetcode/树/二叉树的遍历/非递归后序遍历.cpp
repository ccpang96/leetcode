/************************************************************************/
/*@File Name         : �ǵݹ�������.cpp
/*@Created Date      : 2020/6/14 14:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : �����������һ�η��ʵ�ʱ���ٽ��ڵ�������ջ��Ȼ��������һ��nullptr�ڵ�
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
				stack1.push(node);		//��push�ڵ㣬��push nullptr�������ڳ�ջ��ʱ��nullptr�ȳ�ջ
				stack1.push(nullptr);
				if (node->right)
					stack1.push(node->right);
				if (node->left)
					stack1.push(node->left);
			}
			else {
				//��ָ��֮���ֵһ���ǵڶ��α�����ģ���������һ�ζ�����д���
				result.push_back((stack1.top())->val);
				stack1.pop();
			}
		}
		return result;
	}
};