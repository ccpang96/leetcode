/************************************************************************/
/*@ Problem Name         : 112. ·���ܺ�
/*@ Description 		 :����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·����
����·�������нڵ�ֵ��ӵ���Ŀ��͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		//Ҫ����Ҷ�ӽڵ�
		if (root->left == nullptr && root->right == nullptr && root->val == sum)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

