/************************************************************************/
/*@File Name         : 662.�������������.cpp
/*@Created Date      : 2020/7/5 8:34
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
	//˼·����ÿ���ڵ���б�ţ�Ȼ������Ⱦ�����һ�����ұ߽ڵ�ı��-����߽ڵ���+1
	int widthOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		queue<pair<TreeNode*, int>>q;
		q.push({ root,1 });
		int ans = 0;
		while (!q.empty()) {
			int sz = q.size();
			ans = max(q.back().second - q.front().second + 1, ans);

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