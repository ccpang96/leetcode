/*
	链表的倒数第k个节点：先让快指针走k步，然后再将快慢指针一起走，直到快指针到达链表尾部
*/



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

class Solution {
public:
	ListNode * getKthFromEnd(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* quick = dummy;
		ListNode* slow = dummy;
		while (k > 0 && quick) {
			quick = quick->next;
			k--;
		}

		if (k > 0)
			return nullptr;

		while (quick) {
			quick = quick->next;
			slow = slow->next;
		}

		delete dummy;
		return slow;
	}
};