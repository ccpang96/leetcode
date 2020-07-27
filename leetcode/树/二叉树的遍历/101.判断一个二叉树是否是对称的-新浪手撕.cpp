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
	bool isSymmetric(TreeNode* root) {
		if (check(root, root))
			return true;
		else
			return false;


	}

	bool check(TreeNode* p, TreeNode* q) {
		if (!p && !p)
			return true;
		if (!p || !q)
			return false;
		if (p->val == q->val)
			return check(p->left, q->right) && check(p->right, q->left);
		else
			return false;
	}
};