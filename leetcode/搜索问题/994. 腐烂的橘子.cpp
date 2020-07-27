/************************************************************************/
/*@File Name         : 994. 腐烂的橘子.cpp
/*@Created Date      : 2020/6/28 15:50
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
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
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int orangesRotting(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		queue<pair<int, int>>q1;
		int cnt = 0; //用来统计好橘子
		int round = 0; //用来统计腐烂经过的分钟数
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 2) {
					q1.push(pair<int, int>{i, j});
				}
				else if (grid[i][j] == 1)
					cnt++;
			}
		}
		while (cnt > 0 && !q1.empty()) {
			round++;
			int size = q1.size(); //把腐烂的橘子都拿出来
			for (int i = 0; i < size; i++) {
				int cur_i = q1.front().first;
				int cur_j = q1.front().second;
				q1.pop();

				for (int index = 0; index < 4; index++) {
					int next_i = cur_i + dx[index];
					int next_j = cur_j + dy[index];
					if (next_i >= 0 && next_i < grid.size() && next_j >= 0 && next_j < grid[0].size() && grid[next_i][next_j] == 1) {
						q1.push(pair<int, int>{next_i, next_j});
						grid[next_i][next_j] = 2;
						cnt--; //减少好橘子的数量
					}
				}
			}
		}
		if (cnt > 0)
			return -1;
		else
			return round;
	}
};