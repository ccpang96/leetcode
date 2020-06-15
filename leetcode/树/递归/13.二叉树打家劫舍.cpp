/************************************************************************/
/*@File Name         : 13.间隔遍历.cpp
/*@Created Date      : 2020/6/14 7:52
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



//树形DP
class Solution {
public:

	int rob(TreeNode* root) {
		pair<int, int>ans = robhelp(root);	//first代表不抢劫当前节点，second代表抢劫当前节点
		return max(ans.first,ans.second);
	}

	pair<int, int> robhelp(TreeNode* root)
	{
		if (!root)   
			return make_pair(0,0);
		pair<int, int>l = robhelp(root->left), r = robhelp(root->right);
		return make_pair(max(l.first, l.second) + max(r.first, r.second), root->val + l.first + r.first); //不抢劫当前节点，抢劫当前节点
	}
};


//直接递归
class Solution1{
public:
	int rob(TreeNode* root) {
		if (!root)
			return 0;
		int val1 = root->val, val2 = 0;
		if (root->left)
			val1 += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val1 += rob(root->right->left) + rob(root->right->right);

		val2 += rob(root->left) + rob(root->right);

		return max(val1, val2);
	}
};

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

//int main() {
//	string input = "[3,2,3,null,3,null,1]";
//	TreeNode* root = stringToTreeNode(input);
//	int result = Solution1().rob(root);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}