/************************************************************************/
/*@File Name         : 124.�������е����·����.cpp
/*@Created Date      : 2020/7/13 15:46
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

class Solution {
public:
	int maxPathSum(TreeNode* root) {

		ans = INT_MIN;
		maxGain(root);
		return ans;
	}

	int maxGain(TreeNode *root) {
		if (!root)
			return 0;
		int leftValue = max(maxGain(root->left), 0); //�����û��0�󣬾Ͳ�Ҫ��
		int rightValue = max(maxGain(root->right), 0);
		//left-root-right ��Ϊ·�������ֵ�Ƚ�
		ans = max(ans, leftValue + root->val + rightValue);
		//���ؾ���root�ĵ�������֧������
		return root->val + max(leftValue, rightValue);
	}
private:
	int ans;
};