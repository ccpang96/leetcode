/*
�ö���ʵ��ջ:que2����ʱ���ݵ����ã��ڽ�que1�����һ��Ԫ��end��pop������ʱ���Ƚ�end֮ǰ��Ԫ�ط���que2��
//����que1��Ԫ�أ� 3 2 1
//�ڽ�3popʱ���Ƚ�2 1�ŵ�que2�У�Ȼ��3pop��ȥ���ٽ�2 1 ����que1
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
			int x = que1.front(); //�Ӷ���1�е������������2����ʱ�洢
			que1.pop();
			que2.push(x);
			size--;
		}
		int val = que1.front(); //��pop����Ԫ��
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
