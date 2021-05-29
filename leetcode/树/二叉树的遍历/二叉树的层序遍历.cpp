/*
	求出二叉树的层序遍历：使用queue
*/


#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>result;
		if (!root)
			return result;
		queue<TreeNode*>q1;
		q1.push(root);
		int next, cur; //分别用来代表下一层和当前层的节点个数
		vector<int>temp;
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			temp.push_back(node->val);
			q1.pop();
			cur--;
			if (node->left) {
				q1.push(node->left);
				next++;
			}
				
			if (node->right) {
				q1.push(node->right);
				next++;
			}
				

			if (cur == 0) {
				result.push_back(temp);
				cur = next;
				next = 0;
				temp.clear();
			}
		}
		return result;
	}
};