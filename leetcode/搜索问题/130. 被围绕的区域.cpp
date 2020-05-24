/************************************************************************/
/*@File Name         : 130. ��Χ�Ƶ�����.cpp
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
/*@ Problem Name         : 130. ��Χ�Ƶ�����
/*@ Description 		 :����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����
�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ���
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵�����㷨˼·���Ա߽��ϵ�O��ʹ��DFS�㷨���б�������O����O�����ĵ��Ϊ��#����Ȼ���ٱ����������죬
��'#'��Ϊ'O',��'O'��Ϊ'X'.
/************************************************************************/

class Solution {
public:
	void dfs(vector<vector<char>> &grid, int cur_i, int cur_j) {
		//�ݹ��:�������ĵ���0�����ߴﵽ�߽磬�˻أ�����̽���������� 
		//����ط�һ��Ҫ���жϱ߽磬�����ж��Ƿ�Ϊ���ػ�Խ��grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 'O')
			return ;
		grid[cur_i][cur_j] = '#'; //ÿ������ֻ��̽��һ��

								//�����ߣ������ߣ������ߣ�������
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		int ans = 1;
		//������ǰ���ص��ĸ�����
		for (int index = 0; index != 4; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			 dfs(grid, next_i, next_j);
		}
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		//�Ա߽��ϵ�Oʹ��DFS����
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