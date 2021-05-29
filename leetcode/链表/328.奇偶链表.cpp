/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

*/

 
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};
class Solution {
public:
	ListNode * oddEvenList(ListNode* head) {
		if (head == nullptr)
			return head;
		if (head->next == nullptr)
			return head;
		ListNode* even, *odd, *evenHead;
		odd = head;  //�������ͷ�ڵ�
		even = evenHead = head->next; //ż�����ͷ�ڵ�

		while (even && even->next) {
			odd->next = even->next;
			odd = odd->next;
			
			even->next = odd->next;
			even = even->next;
		}

		odd->next = evenHead;
		return head;
	}
};
