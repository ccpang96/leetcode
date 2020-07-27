/************************************************************************/
/*@File Name         : ��������ż�������������������.cpp
/*@Created Date      : 2020/7/8 10:17
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
	ListNode* isPalindrome(ListNode* head) {
	
		ListNode* oddHead = nullptr;
		ListNode* evenHead = nullptr;
	
		if (head && head->next) {
			oddHead = head;
			evenHead = head->next;
		}

		ListNode* even = evenHead; //����ż�������ͷ�����Ժ�Ϊ�˷�ת
								   //����ż���������
		while (oddHead && evenHead) {
			oddHead->next = evenHead->next; //����ͷָ��ָ����һ������
			oddHead = oddHead->next;		//ż��
			if (oddHead) {
				evenHead->next = oddHead->next;
					evenHead = evenHead->next;
			}
		}

		//��תż������
		ListNode * reserved = nullptr;
		ListNode * node = nullptr;
		while (even) {
			node = even->next;  //�ȱ�����һ���ڵ�
			even->next = reserved;
			reserved = even;
			even = node;
		}

		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;


		//��ʼ�����������������
		while (head && reserved) {
			if (head->val <= reserved->val) {
				cur->next = head;
				head = head->next;
			}
			else
			{
				cur->next = reserved;
				reserved = reserved->next;
			}
			cur = cur->next;
		}
		if (head) {
			cur->next = head;
		}
		if (reserved) {
			cur->next = reserved;
		}
		head = dummy->next;
		delete dummy;
		return head;
	}



	//��һ����stringת��Ϊvector
	vector<int> stringToIntegerVector(string input) {
		vector<int>output;
		//trimLeftTrailingSpaces(input); //ȥ�����ո�
		//trimRightTrailingSpaces(input); //ȥ���Ҳ�ո�
		input = input.substr(1, input.length() - 2); //��ȡ���еĳ���
		stringstream ss;
		ss.str(input);
		string item;
		char delim = ',';  //�綨��
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}
		return output;
	}

	//��stringת��ΪListNode
	ListNode* stringToListNode(string input) {

		vector<int>list = stringToIntegerVector(input);
		ListNode* dummyHead = new ListNode(0);
		ListNode *curr = dummyHead;

		for (auto item : list) {
			curr->next = new ListNode(item);
			curr = curr->next;
		}
		curr = dummyHead->next;
		delete dummyHead;
		return curr;
	}

	string listNodeToString(ListNode* node) {
		if (node == nullptr)
			return "[]";
		string result;
		while (node) {
			result += std::to_string(node->val) + ",";
			node = node->next;
		}
		return "[" + result.substr(0, result.length() - 1) + "]";
	}
};



//int main() {
//	string input = "[1,8,3,6,5,4,7,2,9]";
//	ListNode* head = stringToListNode(input);
//
//	head = Solution().isPalindrome(head);
//	string result = listNodeToString(head);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}