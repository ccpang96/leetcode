/************************************************************************/
/*@File Name         : 9. 二叉搜索树的最小绝对差.cpp
/*@Created Date      : 2020/6/15 8:49
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
#include<set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

 

//迭代解法
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {

		long long  last_number = INT_MAX;
		int result = INT_MAX;
		stack<TreeNode*>stack1;
		TreeNode*cur = root;
		while (cur != nullptr || !stack1.empty()) {
			while (cur != nullptr) {
				stack1.push(cur);
				cur = cur->left;
			}
			if (!stack1.empty()) {
				cur = stack1.top();
				stack1.pop();

				if (abs(last_number - cur->val) < result) {
					result = abs(last_number - cur->val);
				}
				last_number = cur->val;
				cur = cur->right;
			}
		}
		return result;
	}
};


 