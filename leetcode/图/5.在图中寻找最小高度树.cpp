/************************************************************************/
/*@File Name         : 5.在图中寻找最小高度树.cpp
/*@Created Date      : 2020/6/16 10:23
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
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		//特殊情况判定
		vector<int>result;
		if (n == 1) 
		{
			result.push_back(0);
			return result;
		}
		//每个节点的度
		vector<int>degree(n);
		vector<vector<int>>vec(n);
		for (int i = 0; i < edges.size(); i++) {
			degree[edges[i][0]]++;		//增加节点的度
			degree[edges[i][1]]++;		//增加节点的度
			vec[edges[i][0]].push_back(edges[i][1]);
			vec[edges[i][1]].push_back(edges[i][0]);	//增加了平行边 其实无向图 也无所谓平行边了
		}

		return bfs(vec, degree, n);

	}
	vector<int>bfs(vector<vector<int>>& vec, vector<int>&degree, int n) {
		queue<int>q1;
		//先将入度为1的所有节点入队
		for (int i = 0; i < degree.size(); i++) {
			if (degree[i] == 1)
				q1.push(i);
		}

		int cnt = q1.size();
		while (n > 2) {
			n -= cnt;
			while (cnt--) {
				int temp = q1.front();
				q1.pop();
				degree[temp] = 0;
				for (int i = 0; i < vec[temp].size(); i++) {
					if (degree[vec[temp][i]] != 0) {
						degree[vec[temp][i]]--;
						if (degree[vec[temp][i]] == 1) {
							q1.push(vec[temp][i]);
						}
					}
				}
			}
			cnt = q1.size();
		}
		vector<int>result;
		while (!q1.empty()) {
			result.push_back(q1.front());
			q1.pop();
		}
		return result;
	}
}; 