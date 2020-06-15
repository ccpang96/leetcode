/************************************************************************/
/*@File Name         : m18.ɾ�������еĽڵ�(�����ǽڵ�ֵ).cpp
/*@Created Date      : 2020/6/11 10:17
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

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
	ListNode * deleteNode(ListNode* head, int val) {
		//��ɾ���Ľڵ㲻��β�ڵ�Ҳ����ֻ��һ���ڵ��ͷ�ڵ�
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		dummy->next = head;

		while (cur && cur->next) {
			if (cur->next->val == val) {
				cur->next = cur->next->next;
				break;
			}
			cur = cur->next;
		}
		cur = dummy->next;
		delete dummy;
		return cur;
	}
};
