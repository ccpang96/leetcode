
/************************************************************************/
/*@ Problem Name         : 7.重建二叉树
/*@ Description 		 :输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树.
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*************************************************************************/

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
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty())
			return nullptr;
		TreeNode* root = new TreeNode(pre[0]);

		//在中序遍历中找到根节点的位置
		int m = 0;
		for (int i = 0; i < vin.size(); i++) {
			if (vin[i] == pre[0]) {
				m = i; 
				break;
			}
		}

		//得到左子树和右子树数组的前序和中序遍历

		vector<int>left_pre, right_pre, left_vin, right_vin;
		for (int i = 0; i < m; i++) {
			left_vin.push_back(vin[i]); //左子树的中序遍历
			left_pre.push_back(pre[i + 1]); //左子树的前序遍历
		}

		for (int i = m + 1; i < vin.size(); i++) {
			right_vin.push_back(vin[i]); //右子树的中序遍历
			right_pre.push_back(pre[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};
 
