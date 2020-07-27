


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//快慢指针：找到中间节点
		ListNode* first = head;
		ListNode* second = head;
		while (second &&second->next) {
			second = second->next->next;
			first = first->next;
		}

		//反转链表
		ListNode* newHead = nullptr;
		ListNode* temp = nullptr;
		while (first) {
			temp = first->next;
			first->next = newHead;
			newHead = first;
			first = temp;
		}
		while (head &&newHead) {
			if (head->val != newHead->val)
				return false;
			head = head->next;
			newHead = newHead->next;
		}
		return true;
	}
};