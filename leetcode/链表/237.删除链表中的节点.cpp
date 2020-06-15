/************************************************************************/
/*@File Name         : 237.ɾ�������еĽڵ�.cpp
/*@Created Date      : 2020/6/11 9:51
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

//ʹ��O(1)��ʱ�临�Ӷ�ɾ���ڵ�
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

 
//��head������ɾ��node�ڵ㣬node�ڵ�һ����head�������
ListNode*  deleteNode(ListNode* head, ListNode* node){
	//ɾ���Ĳ���β�ڵ�,ֱ�ӽ���ɾ���ڵ����һ���ڵ㸲��ɾ���ڵ�
	if (node->next != nullptr) {
		ListNode* next = node->next;
		node->val = next->val;
		node->next = next->next;

		delete next;
		next = nullptr;
	}

	//ɾ������ͷ�ڵ������β�ڵ�O(n)
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
