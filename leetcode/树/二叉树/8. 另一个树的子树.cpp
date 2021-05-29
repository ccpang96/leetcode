/************************************************************************/
/*@File Name         : 572. ��һ����������.cpp
/*@Created Date      : 2020/6/1 8:42
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����ʹ�õݹ��˼·���ֱ��ж�(s,t)��(s->right,t)��(s->left,t).Ȼ����ú����ж��������Ƿ����.
//����s�ϵ�ÿ���㶼Ҫ��t����ƥ�䣬��ƥ��һ�εĴ�����O(t)�����Խ���ʱ�临�Ӷ���O(s*t);
//�ռ临�Ӷ��ǣ�max(ds,dt); //����ds����s����ȣ�dt����t�����
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
			return true;   //������������������
		if (s == nullptr)
			return false;  //s�ǿ����Ļ�����ֱ�ӷ���false
		return isSubTree(s->left, t) || isSubTree(s->right, t) || isSubTreeWithRoot(s, t);
	}
	bool isSubTreeWithRoot(TreeNode *s, TreeNode* t) {
		//�����������ж���s��һ���ڵ�ͽڵ���������ﶼ��t���
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr || s->val != t->val)
			return false;
		return isSubTreeWithRoot(s->left, t->left) && isSubTreeWithRoot(s->right, t->right);
	}
};

 

