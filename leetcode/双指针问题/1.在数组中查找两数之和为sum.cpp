#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 //思路：先快排，再双指针查找，再返回索引值下标
class Solution {
public:
	vector<int> twoSum(vector<int>& array, int sum) {
		vector<int>result;
		if (array.size() < 2)
			return result;
		//快排
		vector<int>temp = array;
		qsort(temp, 0, temp.size() - 1);
		int left = 0; int right = temp.size() - 1;

		while (left < right) {
			if (temp[left] + temp[right] == sum) {
				result.push_back(temp[left]);
				result.push_back(temp[right]);
				break;
			}
			else if (temp[left] + temp[right] > sum) {
				right--;
			}
			else
				left++;
		}
		int i = -1, j = -1;
		if (!result.empty()) {
			for (int k = 0; k < array.size(); k++) {
				if (array[k] == result[0] && k != j && i == -1)
					i = k;
				if (array[k] == result[1] && k != i && j == -1)
					j = k;
				if (i != -1 && j != -1) {
					result[0] = min(i, j);
					result[1] = max(i, j);
					break;
				}
			}
			return result;

		}
		else
			return result;
	}


	void qsort(vector<int>& array, int start, int end) {
		if (start >= end)
			return;
		//随机化防止O(n)的递归
		int pos = rand() % (end - start) + start;
		swap(array[end], array[pos]);

		int index = partition(array, start, end);
		if (index > start)
			qsort(array, start, index - 1);
		if (index < end)
			qsort(array, index + 1, end);
	}

	int partition(vector<int>& array, int start, int end) {
		int small = start - 1;
		for (int index = start; index < end; index++) {
			if (array[index] < array[end]) {
				small++;
				if (small != index)
					swap(array[small], array[index]);
			}

		}
		small++;
		swap(array[small], array[end]);
		return small;
	}
};

