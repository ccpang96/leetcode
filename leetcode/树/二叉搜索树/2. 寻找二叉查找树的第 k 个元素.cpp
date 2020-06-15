/************************************************************************/
/*@File Name         : 2. Ѱ�Ҷ���������ĵ� k ��Ԫ��.cpp
/*@Created Date      : 2020/6/14 16:29
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
	int kthSmallest(TreeNode* root, int k) {
		
		stack<TreeNode*>stack1;
		TreeNode* cur = root;
		int result = -1;
		while (cur != nullptr || !stack1.empty()) {
			while (cur != nullptr) {
				stack1.push(cur);
				cur = cur->left;
			}
			if (!stack1.empty()) {
				cur = stack1.top();
				stack1.pop();
				k--;
				if (k == 0)
					result = cur->val;
				cur = cur->right;
			}
		}
		return result;
	}
};