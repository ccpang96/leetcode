//判断一颗二叉树是对称的
//时间复杂度：最多调用N/2次isSymmetrical递归函数，所以是O（N），N是二叉树的节点数量，
//空间复杂度：最差情况下，二叉树退化为单链表，递归使用O（N）的空间
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}

	bool isSymmetrical(TreeNode*pRoot1, TreeNode*pRoot2) {
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right) &&
			isSymmetrical(pRoot1->right, pRoot2->right);
	}
};