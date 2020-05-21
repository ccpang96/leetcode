/************************************************************************/
/*@File Name         : BFSTemplate.cpp
/*@Created Date      : 2020/5/21 14:03
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : BFS的模板
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

 


//用队列实现bfs(先以土地为中心，将周边的土地都访问一圈)
class Solution_695_bfs {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j) {
				queue<int>queuei;
				queue<int>queuej;
				queuei.push(i);
				queuej.push(j);
				int cur = 0;
				while (!queuei.empty()) {
					int cur_i = queuei.front(), cur_j = queuej.front();
					queuei.pop();
					queuej.pop();

					if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
						continue;

					cur += 1;
					grid[cur_i][cur_j] = 0;
					int di[4] = { 0,0,1,-1 };
					int dj[4] = { 1,-1,0,0 };
					for (int index = 0; index != 4; ++index) {
						int next_i = cur_i + di[index], next_j = cur_j + dj[index];
						queuei.push(next_i);
						queuej.push(next_j);
					}
				}

				ans = std::max(ans, cur);
			}
		return ans;
	}
};
