/************************************************************************/
/*@File Name         : 13.�������.cpp
/*@Created Date      : 2020/6/14 7:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/*
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



//����DP
class Solution {
public:

	int rob(TreeNode* root) {
		pair<int, int>ans = robhelp(root);	//first�������ٵ�ǰ�ڵ㣬second�������ٵ�ǰ�ڵ�
		return max(ans.first,ans.second);
	}

	pair<int, int> robhelp(TreeNode* root)
	{
		if (!root)   
			return make_pair(0,0);
		pair<int, int>l = robhelp(root->left), r = robhelp(root->right);
		return make_pair(max(l.first, l.second) + max(r.first, r.second), root->val + l.first + r.first); //�����ٵ�ǰ�ڵ㣬���ٵ�ǰ�ڵ�
	}
};



//ֱ�ӵݹ�
class Solution1{
public:
	int rob(TreeNode* root) {
		if (!root)
			return 0;
		int val1 = root->val, val2 = 0;
		if (root->left)
			val1 += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val1 += rob(root->right->left) + rob(root->right->right);

		val2 += rob(root->left) + rob(root->right);

		return max(val1, val2);
	}
};
*/