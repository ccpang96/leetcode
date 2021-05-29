/*
用队列实现栈:que2起到暂时备份的作用，在将que1中最后一个元素end，pop出来的时候，先将end之前的元素放在que2中
//比如que1中元素： 3 2 1
//在将3pop时，先将2 1放到que2中，然后将3pop出去后，再将2 1 附给que1
*/

#include<queue>
using namespace std;

class MyStack {

	queue<int>que1;
	queue<int>que2;
public:
	MyStack() {

	}

	void push(int x) {
		que1.push(x);
	}

	int pop() {
		int size = que1.size();
		while (size > 1) {
			int x = que1.front(); //从队列1中弹出，放入队列2中暂时存储
			que1.pop();
			que2.push(x);
			size--;
		}
		int val = que1.front(); //待pop出的元素
		que1.pop();

		que1 = que2;

		while (!que2.empty()) {
			que2.pop();
		}

		return val;
	}

	int top() {

		return que1.back();
	}

	bool empty() {
		return que1.empty();
	}
};
