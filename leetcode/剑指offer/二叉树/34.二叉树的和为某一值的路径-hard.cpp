/*
	����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·���������ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
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
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<vector<int>> result;

		if (root == nullptr)
			return result;
		vector<int> temp;
		hasPathWithRoot(root, sum, temp, result);
		return result;
	}
	void hasPathWithRoot(TreeNode *root, int sum, vector<int>&temp, vector<vector<int>>&result) {

		//�������
		temp.push_back(root->val);
		if (root->val == sum && root->left == nullptr && root->right == nullptr)
		{
			result.push_back(temp);
		}

		if (root->left)
			hasPathWithRoot(root->left, sum - root->val, temp, result);
		if (root->right)
			hasPathWithRoot(root->right, sum - root->val, temp, result);

		temp.pop_back();
	}
};