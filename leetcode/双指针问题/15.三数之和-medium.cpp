/************************************************************************/
/*@File Name         : 15.����֮��.cpp
/*@Created Date      : 2020/6/26 19:30
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��������ʹ��˫ָ�뷨�������ҵ����������ҵĹ����л�Ҫע�����ȥ�أ�
/*���Ӷȷ�����ʱ�临�Ӷ���O(N2),˫��ѭ�����ռ临�Ӷ���O(nlogn)�����ǿ��ŵĿռ临�Ӷȣ�������������ı����������飬����
�ռ临�Ӷ���O(N)
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
			if (nums[i] > 0) //��С��ֵ������0��
				break;
			if (i > 0 && nums[i] == nums[i - 1]) { //�Ե�һ����ȥ��,ֻ�е�i������0ʱ��ȥ��
				continue;
			}
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {  //˫��ѭ��
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0) {
					result.push_back(vector<int>{nums[i], nums[l], nums[r]});
					//��l����rȥ��
					while (l < r && nums[l] == nums[l + 1]) l++; //�Եڶ�����ȥ��
					while (l < r && nums[r] == nums[r - 1]) r--;//�Ե�������ȥ��
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