/************************************************************************/
/*@File Name         : 41.数据流中的中位数-hard.cpp
/*@Created Date      : 2020/7/11 15:33
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
#include<set>
using namespace std;


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		int count = pq_max.size() + pq_min.size();
		if (count & 1) { //奇数  插入大顶堆
			if (!pq_min.empty() && num > pq_min.top()) {
				int temp = pq_min.top();
				pq_min.pop();
				pq_min.push(num);
				num = temp;
			}
			pq_max.push(num);
		}
		else {		//插入小顶堆
			if (!pq_max.empty() && num < pq_max.top()) {
				int temp = pq_max.top();
				pq_max.pop();
				pq_max.push(num);
				num = temp;
			}
			pq_min.push(num);
		}
	}

	double findMedian() {
		int count = pq_max.size() + pq_min.size();
		if (count & 1) {
			return pq_max.size() > pq_min.size() ? pq_max.top() : pq_min.top();
		}
		else {
			return double(pq_max.top() + pq_min.top()) / 2.0;
		}
	}
private:
	priority_queue<int, vector<int>, less<int>>pq_max;   //大顶堆  顶部元素最大
	priority_queue<int, vector<int>, greater<int>>pq_min;   //小顶堆  顶部元素最小


};