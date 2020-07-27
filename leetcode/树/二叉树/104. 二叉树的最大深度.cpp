/************************************************************************/
/*@File Name         : 104. ��������������.cpp
/*@Created Date      : 2020/5/31 6:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/

/************************************************************************/
/*@ Problem Name         : 104. ��������������
/*@ Description 		 :����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
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
#include<cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//������������ݹ�汾
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + max(left, right);
	}
};

/*
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int depth = 0;
		stack<pair<TreeNode*, int>>s1;
		s1.push(pair<TreeNode*, int>{root, depth});
		TreeNode* p = root;
		int maxDepth = 0;
		while (!s1.empty() || p != nullptr) {
			while (p != nullptr) {
				s1.push(pair<TreeNode*, int>{p, ++depth});
				p = p->left;
			}
			p = s1.top().first;
			depth = s1.top().second; //��� ��ȡ��ͷ���ڵ�ʱ����Ȼ��޸�Ϊ��ǰ�����ڵ��ֵ
			s1.pop();
			maxDepth = max(depth, maxDepth);
			p = p->right;
		}
		return maxDepth;
	}
};*/