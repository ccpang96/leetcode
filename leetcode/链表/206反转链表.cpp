/************************************************************************/
/*@File Name         : 206反转链表.cpp
/*@Created Date      : 2020/7/4 9:17
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

 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};




//迭代法
class Solution {
public:
	ListNode * reverseList(ListNode* head) {

		ListNode *pre = nullptr;
		ListNode *next = nullptr;
		while (head  != nullptr) {
			next = head->next;
			head->next = pre;

			pre = head;
			head = next;
		}
		return pre;	//记住返回的是pre
	}
};

//递归法
ListNode* reverseList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode* p = reverseList(head->next);
	head->next->next = head; //让head的下一个节点指向自己
	head->next = nullptr;
	return p;
};


