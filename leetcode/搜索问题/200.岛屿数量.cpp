/************************************************************************/
/*@File Name         : 200.岛屿数量.cpp
/*@Created Date      : 2020/5/21 15:38
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
/*@ Problem Name         : 200.岛屿数量
/*@ Description 		 :给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。


*************************************************************************
/*@ Example1-Input	 	 :
11110
11010
11000
00000
/*@ Example1-Output		 : 1
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：
/************************************************************************/
 



class Solution {
public:
	void dfs(vector<vector<char>> &grid, int cur_i, int cur_j) {
		//递归基:搜索到的点是0，或者达到边界，退回，重新探索其他方向 
		//这个地方一定要先判断边界，否则判断是否为土地会越界grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != '1')
			return ;
		grid[cur_i][cur_j] = 0; //每个网格只被探索一次

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

	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					result++;
				}
			}
		}
		return result;
	}
};


/**
int main() {

	int m, n; 
	char a;			//用于读取换行符
	while (2 == scanf("%d %d\n", &m, &n)) {
		vector<vector<char>>grid(m, vector<char>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == n)
					scanf("%c", &a);			//读取换行符
				else
					scanf("%c", &grid[i][j]);
			}
		}

		//在这里执行Solution算法
		cout << Solution().numIslands(grid) << endl;
	}

	system("pause");
	return 0;
}
*/