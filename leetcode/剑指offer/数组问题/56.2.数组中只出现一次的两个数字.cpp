/*
	�������ֶ�����2�Σ�ֻ��2�����ֳ���һ�Σ��ҵ�����1�ε�����������.
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
		for (auto &m : nums)  //�õ������������ֵ
			res ^= m;
		int div = 1;  //�ҳ��ֳ������������ĳһλ
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