/************************************************************************/
/*@File Name         : 82.ɾ�����������е��ظ�Ԫ��(ֻ���ز��ظ���).cpp
/*@Created Date      : 2020/6/11 11:11
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

//����һ��dummyͷ�ڵ㣬������ԭ����curָ��ԭ����






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
			if (cur->val == cur->next->val) { //��һ�η����ظ�Ԫ��
				while (cur->next && cur->val == cur->next->val) {
					cur = cur->next;
				}
				pre->next = cur->next; //ָ���һ����Ϊ�ظ�Ԫ�ص�����ڵ�
				cur = cur->next;
			}
			else { //���û�з����ظ�����ڵ�
				pre = cur;
				cur = cur->next;

			}
		}

		return dummy->next;
	}
};