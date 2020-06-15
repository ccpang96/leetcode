/************************************************************************/
/*@File Name         : 8. �ڶ����������Ѱ�������ڵ㣬ʹ���ǵĺ�Ϊһ������ֵ.cpp
/*@Created Date      : 2020/6/14 22:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ��������������һ��Ŀ��������� BST �д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��
/************************************************************************/



#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
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
private:
	unordered_set<int>hash;
public:
	bool findTwoNodes(TreeNode* root, int k) {
		if (!root)
			return false;
		
		//������ҵ��Ļ�
		if (hash.find(k - root->val) != hash.end())
			return true;
		hash.insert(root->val);
		bool left  =  findTwoNodes(root->left, k);
		bool right = findTwoNodes(root->right, k);
		return left || right;
	}
};