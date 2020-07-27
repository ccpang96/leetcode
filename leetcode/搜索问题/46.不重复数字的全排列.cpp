/************************************************************************/
/*@File Name         : 46.不重复数字的全排列.cpp
/*@Created Date      : 2020/7/4 7:45
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 
/************************************************************************/


/* Includes *************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>

#include<unordered_set>
using namespace std;


//决策树的遍历过程
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>result;
		if (nums.empty())
			return result;
		vector<int>track;
		unordered_set<int>set1;
		backtrack(result, set1, track, nums);
		return result;
	}

	void backtrack(vector<vector<int>>&result, unordered_set<int>&set1, vector<int>& track, vector<int>& nums) {

		if (track.size() == nums.size()) {
			result.push_back(track);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {


			if (set1.find(nums[i]) != set1.end()) //该元素已经访问过，直接退出循环
				continue;

			track.push_back(nums[i]);
			set1.insert(nums[i]);

			backtrack(result, set1, track, nums);

			track.pop_back();
			set1.erase(nums[i]);
		}
	}
};



//int main() {
//
//	vector<int> nums = { 1,2,3 };
//	vector<vector<int>>result = Solution().permute(nums);
//	system("pause");
//	return 0;
//}
//