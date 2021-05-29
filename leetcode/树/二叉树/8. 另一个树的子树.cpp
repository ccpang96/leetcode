/************************************************************************/
/*@File Name         : 572. 另一个树的子树.cpp
/*@Created Date      : 2020/6/1 8:42
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 首先使用递归的思路，分别判断(s,t)、(s->right,t)、(s->left,t).然后调用函数判断两个树是否相等.
//对于s上的每个点都要和t进行匹配，而匹配一次的代价是O(t)，所以渐近时间复杂度是O(s*t);
//空间复杂度是：max(ds,dt); //其中ds是树s的深度，dt是树t的深度
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
	bool isSubTree(TreeNode* s, TreeNode *t) {
		if (t == nullptr) 
			return true;   //空树是任意树的子树
		if (s == nullptr)
			return false;  //s是空树的话，就直接返回false
		return isSubTree(s->left, t) || isSubTree(s->right, t) || isSubTreeWithRoot(s, t);
	}
	bool isSubTreeWithRoot(TreeNode *s, TreeNode* t) {
		//这里子树的判断是s的一个节点和节点的所有子孙都和t相等
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr || s->val != t->val)
			return false;
		return isSubTreeWithRoot(s->left, t->left) && isSubTreeWithRoot(s->right, t->right);
	}
};

 

