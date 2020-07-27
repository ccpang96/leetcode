/************************************************************************/
/*@File Name         : 奇数升序偶数降序的链表重新升序.cpp
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

		ListNode* even = evenHead; //保存偶数链表的头部，以后为了反转
								   //奇数偶数链表分离
		while (oddHead && evenHead) {
			oddHead->next = evenHead->next; //奇数头指针指向下一个奇数
			oddHead = oddHead->next;		//偶数
			if (oddHead) {
				evenHead->next = oddHead->next;
					evenHead = evenHead->next;
			}
		}

		//反转偶数链表
		ListNode * reserved = nullptr;
		ListNode * node = nullptr;
		while (even) {
			node = even->next;  //先保存下一个节点
			even->next = reserved;
			reserved = even;
			even = node;
		}

		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;


		//开始对两个链表进行排序
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



	//将一组数string转换为vector
	vector<int> stringToIntegerVector(string input) {
		vector<int>output;
		//trimLeftTrailingSpaces(input); //去除左侧空格
		//trimRightTrailingSpaces(input); //去除右侧空格
		input = input.substr(1, input.length() - 2); //截取其中的长度
		stringstream ss;
		ss.str(input);
		string item;
		char delim = ',';  //界定符
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}
		return output;
	}

	//将string转换为ListNode
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