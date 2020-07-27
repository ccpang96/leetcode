


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//����ָ�룺�ҵ��м�ڵ�
		ListNode* first = head;
		ListNode* second = head;
		while (second &&second->next) {
			second = second->next->next;
			first = first->next;
		}

		//��ת����
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