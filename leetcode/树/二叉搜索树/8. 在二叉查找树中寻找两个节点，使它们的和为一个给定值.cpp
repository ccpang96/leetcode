/************************************************************************/
/*@File Name         : 8. 在二叉查找树中寻找两个节点，使它们的和为一个给定值.cpp
/*@Created Date      : 2020/6/14 22:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
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
		
		//如果能找到的话
		if (hash.find(k - root->val) != hash.end())
			return true;
		hash.insert(root->val);
		bool left  =  findTwoNodes(root->left, k);
		bool right = findTwoNodes(root->right, k);
		return left || right;
	}
};