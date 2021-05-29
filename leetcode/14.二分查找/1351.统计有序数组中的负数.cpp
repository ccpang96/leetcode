/*
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。

请你统计并返回 grid 中 负数 的数目。


从左到右、从上到小都是依次减小的.所以
*/


#include<vector>
using namespace std;

class Solution {
public:
	//统计负数的数量
	int countNegatives(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += count(grid[i]);
		}
		return sum;
	}


	int count(vector<int>&row) {
		//求第一个小于0的数所在的索引值
		int l = 0, r = row.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (row[mid] < 0) r = mid;
			else l = mid+1;
		}
		return l;
	}
 
};