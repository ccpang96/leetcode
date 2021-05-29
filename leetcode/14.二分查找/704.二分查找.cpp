/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1
*/

#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if (nums[l] != target)
			return -1;
		else
			return l;
	}
};