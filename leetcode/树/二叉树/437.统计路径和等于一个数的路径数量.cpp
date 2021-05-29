/*
����һ��������������ÿ����㶼�����һ������ֵ���ҳ�·���͵��ڸ�����ֵ��·��������
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
˫�ݹ飺ʱ�临�Ӷ�O(n2)
*/

#include<iostream>
#include<sstream>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root)
			return 0;
		int res = pathSumWithNode(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		return res;
	}

	int pathSumWithNode(TreeNode *root, int sum) {
		if (root == nullptr)
			return 0;

		int res = 0;
		if (root->val == sum)
			res = 1;

		res += pathSumWithNode(root->left, sum - root->val) + pathSumWithNode(root->right, sum - root->val);
		return res;
	}
};

