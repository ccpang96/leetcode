/************************************************************************/
/*@File Name         : 层次遍历.cpp
/*@Created Date      : 2020/6/14 9:06
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>result;
		//输入异常值处理
		if (!root)
			return result;
		int cur = 1;	//代表当前层的数量
		int next = 0;	//代表下一层的数量
		int numbers = cur;
		long long sum = 0;
		queue<TreeNode*>q1;
		q1.push(root);
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			q1.pop();

			cur--;
			sum += node->val;

			if (node->left) {
				q1.push(node->left);
				next++;
			}
			if (node->right) {
				q1.push(node->right);
				next++;
			}

			if (cur == 0) { //当前层遍历结束
				result.push_back(double(sum) / double(numbers));
				cur = next;
				numbers = next;	//保留这一层的总数
				sum = 0; //和清为0
				next = 0;

			}
		}
		return result;
	}
};