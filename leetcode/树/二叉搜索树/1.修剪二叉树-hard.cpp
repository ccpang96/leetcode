/************************************************************************/
/*@File Name         : 1.修建二叉树.cpp
/*@Created Date      : 2020/6/14 15:40
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
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
	TreeNode * trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr)
			return root;
		if (root->val > R)
			return trimBST(root->left, L, R);
		if (root->val < L)
			return trimBST(root->right, L, R);
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
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
//
//	string input = "[0,1,2]";
//	TreeNode* root = Input().stringToTreeNode(input);
//	TreeNode* result = Solution().trimBST(root,1,2);
//
//	system("pause");
//	return 0;
//}