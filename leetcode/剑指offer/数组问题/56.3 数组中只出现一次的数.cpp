/*
	有一个数出现1次，其他数都出现3次，找出只出现一次的那个数
	解法还是位运算：
*/

#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		
		for (int i = 0; i < 32; i++) { //遍历32位
			int count = 0;
			for (auto & m : nums) {  //遍历每个数的第i位
				if (m & (1 << i))
					count++;
			}
			if (count % 3 == 1)  //
				res = res ^  (1 << i);
		}
		return res;

	}
};


 