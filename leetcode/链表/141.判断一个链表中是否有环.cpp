/************************************************************************/
/*@File Name         : 141.�ж�һ���������Ƿ��л�.cpp
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
		//�ڻ���ĳ������
		while (quick && quick->next) {
			quick = quick->next->next;
			slow = slow->next;
			if (quick == slow)
				break;
		}

		//�ж��Ƿ񵽴�ĩβ���������˵�������޻�
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