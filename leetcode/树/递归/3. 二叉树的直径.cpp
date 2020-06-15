/************************************************************************/
/*@File Name         : 543. ��������ֱ��.cpp
/*@Created Date      : 2020/5/31 10:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 543. ��������ֱ��
/*@ Description 		 :����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
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
	int ans = 0;

	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;

		int maxD = maxDepth(root);
		return ans - 1;
	}

	int maxDepth(TreeNode *root) {
		if (!root)
			return 0;
		int left = maxDepth(root->left);	//��������������
		int right = maxDepth(root->right);	//��������������
		ans = max(ans, left + right + 1);	//���ڵ������L+R+1
		return 1 + max(left, right);
	}
};