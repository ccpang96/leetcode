/*
	其他数字都出现2次，只有2个数字出现一次，找到出现1次的这两个数字.
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		if (nums.empty())
			return {};
		int res = 0;
		int a = 0, b = 0;
		for (auto &m : nums)  //得到所有数的异或值
			res ^= m;
		int div = 1;  //找出分出这个两个数的某一位
		while ((div & res) == 0)
			div = div << 1;
		for (auto &n : nums) {
			if (n &div)
				a ^= n;
			else
				b ^= n;
		}
		return { a,b };
	}
};