/************************************************************************/
/*@File Name         : �������������������-������.cpp
/*@Created Date      : 2020/6/14 20:24
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



//�����������ȷֱ��ҵ�һ���ɸ��ڵ�ͨ���ڵ�1�ͽڵ�2��·�����ֱ�����list1��list2�У�Ȼ���ٴӺ���ǰ����list1��list2�ҵ���ȵ�ֵ��
class Solution {
public:


	bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>&list) {
		list.push_back(root);
		if (root == node)
			return true;
		bool found = false;
		if (!found && root->left)  found = findPath(root->left, node, list);
		if (!found && root->right)  found = findPath(root->right, node, list);
		if (!found) {
			list.pop_back();
		}
		return found;
	}

	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return nullptr;

		vector<TreeNode*>list1;
		vector<TreeNode*>list2;

		bool found1 = findPath(root, p, list1);
		bool found2 = findPath(root, q, list2);

		TreeNode* node = root;
		if (found1 && found2) {
			for (int i = min(list1.size(), list2.size()) - 1; i >= 0;i--) {
				if (list1[i] == list2[i]) {
					node = list1[i];
					break;

				}
			}
		}
		return node;
	}
};

//�ݹ鷽�����ֱ������������в��ҽڵ�p�ͽڵ�q�����root=p����root =q����root =nullptr�ͷ��أ����ж����left

class Solution1 {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//�ߵ���һ����˵��p����q���ҵ����򷵻�p����q�����򷵻�nullptr
		if (!root || root == p || root == q) {
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (!left && !right)	return nullptr;  //����������û�ҵ�p��q�ͷ���nullptr
		if (!right && left)	return left;	//������û�ҵ���˵�����������ǹ����ڵ�
		if (!left && right)	return right;   //������û�ҵ���˵�����������ǹ����ڵ�

		return root;   //˵�����ڵ���ǹ����ڵ�
	}
};
