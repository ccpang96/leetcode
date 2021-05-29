
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




//迭代法
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
		return pre;	//记住返回的是pre
	}
};

//递归法:这是个难点和重点
ListNode* reverseList(ListNode* head) {
	if(head == nullptr)
		return head; //这个是用来判空输入的
	
	
	if (head->next == nullptr) {
		return head;
	}

	ListNode* p = reverseList(head->next);
	head->next->next = head; //让head的下一个节点指向自己 4的next是5，让5指向4
	head->next = nullptr;  //断开4到5的连接
	return p;  //这个cur一直是5
};


*/