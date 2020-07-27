/************************************************************************/
/*@File Name         : 47.·���ܺ�3.cpp
/*@Created Date      : 2020/5/31 14:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 47.·���ܺ�3
/*@ Description 		 :����һ��������������ÿ����㶼�����һ������ֵ��
�ҳ�·���͵��ڸ�����ֵ��·��������
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
������������1000���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������
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
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ret = pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
		return ret;
	}

	int pathSumStartWithRoot(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ret = 0;
		if (root->val == sum) ret++;
		ret += pathSumStartWithRoot(root->left, sum - root->val) + pathSumStartWithRoot(root->right, sum - root->val);
		return ret;
	}
};
