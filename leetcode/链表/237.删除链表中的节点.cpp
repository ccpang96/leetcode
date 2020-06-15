/************************************************************************/
/*@File Name         : 237.删除链表中的节点.cpp
/*@Created Date      : 2020/6/11 9:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

//使用O(1)的时间复杂度删除节点
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

 
//从head链表中删除node节点，node节点一定在head链表汇总
ListNode*  deleteNode(ListNode* head, ListNode* node){
	//删除的不是尾节点,直接将待删除节点的下一个节点覆盖删除节点
	if (node->next != nullptr) {
		ListNode* next = node->next;
		node->val = next->val;
		node->next = next->next;

		delete next;
		next = nullptr;
	}

	//删除的是头节点或者是尾节点O(n)
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* cur = dummy;
	
	while (cur && cur->next) {
		
		if (cur->next == node) {
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}


	cur = dummy->next;
	delete dummy;
	return cur;
}
