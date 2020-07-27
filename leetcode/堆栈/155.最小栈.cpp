

#include<stack>
using namespace std;
class MinStack {
public:
	void push(int x) {
		s1.push(x);
		if (!min_s.empty() && min_s.top() <= x)
			min_s.push(min_s.top());
		else
			min_s.push(x);
	}

	void pop() {
		s1.pop();
		min_s.pop();
	}

	int top() {
		if(!s1.empty())
			return s1.top();
		return -1;
	}

	int getMin() {
		if (!min_s.empty())
			return min_s.top();
		return -1;
	}
private:
	stack<int>s1;
	stack<int>min_s;
};