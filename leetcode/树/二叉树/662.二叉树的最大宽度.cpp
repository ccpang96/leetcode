/*
	给定一个二叉树，获取二叉树的宽度.
	树的宽度是所有层的最大宽度，这个二叉树与满二叉树结构相同，但是有一些节点为空.
*/
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
	//思路：给每个节点进行编号，然后最大宽度就是这一层最右边节点的编号-最左边节点编号+1
	int widthOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		queue<pair<TreeNode*, unsigned long long >>q;
		q.push({ root,1 });
		int ans = 0;
		while (!q.empty()) {
			int sz = q.size();
			ans = max(int(q.back().second - q.front().second + 1), ans);

			for (int i = 0; i < sz; i++) {
				unsigned long long pos = q.front().second;
				TreeNode *node = q.front().first;
				q.pop();
				if (node->left) q.push({ node->left,2 * pos });
				if (node->right) q.push({ node->right,2 * pos + 1 });
			}
		}
		return ans;
	}
};
 