/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

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
		odd = head;  //奇链表的头节点
		even = evenHead = head->next; //偶链表的头节点

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
