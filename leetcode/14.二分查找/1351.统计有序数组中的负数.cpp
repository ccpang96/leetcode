/*
����һ�� m * n �ľ��� grid�������е�Ԫ�������ǰ��л��ǰ��У����Էǵ���˳�����С�

����ͳ�Ʋ����� grid �� ���� ����Ŀ��


�����ҡ����ϵ�С�������μ�С��.����
*/


#include<vector>
using namespace std;

class Solution {
public:
	//ͳ�Ƹ���������
	int countNegatives(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += count(grid[i]);
		}
		return sum;
	}


	int count(vector<int>&row) {
		//���һ��С��0�������ڵ�����ֵ
		int l = 0, r = row.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (row[mid] < 0) r = mid;
			else l = mid+1;
		}
		return l;
	}
 
};