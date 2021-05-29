/*
	找到数组中重复的数字

*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return 0 ;

		//3 2 3 0  -> 0 2 3 3 ->0 3 2 3 ->  
		//如果数字都在0~n-1范围内，nums[i]变到nums[nums[i]]上
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) {
					return nums[i];
				}

				int temp = nums[i];   //假如第0个数是3
				nums[i] = nums[temp];  //将0附给第0个位置
				nums[temp] = temp;   //将3附给第3个位置
			}
		}
		return -1;
	}
};