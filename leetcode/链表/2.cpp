
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




//������
class Solution {
public:
	ListNode * reverseList(ListNode* head) {

		ListNode *pre = nullptr;
		ListNode *next = nullptr;
		while (head  != nullptr) {
			next = head->next;
			head->next = pre;

			pre = head;
			head = next;
		}
		return pre;	//��ס���ص���pre
	}
};

//�ݹ鷨:���Ǹ��ѵ���ص�
ListNode* reverseList(ListNode* head) {
	if(head == nullptr)
		return head; //����������п������
	
	
	if (head->next == nullptr) {
		return head;
	}

	ListNode* p = reverseList(head->next);
	head->next->next = head; //��head����һ���ڵ�ָ���Լ� 4��next��5����5ָ��4
	head->next = nullptr;  //�Ͽ�4��5������
	return p;  //���curһֱ��5
};


*/