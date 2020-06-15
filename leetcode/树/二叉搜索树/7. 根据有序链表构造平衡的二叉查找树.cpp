/************************************************************************/
/*@File Name         : 7. ��������������ƽ��Ķ��������.cpp
/*@Created Date      : 2020/6/14 20:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����ת��ΪBST����������ת��ΪBST����֮ͬ�����������ҵ��е㣬��ΪBST�ĸ��ڵ㣬Ȼ���ٵݹ�
������һ���Ƚ���ķ�������ʹ�ÿ���ָ�����ҵ�������е㡣
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

//


class Solution {
public:
	TreeNode * sortedListToBST(ListNode* head) {
		if (head == nullptr)	//�����head�ж����ж��������˱߽�
			return nullptr;

		//�˴�ʹ�ÿ���ָ�뷽����ȷ��������е�
		ListNode* slow_ptr = head;
		ListNode* fast_ptr = head;
		ListNode* pre_ptr = nullptr;

		//��fast_ptr�����յ��ʱ��slow_ptr�պõ���������е�
		while (fast_ptr && fast_ptr->next) {
			pre_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}
		if (pre_ptr)
			pre_ptr->next = nullptr;	//�����������ı߽磬���õݹ��ʱ�򷵻�

		TreeNode* root = new TreeNode(slow_ptr->val);
		root->left = sortedListToBST(head == slow_ptr?pre_ptr:head);
		root->right = sortedListToBST(slow_ptr->next);
		return root;
	}
};
 
