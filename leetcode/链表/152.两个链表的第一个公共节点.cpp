//两个链表的第一个公共节点
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

	ListNode * getIntersectionNode(ListNode* l1, ListNode* l2) {
		if (!l1 || !l2)
			return nullptr;

		int length1 = 0, length2 = 0;
		ListNode*p = l1, *q = l2;
		while (!p) {
			length1++;
			p = p->next;
		}
		while (!q) {
			length2++;
			q = q->next;
		}

		ListNode* longList = l1, *shortList = l2;

		if (length1 < length2) {
			shortList = l1;
			longList = l2;
		}

		int diff = abs(length1 - length2);
		while (diff > 0) {
			longList = longList->next;
			diff--;
		}
		while (longList && shortList ) {
			if (longList == shortList) {
				return longList;
			}
			longList = longList->next;
			shortList = shortList->next;
		}

		return nullptr;
	}
};



 