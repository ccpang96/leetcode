/************************************************************************/
/*@File Name         : 52.两个链表的第一个公共节点.cpp
/*@Created Date      : 2020/6/12 15:25
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 求两个单向链表的第一个公共节点：只需要让长的链表先走diff步，然后当两个链表第一次相等时的节点就是
/* 第一个公共节点。
/************************************************************************/

/*
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

class Solution {
public:
	ListNode * getIntersectionNode(ListNode* head1, ListNode* head2) {
		if (!head1 || !head2)
			return nullptr;
		int head1Length = 0, head2Length = 0;
		ListNode* cur1 = head1;
		ListNode* cur2 = head2;
		while (cur1) {
			cur1 = cur1->next;
			head1Length++;
		}
		while (cur2) {
			cur2 = cur2->next;
			head2Length++;
		}

		ListNode* pShort = head1;
		ListNode* pLong = head2;
		if (head1Length > head2Length) {
			pShort = head2;
			pLong = head1;
		}

		int diff = abs(head1Length - head2Length);
		while (diff > 0) {
			pLong = pLong->next;
			diff--;
		}
		while (pLong != nullptr && pShort != nullptr && pLong != pShort) {
			pLong = pLong->next;
			pShort = pShort->next;
		}
		return pLong;
	}
};

*/
//空间复杂度O(n+m)：这种方法不好
//class Solution {
//public:
//	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == nullptr || pHead2 == nullptr)
//			return nullptr;
//		ListNode*result = nullptr;
//		stack<ListNode*>stack1;
//		stack<ListNode*>stack2;
//
//		stack1.push(pHead1);
//		while (pHead1->next) {
//			pHead1 = pHead1->next;
//			stack1.push(pHead1);
//		}
//
//		stack2.push(pHead2);
//		while (pHead2->next) {
//			pHead2 = pHead2->next;
//			stack2.push(pHead2);
//		}
//
//		
//		while (!stack1.empty() && !stack2.empty()) {
//			
//			if (stack2.top() == stack1.top()) {
//				result = stack1.top();
//				stack1.pop();
//				stack2.pop();
//			}
//			else
//			{
//				break;
//			}
//		}
//		return result;
//	}
//};


