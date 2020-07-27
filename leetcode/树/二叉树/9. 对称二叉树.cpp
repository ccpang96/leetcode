struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr) {}
};

bool check(TreeNode* p, TreeNode* q) {
	if (!p && !q)   //pºÍq¾ùÎª¿Õ
		return true;
	if (!p || !q)
		return false;
	if (p->val == q->val)
		return check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
	if (check(root, root))
		return true;
	else
		return false;

}

