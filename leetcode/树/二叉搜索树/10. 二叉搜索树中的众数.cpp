/************************************************************************/
/*@File Name         : 10. 二叉搜索树中的众数.cpp
/*@Created Date      : 2020/6/15 15:28
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

//众数只会出现在连续的节点中
class Solution {

public:
	TreeNode * preNode = nullptr;
	int times = 1;
	int maxTimes = 1;
	vector<int> findMode(TreeNode* root) {
		vector<int> results;
		if (root == nullptr)
			return results;
		dfs_inorder(root, results);
		return results;
	}

	//中序遍历
	void dfs_inorder(TreeNode* root, vector<int>&results)
	{
		if (root == nullptr) return;
		dfs_inorder(root->left, results);
		if (preNode != nullptr) {
			if (preNode->val == root->val)
				times++;
			else
				times = 1;	//重新开始一个值
		}
 
		if (times  > maxTimes)
		{
			results.clear();
			maxTimes = times;
			results.push_back(root->val);
		}
		else if (times ==  maxTimes)
		{
			results.push_back(root->val);
		}
		preNode = root;
		dfs_inorder(root->right, results);
	}
};