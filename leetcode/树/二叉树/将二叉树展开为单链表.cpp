/*
����һ����������ԭ�ؽ���չ��Ϊһ��������
*/

#include<iostream>

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



 //û�뵽�ݹ�һ�Ѿ�Ȼ����
class Solution {
public:
	void flatten(TreeNode* root) {

		if (!root || (!root->left && !root->right))
			return;

		//����ڵ㵫��û���ҽڵ�
		if (root->left && !root->right) {
			TreeNode* temp = root->right;
			root->right = root->left;
			root->left = temp;
		}
		//������ڵ������ҽڵ�
		if (root->left && root->right) {
			TreeNode* temp = root->right;
			root->right = root->left;
			root->left = nullptr;  //����ڵ���Ϊ��
			TreeNode* cur = root->right;
			while (cur->right != nullptr) {
				cur = cur->right;
			}
			cur->right = temp;
		}
		flatten(root->left);
		flatten(root->right);

	}
};