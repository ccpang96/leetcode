/*
	�ҵ��������ظ�������

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
		//������ֶ���0~n-1��Χ�ڣ�nums[i]�䵽nums[nums[i]]��
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) {
					return nums[i];
				}

				int temp = nums[i];   //�����0������3
				nums[i] = nums[temp];  //��0������0��λ��
				nums[temp] = temp;   //��3������3��λ��
			}
		}
		return -1;
	}
};