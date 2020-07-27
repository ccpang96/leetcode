/************************************************************************/
/*@File Name         : 141.判断一个链表中是否有环.cpp
/*@Created Date      : 2020/7/25 8:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 
/************************************************************************/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr)
			return false;
		bool found = false;

		ListNode* quick = head;
		ListNode* slow = head;
		//在环中某点相遇
		while (quick && quick->next) {
			quick = quick->next->next;
			slow = slow->next;
			if (quick == slow)
				break;
		}

		//判断是否到达末尾，如果到达说明链表无环
		if (quick == nullptr || quick->next == nullptr) {
			return false;
		}

		slow = head;
		while (slow && quick) {
			if (slow == quick) {
				found = true;
				break;
			}

			slow = slow->next;
			quick = quick->next;
		}
		return found;
	}
};