/************************************************************************/
/*@File Name         : 417. 太平洋大西洋水流问题.cpp
/*@Created Date      : 2020/5/24 16:33
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 这一题还是从边界出发，对边界上的进行DFS遍历，只不过要同时遍历两个方向，一个是大西洋，一个是太平洋，分别从这两个方向去找
比当前值小的点。
/************************************************************************/


/* Includes *************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 
/************************************************************************/
/*@ Problem Name         : 417. 太平洋大西洋水流问题
/*@ Description 		 :给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
*************************************************************************
/*@ Example1-Input	 	 : 
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：
/************************************************************************/

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return matrix;

		vector<vector<int>> result;

		int m = matrix.size();
		int n = matrix[0].size();

		//先对靠近太平洋的边界点进行DFS搜索，对太平洋可达到的点标记为true
		vector<vector<bool>>canRechT(m, vector<bool>(n, false));
		vector<vector<bool>>canRechD(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			dfs(canRechT, matrix, i, 0);		//左边一列
			dfs(canRechD, matrix, i, n - 1);	//右边一列
		}
		for (int j = 0; j < n ; j++) {			//这里为什么不是j= 0; j < n-1,如果是这样，就会出错
			dfs(canRechT, matrix, 0, j);		//上边一行
			dfs(canRechD, matrix, m - 1, j);	//下边一行
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (canRechT[i][j] && canRechD[i][j]) {
					result.push_back(vector<int>{i, j});
				}
			}
		}
		return result;
	}

	void dfs(vector<vector<bool>>& canRech, vector<vector<int>>& matrix, int cur_i, int cur_j) {
		if (canRech[cur_i][cur_j])
			return;
	
		canRech[cur_i][cur_j] = true;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };

		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + dx[index], next_j = cur_j + dy[index];
			if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || matrix[cur_i][cur_j] > matrix[next_i][next_j])
				continue;
			dfs(canRech, matrix, next_i, next_j);
		}
	}


};