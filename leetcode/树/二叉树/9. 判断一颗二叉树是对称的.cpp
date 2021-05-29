//�ж�һ�Ŷ������ǶԳƵ�
//ʱ�临�Ӷȣ�������N/2��isSymmetrical�ݹ麯����������O��N����N�Ƕ������Ľڵ�������
//�ռ临�Ӷȣ��������£��������˻�Ϊ�������ݹ�ʹ��O��N���Ŀռ�
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