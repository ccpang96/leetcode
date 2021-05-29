/*
	����ĵ�����k���ڵ㣺���ÿ�ָ����k����Ȼ���ٽ�����ָ��һ���ߣ�ֱ����ָ�뵽������β��
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