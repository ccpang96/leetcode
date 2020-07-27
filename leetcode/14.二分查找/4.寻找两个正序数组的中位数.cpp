/************************************************************************/
/*@File Name         : 4.Ѱ�����������������λ��.cpp
/*@Created Date      : 2020/7/25 15:05
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

//����ĳ��ȷֱ���m��n������λ����k = (m + n) /2 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int  m = nums1.size();
		int n = nums2.size(); 
		int length = m + n;
		if (length & 1)
			return findkth(nums1, nums2, length / 2 + 1);
		else
			return (double(findkth(nums1, nums2, length / 2) + findkth(nums1, nums2, length / 2 + 1)) / 2);
	}
	int findkth(vector<int>&nums1, vector<int>&nums2,int k) {
		int m = nums1.size();
		int n = nums2.size();
		int index1 = 0, index2 = 0;
		while (true) {
			if (index1 == m)
				return nums2[index2 + k - 1];
			if (index2 == m)
				return nums1[index1 + k - 1];
			if (k == 1)
				return min(nums1[index1], nums2[index2]);

			//�������
			int newIndex1 = min(index1 + k / 2 - 1, m - 1);
			int newIndex2 = min(index2 + k / 2 - 1, n - 1);
			int pivot1 = nums1[newIndex1];
			int pivot2 = nums2[newIndex2];

			//�Ƚ��������pivot1 ��pivot2֮��Ĵ�С��
			//���pivot1 <= pivot2�Ļ���
			if (pivot1 <= pivot2) {
				k -= newIndex1 - index1+ 1;  //��ȥ�Թ�����һ����
				index1 = newIndex1 + 1;
			}
			else {
				k -= newIndex2 - index2 + 1;
				index2 = newIndex2 + 1;
			}
		}

	}
};
