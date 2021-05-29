/*
	给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
	输入: 1->2->3->3->4->4->5
	输出: 1->2->5
*/

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

//定义一个dummy头节点，链接上原链表，cur指向原链表

/*
class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		while (cur &&cur->next) {
			(cur->val == cur->next->val) { //第一次发现重复元素
				while (cur->next && cur->val == cur->next->val) {
					cur = cur->next;
				}
				pre->next = cur->next; //指向第一个不为重复元素的链表节点
				cur = cur->next;
			}
			else { //如果没有发现重复链表节点
				pre = cur;
				cur = cur->next;

			}
		}

		return dummy->next;
	}
};*/