/************************************************************************/
/*@File Name         : 10.��С·��.cpp
/*@Created Date      : 2020/6/14 7:22
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
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
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0 || right == 0) return left + right + 1;		//��һ������Ϊ��
		return min(left, right) + 1;
	}
};