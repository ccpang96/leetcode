/*
	��������ֱ��������ָ���������ڵ��·�����ȵ����ֵ
	����·�����ܿ�����ڵ�Ҳ���ܲ����.
*/

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
	int maxLength = 1;

	int diameterOfBinaryTree(TreeNode* root) {
		maxDepth(root);
		return maxLength - 1; //�ߵ�����= �ڵ�����-1
	}

	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		maxLength = max(maxLength, left + right + 1);
		return 1 + max(left, right);
	}
 
	
};