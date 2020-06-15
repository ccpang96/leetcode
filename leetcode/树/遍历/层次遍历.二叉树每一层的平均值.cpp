/************************************************************************/
/*@File Name         : ��α���.cpp
/*@Created Date      : 2020/6/14 9:06
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ���ǿն�����, ����һ����ÿ��ڵ�ƽ��ֵ��ɵ�����.
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
		//�����쳣ֵ����
		if (!root)
			return result;
		int cur = 1;	//����ǰ�������
		int next = 0;	//������һ�������
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

			if (cur == 0) { //��ǰ���������
				result.push_back(double(sum) / double(numbers));
				cur = next;
				numbers = next;	//������һ�������
				sum = 0; //����Ϊ0
				next = 0;

			}
		}
		return result;
	}
};