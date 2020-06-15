/************************************************************************/
/*@File Name         : 非递归中序遍历.cpp
/*@Created Date      : 2020/6/10 16:32
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 树的中序遍历 根节点 左子树 右子树
/************************************************************************/

//思路

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>result;
		if (!root)
			return result;
		stack<TreeNode*>stack1;
		TreeNode* cur = root;

		while (cur != nullptr || !stack1.empty()) {
			while (cur != nullptr) {
				stack1.push(cur);
				cur = cur->left;
			}
			if (!stack1.empty()) {
				cur = stack1.top();
				stack1.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}
};


class Input {
public:
	void trimLeftTrailingSpaces(string &input) {
		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
			return !isspace(ch);
		}));
	}

	void trimRightTrailingSpaces(string &input) {
		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), input.end());
	}

	//将输入的一行数构建为二叉树
	TreeNode* stringToTreeNode(string input) {
		trimLeftTrailingSpaces(input);
		trimRightTrailingSpaces(input);
		input = input.substr(1, input.length() - 2);
		if (!input.size()) {
			return nullptr;
		}

		string item;
		stringstream ss;
		ss.str(input);

		getline(ss, item, ',');
		TreeNode* root = new TreeNode(stoi(item));
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);

		while (true) {
			TreeNode* node = nodeQueue.front();
			nodeQueue.pop();

			if (!getline(ss, item, ',')) {
				break;
			}

			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int leftNumber = stoi(item);
				node->left = new TreeNode(leftNumber);
				nodeQueue.push(node->left);
			}

			if (!getline(ss, item, ',')) {
				break;
			}

			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int rightNumber = stoi(item);
				node->right = new TreeNode(rightNumber);
				nodeQueue.push(node->right);
			}
		}
		return root;
	}
};



//int main() {
//	string input = "[1, null, 2, 3]";
//	TreeNode* root = Input().stringToTreeNode(input);
//	vector<int>result = Solution().inorder(root);
//	for (auto &m : result)
//		cout << m << "  ";
//	cout << endl;
//
//	cout << "ccpang" << endl;
//	system("pause");
//	return 0;
//}