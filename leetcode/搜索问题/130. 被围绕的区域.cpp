/************************************************************************/
/*@File Name         : 130. 被围绕的区域.cpp
/*@Created Date      : 2020/5/22 20:25
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
/*@ Problem Name         : 130. 被围绕的区域
/*@ Description 		 :给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：算法思路：对边界上的O点使用DFS算法进行遍历，将O和与O相连的点改为‘#’，然后再遍历整个岛屿，
将'#'改为'O',将'O'改为'X'.
/************************************************************************/

class Solution {
public:
	void dfs(vector<vector<char>> &grid, int cur_i, int cur_j) {
		//递归基:搜索到的点是0，或者达到边界，退回，重新探索其他方向 
		//这个地方一定要先判断边界，否则判断是否为土地会越界grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 'O')
			return ;
		grid[cur_i][cur_j] = '#'; //每个网格只被探索一次

								//往右走，往左走，往下走，往上走
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		int ans = 1;
		//遍历当前土地的四个方向
		for (int index = 0; index != 4; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			 dfs(grid, next_i, next_j);
		}
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		//对边界上的O使用DFS遍历
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O')
				dfs(board, i, 0);
			if (board[i][board[0].size() - 1] == 'O')
				dfs(board, i, board[0].size() - 1);
		}

		for (int j = 1; j < board[0].size() - 1; j++) {
			if (board[0][j] == 'O')
				dfs(board, 0, j);
			if (board[board.size()-1][j] == 'O')
				dfs(board, board.size() - 1, j);
		}
	

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O') 
					board[i][j] = 'X';
				if (board[i][j] == '#')
					board[i][j] = 'O';
			}
		}
	}
};