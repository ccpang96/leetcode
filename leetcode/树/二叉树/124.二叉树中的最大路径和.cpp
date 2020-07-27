/************************************************************************/
/*@File Name         : 124.二叉树中的最大路径和.cpp
/*@Created Date      : 2020/7/13 15:46
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
	int maxPathSum(TreeNode* root) {

		ans = INT_MIN;
		maxGain(root);
		return ans;
	}

	int maxGain(TreeNode *root) {
		if (!root)
			return 0;
		int leftValue = max(maxGain(root->left), 0); //如果还没有0大，就不要了
		int rightValue = max(maxGain(root->right), 0);
		//left-root-right 作为路径与最大值比较
		ans = max(ans, leftValue + root->val + rightValue);
		//返回经过root的单边最大分支给上游
		return root->val + max(leftValue, rightValue);
	}
private:
	int ans;
};