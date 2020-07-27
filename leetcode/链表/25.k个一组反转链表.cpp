
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
	ListNode(int x) :val(x), next(nullptr) { }
};




class Solution {
public:
	pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {

		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		return { head,tail };
	}
	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode*dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* tail = dummy;

		while (head) {
			for (int i = 0; i < k; i++) {
				tail = tail->next;
				if (!tail)
					return dummy->next;
			}

			ListNode* next = tail->next;
			pair<ListNode*, ListNode*>result = reverse(head, tail);
			head = result.second;
			tail = result.first;

			pre->next = head;
			tail->next = next;	//这一步可以省略 
			pre = tail;
			head = next;
		}
		return dummy->next;
	}



};

class Input {
public:
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
};



//int main() {
//
//	string input = "[1,2,3,4,5]";
//	ListNode* head = Input().stringToListNode(input);
//	head = Solution().reverseKGroup(head, 2);
//	system("pause");
//	return 0;
//}
