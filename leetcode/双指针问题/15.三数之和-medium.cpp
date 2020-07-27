/************************************************************************/
/*@File Name         : 15.三数之和.cpp
/*@Created Date      : 2020/6/26 19:30
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 先排序，再使用双指针法，进行找到三个数；找的过程中还要注意进行去重；
/*复杂度分析：时间复杂度是O(N2),双重循环。空间复杂度是O(nlogn)，这是快排的空间复杂度，但是我们排序改变了输入数组，所以
空间复杂度是O(N)
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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) //最小的值都大于0了
				break;
			if (i > 0 && nums[i] == nums[i - 1]) { //对第一个数去重,只有当i不等于0时才去重
				continue;
			}
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {  //双重循环
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0) {
					result.push_back(vector<int>{nums[i], nums[l], nums[r]});
					//对l或者r去重
					while (l < r && nums[l] == nums[l + 1]) l++; //对第二个数去重
					while (l < r && nums[r] == nums[r - 1]) r--;//对第三个数去重
					l++;
					r--;
				}
				else if (sum > 0) {
					r--;
				}
				else
					l++;
			}

		}
		return result;
	}
};