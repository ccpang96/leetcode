/************************************************************************/
/*@File Name         : 572. ��һ����������.cpp
/*@Created Date      : 2020/6/1 8:42
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 572. ��һ����������
/*@ Description 		 :


*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
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
	bool isSubTree(TreeNode* s, TreeNode *t) {
		if (t == nullptr) return true;
		if (s == nullptr) return false;
		return isSubTree(s->left, t) || isSubTree(s->right, t) || isSubTreeWithRoot(s, t);
	}
	bool isSubTreeWithRoot(TreeNode *s, TreeNode* t) {
		//�����������ж���s��һ���ڵ�ͽڵ���������ﶼ��t���
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr || s->val != t->val)
			return false;
		return isSubTreeWithRoot(s->left, t->left) && isSubTreeWithRoot(s->right, t->right);
	}
};

 

//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}

//�������һ��������Ϊ������
//TreeNode* stringToTreeNode(string input) {
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);
//	if (!input.size()) {
//		return nullptr;
//	}
//
//	string item;
//	stringstream ss;
//	ss.str(input);
//
//	getline(ss, item, ',');
//	TreeNode* root = new TreeNode(stoi(item));
//	queue<TreeNode*> nodeQueue;
//	nodeQueue.push(root);
//
//	while (true) {
//		TreeNode* node = nodeQueue.front();
//		nodeQueue.pop();
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int leftNumber = stoi(item);
//			node->left = new TreeNode(leftNumber);
//			nodeQueue.push(node->left);
//		}
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int rightNumber = stoi(item);
//			node->right = new TreeNode(rightNumber);
//			nodeQueue.push(node->right);
//		}
//	}
//	return root;
//}

 
