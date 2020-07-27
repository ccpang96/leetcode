/************************************************************************/
/*@File Name         : 34.�����������в���Ԫ�صĵ�һ�������һ��λ��.cpp
/*@Created Date      : 2020/7/16 16:09
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

 

class Solution {
public:
	vector<int>searchRange(vector<int>input, int target) {
		vector<int>result{ -1,-1 };
		int left = 0;
		int right = input.size() - 1;
		//Ѱ����߽�
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (input[mid] < target) {
				left = mid;
			}
			else if (input[mid] > target) {
				right = mid - 1;
			}
			else {
				if (mid-1 >= 0 && input[mid - 1] == target)
					right = mid;
				else {
					result[0] = mid;
					break;
				}
			}
		}

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (input[mid] < target) {
				left = mid;
			}
			else if (input[mid] > target) {
				right = mid - 1;
			}
			else {
				if (mid+1 < input.size() && input[mid + 1] == target)
					left = mid;
				else {
					result[1] = mid;
					break;
				}

			}
		}
		return result;
	}
};

//int main() {
//
//	vector<int>input{ 5,7,7,8,8,10 };
//	int target = 8;
//	vector<int>result = Solution().searchRange(input, target);
//	system("pause");
//	return 0;
//}