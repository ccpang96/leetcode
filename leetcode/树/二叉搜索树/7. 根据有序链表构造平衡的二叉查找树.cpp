/************************************************************************/
/*@File Name         : 7. 根据有序链表构造平衡的二叉查找树.cpp
/*@Created Date      : 2020/6/14 20:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 链表转换为BST与有序数组转换为BST的相同之处都是在于找到中点，作为BST的根节点，然后再递归
本题中一个比较妙的方法在于使用快慢指针来找到链表的中点。
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
		if (head == nullptr)	//这里的head判断是判断链表到达了边界
			return nullptr;

		//此处使用快慢指针方法来确定链表的中点
		ListNode* slow_ptr = head;
		ListNode* fast_ptr = head;
		ListNode* pre_ptr = nullptr;

		//当fast_ptr到达终点的时候，slow_ptr刚好到达链表的中点
		while (fast_ptr && fast_ptr->next) {
			pre_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}
		if (pre_ptr)
			pre_ptr->next = nullptr;	//设置左子树的边界，好让递归的时候返回

		TreeNode* root = new TreeNode(slow_ptr->val);
		root->left = sortedListToBST(head == slow_ptr?pre_ptr:head);
		root->right = sortedListToBST(slow_ptr->next);
		return root;
	}
};
 
