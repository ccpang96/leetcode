
/************************************************************************/
/*@ Problem Name         : 7.�ؽ�������
/*@ Description 		 :����ĳ��������ǰ���������������Ľ�������ؽ����ö�����.
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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

		//������������ҵ����ڵ��λ��
		int m = 0;
		for (int i = 0; i < vin.size(); i++) {
			if (vin[i] == pre[0]) {
				m = i; 
				break;
			}
		}

		//�õ��������������������ǰ����������

		vector<int>left_pre, right_pre, left_vin, right_vin;
		for (int i = 0; i < m; i++) {
			left_vin.push_back(vin[i]); //���������������
			left_pre.push_back(pre[i + 1]); //��������ǰ�����
		}

		for (int i = m + 1; i < vin.size(); i++) {
			right_vin.push_back(vin[i]); //���������������
			right_pre.push_back(pre[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};
 
