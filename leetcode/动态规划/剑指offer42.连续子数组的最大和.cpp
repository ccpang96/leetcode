/************************************************************************/
/*@File Name         : 剑指offer42.连续子数组的最大和.cpp
/*@Created Date      : 2020/7/8 9:03
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
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int>dp(nums.size() + 1, 0);
		int max = INT_MIN;

		for (int i = 1; i <= nums.size(); i++) {
			if (dp[i - 1] > 0)
				dp[i] = dp[i - 1] + nums[i - 1];
			else
				dp[i] = nums[i - 1];

			if (dp[i] > max)
				max = dp[i];
		}
		return max;
	}
};