/************************************************************************/
/*@File Name         : 41.数组中第一个缺失的正整数.cpp
/*@Created Date      : 2020/7/8 16:25
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
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty())
			return 1;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
				swap(nums[i], nums[nums[i]]);
			}
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] != i)
				return i;
		}
		return nums[0] == n ? n+1:n;
	}
};


//int main() {
//	
//	vector<int> input = {0, 2,6,423,2,9 };
//	int result = Solution().firstMissingPositive(input);
//
//	system("pause");
//	return 0;
//}