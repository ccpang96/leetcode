/************************************************************************/
/*@File Name         : 695. 岛屿的最大面积.cpp
/*@Created Date      : 2020/5/21 14:07
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
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
/*@ Problem Name         : 695. 岛屿的最大面积
/*@ Description 		 :给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
*************************************************************************
/*@ Example1-Input	 	 :
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
/*@ Example1-Output		 : 6
/*@ Example1-Explanation :对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：
/************************************************************************/

class Solution {
public:
	int  dfs(vector<vector<int>>&grid,int i,int j) {

		//递归基判断
		if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1)
			return 0;

		grid[i][j] = 0;		//将访问过的岛屿置为0，其实按照模板这里应该设置一个二维visit数组
		int sum = 0;		//岛屿的和
		sum += 1;			//增加1


		//当前点的上下左右四个方向
		int dx[4] = { 1,-1,0,0 };		
		int dy[4] = { 0,0,1,-1 };

		for (int index = 0; index < 4; index++) {
			int next_i = i + dx[index];
			int next_j = j + dy[index];

			sum += dfs(grid, next_i, next_j);
		}
		return sum;
	}


	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
					result = max(dfs(grid, i, j),result);
			}
		}
		return result;
	}
};





 

/************************************************************************/
/*@FullName:  main
/*@Brief:      
/*@Parameter: 无
/*@Returns:   int 0
/*@time:      2020/5/21 14:11
/*@author:    ccpang
/************************************************************************/
 