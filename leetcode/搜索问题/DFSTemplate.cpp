/************************************************************************/
/*@File Name         : DFSTemplate.cpp
/*@Created Date      : 2020/5/21 13:59
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : DFS的模板，DFS分为两种，一种是对二维数组进行遍历的DFS，一种是从边界出发进行DFS，然后对边界可达或不可达的点进行描述。
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

 



//函数调用dfs实现
class Solution_695_dfs {
	int dfs(vector<vector<int>> &grid, int cur_i, int cur_j) {
		//递归基:搜索到的点是0，或者达到边界，退回，重新探索其他方向 
		//这个地方一定要先判断边界，否则判断是否为土地会越界grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
			return 0;
		grid[cur_i][cur_j] = 0; //每个网格只被探索一次

								//往右走，往左走，往下走，往上走
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		int ans = 1;
		//遍历当前土地的四个方向
		for (int index = 0; index != 4; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			ans += dfs(grid, next_i, next_j);
		}
		return ans;
	}

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j)
				ans = std::max(ans, dfs(grid, i, j));
		}
		return ans;
	}
};


//栈实现dfs
class Solution_695_dfs_stack {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j) {
				int cur = 0;
				stack<int>stacki;
				stack<int>stackj;
				stacki.push(i);
				stackj.push(j);
				while (!stacki.empty()) {
					int cur_i = stacki.top(), cur_j = stackj.top();
					stacki.pop();
					stackj.pop();
					if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
					continue;  //不在执行下面的代码
					cur += 1;
					grid[cur_i][cur_j] = 0;
					int di[4] = { 0, 0, 1,-1 };
					int dj[4] = { 1, -1, 0, 0 };
					for (int index = 0; index != 4; ++index) {
						int next_i = cur_i + di[index], next_j = cur_j + dj[index];
						stacki.push(next_i);
						stackj.push(next_j);
					}
				}
				ans = std::max(cur, ans);
			}
	}
};




 


/************************ (C) COPYRIGHT ccpang *****END OF FILE****/