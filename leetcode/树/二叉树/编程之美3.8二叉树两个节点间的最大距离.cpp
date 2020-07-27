/************************************************************************/
/*@File Name         : ���֮��3.8�����������ڵ���������.cpp
/*@Created Date      : 2020/7/5 10:01
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :������ǰѶ���������ͼ�����ӽڵ�֮������߿�����˫��ģ�
���ǹ��Ҷ��塰���롱Ϊ�����ڵ�֮��ߵĸ�����дһ��������һ�ö������������Զ�������ڵ�֮��ľ��롣
/************************************************************************/


//˼·��
/*
���A: ·������������������ڵ㣬ͨ�����ڵ㣬�ٵ�������������ڵ㡣
���B: ·�����������ڵ㣬��������������������������·����ȡ�����
*//*@ Example1-Explanation :

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
		maxDepth(root);
		return ans - 1;
	}

	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int L = maxDepth(root->left);
		int R = maxDepth(root->right);
		ans = max(ans, L + R + 1);	//�ڵ���Ŀ
		return max(L, R) + 1;

	}
};