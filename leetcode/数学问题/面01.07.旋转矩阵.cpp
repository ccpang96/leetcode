/************************************************************************/
/*@File Name         : 面01.07.旋转矩阵.cpp
/*@Created Date      : 2020/7/11 9:07
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :  给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
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
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix[0].size();

		for (int i = 0; i < n / 2; i++) {   //沿对角线深入下去
			for (int k = 0; k < (n + 1) / 2; k++) { //每次交换的对象，k表示的是不断变化的这一列 而i代表的是行的概念
				int temp = matrix[i][k];
				matrix[i][k] = matrix[n - 1 - k][i]; //用左下角的值替换右左上角
				matrix[n - 1 - k][i] = matrix[n - 1 - i][n - 1 - k];
				matrix[n - 1 - i][n - 1 - k] = matrix[k][n - 1 - i];
				matrix[k][n - 1 - i] = temp;
			}
		}
	}
};

//int main() {
//	vector<vector<int>> matrix{ {1,2,3}, {4,5,6 }, { 7,8,9 } };
//	Solution().rotate(matrix);
//
//	system("pause");
//	return 0;
//}