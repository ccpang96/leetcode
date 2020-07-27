
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
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return nullptr;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* first = dummy;
		ListNode* second = dummy;
		//让快指针先走
		int i = 0;
		while (i < n) {
			first = first->next;
			i++;
		}

		while (first->next != nullptr) {  //不能走过
			first = first->next;
			second = second->next;
		}

		second->next = second->next->next;

		second = nullptr;
		first = dummy->next;
		delete dummy;
		return first;
	}
};